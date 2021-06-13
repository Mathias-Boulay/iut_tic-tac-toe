#include "DisplayUtils.h"
#include <iostream>

using namespace std;

void ClearDisplay(){
    cout << "\033[H\033[2J";
}

void DisplayGameMap(const GameMap & Map){
    ClearDisplay();
    string mapModel = R"LIMIT(
╔═══╦═══╦═══╗
║ 6 ║ 7 ║ 8 ║
╠═══╬═══╬═══╣
║ 3 ║ 4 ║ 5 ║
╠═══╬═══╬═══╣
║ 0 ║ 1 ║ 2 ║
╚═══╩═══╩═══╝
)LIMIT";
    for(int i(0), index(0); i<9; ++i){
        index = mapModel.find(to_string(i));
        mapModel.replace(index, 1, 1, Map[i]);
    }
    cout << mapModel;
}
