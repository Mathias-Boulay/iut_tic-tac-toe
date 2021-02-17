#include "types.h"
#include "AiUtils.h"
#include "GameUtils.h"
#include <experimental/random>
#include <fstream>
#include <iostream>

using namespace std;

bool PlayAITurn(GameMap & Map, AI & AiInstance, int ForcedIndex){
    //Get the map state and decide where to play
    MapState mapState = Map;
    unsigned bestCell = ForcedIndex == -1 ? SelectBestCell(mapState, AiInstance._Data) : ForcedIndex;

    //Place the token
    bool hasPlaced = PutToken(Map, AiInstance._Token, bestCell);

    //Add this to the turn history
    AiInstance._History.push_back(make_pair(mapState, bestCell));

    return hasPlaced;
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
        SetMapStateData(AiInstance._Data,turn.first, mapStateData);
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

void SaveTrainingData(TrainingData & Data, const string Path){
    ofstream ofs;
    ofs.open(Path, ios_base::out | ios_base::trunc);

    //if(!ofs.is_open()) return;

    for(TrainingData::iterator it(Data.begin()); it != Data.end(); ++it){
        //Parsing map state
        for(char token : it->first){
            if(token == ' ') token = '_';
            ofs << token;
        }

        ofs << " :";
        //Parse turn score
        for(int score : it->second){
            ofs << " " << score;
        }
        ofs << endl;
    }
    ofs.close();
}

TrainingData GetTrainingData(const std::string Path){
    TrainingData Data;
    ifstream ifs;
    string Key;
    string Value;

    ifs.open(Path);
    if(!ifs.is_open()) return Data;

    while (ifs >> Key){
        MapState MapState;
        MapStateData MapStateData;

        for(char & Char : Key){
            MapState.push_back(Char == '_' ? ' ' : Char);
        }

        ifs >> Value; //Throwaway the :
        for(unsigned i(0); i<9; ++i){
            ifs >> Value;
            MapStateData.push_back(stoi(Value));
        }

        Data[MapState] = MapStateData;
    }
    return Data;
}

bool TryToFill(GameMap & Map, AI & AiInstance, char & TokenToCheck){
    unsigned index;
    for(unsigned i(0); i<3; ++i){
        //Check horizontal filling
        index = (i*2)+i;

        if(Map[index] == TokenToCheck && Map[index] == Map[index+1] && Map[index+2] == ' '){
            return PlayAITurn(Map, AiInstance, index+2);
        }

        if(Map[index] == TokenToCheck && Map[index] == Map[index+2] && Map[index+1] == ' '){
            return PlayAITurn(Map, AiInstance, index+1);
        }

        if(Map[index+1] == TokenToCheck && Map[index+1] == Map[index+2] && Map[index] == ' '){
            return PlayAITurn(Map, AiInstance, index);
        }


        //Check horizontal filling
        index = i;

        if(Map[index] == TokenToCheck && Map[index] == Map[index+3] && Map[index+6] == ' '){
            return PlayAITurn(Map, AiInstance, index+6);
        }

        if(Map[index] == TokenToCheck && Map[index] == Map[index+6] && Map[index+3] == ' '){
            return PlayAITurn(Map, AiInstance, index+3);
        }

        if(Map[index+3] == TokenToCheck && Map[index+3] == Map[index+6] && Map[index] == ' '){
            return PlayAITurn(Map, AiInstance, index);
        }
    }

    //Check diagonals
    if(Map[0] == TokenToCheck && Map[0] == Map[4] && Map[8] == ' '){
        return PlayAITurn(Map, AiInstance, 8);
    }

    if(Map[0] == TokenToCheck && Map[0] == Map[8] && Map[4] == ' '){
        return PlayAITurn(Map, AiInstance, 4);
    }

    if(Map[4] == TokenToCheck && Map[4] == Map[8] && Map[0] == ' '){
        return PlayAITurn(Map, AiInstance, 0);
    }

    //diagonal 2
    if(Map[2] == TokenToCheck && Map[2] == Map[4] && Map[6] == ' '){
        return PlayAITurn(Map, AiInstance, 6);
    }

    if(Map[2] == TokenToCheck && Map[2] == Map[6] && Map[4] == ' '){
        return PlayAITurn(Map, AiInstance, 4);
    }

    if(Map[4] == TokenToCheck && Map[4] == Map[6] && Map[2] == ' '){
        return PlayAITurn(Map, AiInstance, 2);
    }

    return false;
}

