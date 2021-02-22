#include <iostream>
#include "MenuUtils.h"
#include "types.h"
#include "InputUtils.h"
#include "Game.h"
#include "DisplayUtils.h"

using namespace std;

void MainMenu(){
    char input;
    while (true) {
        DisplayHeader();
        cout << "[1] Train the AI" << endl
             << "[2] Play with the trained AI" << endl
             << "[3] Quit the game" << endl;

        input = ReadSpecificKeyboardInput({'1','2','3'});

        switch (input) {
        case '1':
            AITrainingMenu();
            break;

        case '2':
            ClearDisplay();
            PlayAgainstAI();
            break;

        case '3':
            return;
            break;
        }
    }
}

void AITrainingMenu(){
    char input;
    while (true) {
        DisplayHeader();
        cout << "[1] Create a data set" << endl
             << "[2] Re-use the data set" << endl
             << "[3] Go back" << endl;


        input = ReadSpecificKeyboardInput({'1','2','3'});

        switch (input) {

        case '1':
            //Remove the old data sets
            remove("InstanceOne.txt");
            remove("InstanceTwo.txt");
            TrainAI();
            break;

        case '2':
            TrainAI();
            break;

        case '3':
            return;
            break;
        }

    }
}

void DisplayHeader(){
    ClearDisplay();
    cout << " _____ _           _____               _____" << endl
         << "|_   _(_)         |_   _|             |_   _|" << endl
         << "  | |  _  ___ ______| | __ _  ___ ______| |" << endl
         << "  | | | |/ __|______| |/ _` |/ __|______| |/ _ \\ / _ \\" << endl
         << "  | | | | (__       | | (_| | (__       | | (_) |  __/" << endl
         << "  \\_/ |_|\\___|      \\_/\\__,_|\\___|      \\_/\\___/ \\___|" << endl
         << endl
         << endl;
}










