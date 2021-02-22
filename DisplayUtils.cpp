#include "DisplayUtils.h"
#include <iostream>

using namespace std;

void ClearDisplay(){
    cout << "\033[H\033[2J";
}

void DisplayGameMap(GameMap & Map){
    ClearDisplay();
    //Display in a way to match the number pad.
    for(int i(2); i>-1; --i){
        for(unsigned j(0); j<3; ++j){
            cout << string({Map[(i*3)+j],EMPTY_CELL});
        }
        cout << endl;
    }
}
