#include "types.h"
#include "AiUtils.h"
#include <experimental/random>

using namespace std;

void PlayTurn(GameMap & Map, AI & AiInstance){
    //Get the map state and decide where to play
    MapState mapState = Map;
    unsigned bestCell = SelectBestCell(mapState, AiInstance._Data);

    //Place the token
    Map[bestCell] = AiInstance._Token;

    //Add this to the turn history
    AiInstance._History.push_back(make_pair(mapState, bestCell));
}

unsigned SelectBestCell(MapState & MapState, TrainingData Data){
    int score = INT32_MIN;
    unsigned bestCell;

    //Checking the action with the highest score.
    for(unsigned i = 0; i < MapState.size(); ++i){
        if(MapState[i] == ' '){
            int tmpScore = GetMapStateData(Data,MapState)[i];

            if(score < tmpScore){
                score = tmpScore;
                bestCell = i;
                continue;
            }

            if(score == tmpScore){
                bestCell = (experimental::randint(0,1) == 0 ? bestCell : i);
            }
        }
    }

    return bestCell;
}

void TurnHistoryDataIntoTrainingData(AI & AiInstance, bool hasAIWon){
    short modifier = hasAIWon ? 1 : -1;

    for(pair<MapState, unsigned> turn : AiInstance._History){
        //
        MapStateData mapStateData = GetMapStateData(AiInstance._Data, turn.first);
        mapStateData[turn.second] += modifier;
        SetMapStateData(AiInstance._Data,mapStateData);
    }

    AiInstance._History = {};
}

MapStateData GetMapStateData(const TrainingData & Data, const MapState & MapState){
    if(Data.find(MapState) != Data.end()){
        return Data.at(MapState);
    }
    return {0,0,0,0,0,0,0,0,0};  //Default data, with no modifiers
}

void SetMapStateData(TrainingData & Data, const MapState & MapState, const MapStateData & MapStateData){
    Data[MapState] = MapStateData;
}



