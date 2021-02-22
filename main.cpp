#include <iostream>
#include "InputUtils.h"
#include "AiUtils.h"
#include "DisplayUtils.h"
#include "GameUtils.h"
#include "Game.h"

using namespace std;

int main()
{
    //TrainingData Data = GetTrainingData("file.txt");
    srand(time(NULL));
    TrainAI();

    /*
    AI AiInstance;
    AiInstance._Token = Player1Token;
    AiInstance._Data = GetTrainingData("InstanceOne.txt");

    GameMap GameMap;
    for(unsigned i(0); i <9; ++i){
        GameMap.push_back(EMPTY_CELL);
    }

    while(true) {
        char input = ReadSpecificKeyboardInput({'1','2','3','4','5','6','7','8','9'});
        GameMap[input-'1'] = Player2Token;

        if(HasSomeoneWon(GameMap)){
            TurnHistoryDataIntoTrainingData(AiInstance, false);
            SaveTrainingData(AiInstance._Data, "file.txt");
            break;
        }

        PlayAITurn(GameMap, AiInstance);

        if(HasSomeoneWon(GameMap)){
            TurnHistoryDataIntoTrainingData(AiInstance, true);
            SaveTrainingData(AiInstance._Data, "file.txt");
            break;
        }

        DisplayGame(GameMap);

    }
*/
    cout << "Hello World!" << endl;
    return 0;
}
