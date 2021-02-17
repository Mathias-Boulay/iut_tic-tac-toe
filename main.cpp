#include <iostream>
#include "InputUtils.h"
#include "AiUtils.h"
#include "DisplayUtils.h"
#include "GameUtils.h"

using namespace std;

int main()
{
    //TrainingData Data = GetTrainingData("file.txt");
    srand(time(NULL));


    AI AiInstance;
    AiInstance._Token = Player2Token;
    AiInstance._Data = GetTrainingData("file.txt");

    GameMap GameMap;
    for(unsigned i(0); i <9; ++i){
        GameMap.push_back(' ');
    }

    while(true){
        char input = ReadSpecificKeyboardInput({'1','2','3','4','5','6','7','8','9'});
        GameMap[input-'1'] = Player1Token;

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
    cout << "Hello World!" << endl;
    return 0;
}
