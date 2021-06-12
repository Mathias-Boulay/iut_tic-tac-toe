#include <iostream>
#include <experimental/random>

#include "Game.h"
#include "types.h"
#include "GameUtils.h"
#include "AiUtils.h"
#include "DisplayUtils.h"
#include "InputUtils.h"


using namespace std;

void TrainAI(unsigned nbGame /*= 1000000*/){
    unsigned index = 0;
    AI AIToTrain;
    AI controlledAI;
    vector<string> turnOrder;
    GameMap gameMap;
    unsigned turnIndex = 0;

    AIToTrain._Token = Player1Token;
    controlledAI._Token = Player2Token;

    AIToTrain._Data = GetTrainingData("InstanceOne.txt");
    controlledAI._Data = GetTrainingData("InstanceTwo.txt");

    if(experimental::randint(0,1) == 0){
        turnOrder.push_back("AIToTrain");
        turnOrder.push_back("controlledAI");
    }else{
        turnOrder.push_back("controlledAI");
        turnOrder.push_back("AIToTrain");
    }

    while (index <= nbGame){
        gameMap = InitGameMap();

        while (true) {
            if(turnOrder[turnIndex] == "AIToTrain"){
                PlayAITurn(gameMap,AIToTrain);

                if(HasSomeoneWon(gameMap)){
                    TurnHistoryDataIntoTrainingData(AIToTrain, true);
                    TurnHistoryDataIntoTrainingData(controlledAI, false);
                    turnOrder[0] = "controlledAI";
                    turnOrder[1] = "AIToTrain";
                    turnIndex = 0;
                    break;
                }

                if(IsGameMapFull(gameMap)) break;

                turnIndex = turnIndex < turnOrder.size()-1 ? turnIndex+1 : 0;

            }else if(turnOrder[turnIndex] == "controlledAI"){

                if(!TryToFill(gameMap, controlledAI, AIToTrain._Token)){
                    if(!TryToFill(gameMap, controlledAI, controlledAI._Token)){
                        PlayAITurn(gameMap, controlledAI);
                    }
                }

                if(HasSomeoneWon(gameMap)){
                    TurnHistoryDataIntoTrainingData(AIToTrain, false);
                    TurnHistoryDataIntoTrainingData(controlledAI, true);
                    turnOrder[0] = "AIToTrain";
                    turnOrder[1] = "controlledAI";
                    turnIndex = 0;
                    break;
                }

                if(IsGameMapFull(gameMap)) break;

                turnIndex = turnIndex < turnOrder.size()-1 ? turnIndex+1 : 0;
            }
            DisplayGameMap(gameMap);
            //Display some additionnal info
            cout << "Game " << index << '/' << nbGame;
        }

    index+=1;
    }

    SaveTrainingData(AIToTrain._Data,"InstanceOne.txt");
    SaveTrainingData(controlledAI._Data,"InstanceTwo.txt");
}

void PlayAgainstAI(){
    while (true) {
        AI AiInstance;
        AiInstance._Token = Player1Token;
        AiInstance._Data = GetTrainingData("InstanceOne.txt");

        GameMap GameMap = InitGameMap();
        DisplayGameMap(GameMap);


        while(true) {
            char input = ReadSpecificKeyboardInput({'1','2','3','4','5','6','7','8','9'});
            GameMap[input-'1'] = Player2Token;

            if(HasSomeoneWon(GameMap)){
                TurnHistoryDataIntoTrainingData(AiInstance, false);
                SaveTrainingData(AiInstance._Data, "file.txt");
                DisplayGameMap(GameMap);
                break;
            }
            PlayAITurn(GameMap, AiInstance);
            DisplayGameMap(GameMap);

            if(HasSomeoneWon(GameMap)){
                TurnHistoryDataIntoTrainingData(AiInstance, true);
                SaveTrainingData(AiInstance._Data, "file.txt");
                break;
            }
        }
    }
}
