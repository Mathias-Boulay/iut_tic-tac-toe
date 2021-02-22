#ifndef TYPES_H
#define TYPES_H

#include <vector>
#include <string>
#include <map>

#define EMPTY_CELL ' '

typedef char Cell;
typedef std::vector<char> MapState;
typedef std::vector<int> MapStateData;

//Note that the GameMap size should always be 9.
typedef std::vector<char> GameMap;

typedef std::map<MapState, MapStateData> TrainingData;

typedef std::vector<std::pair<MapState, unsigned>> TurnHistory;

const char Player1Token = 'X';

const char Player2Token = 'O';


struct AI{
    TrainingData _Data;
    TurnHistory _History;
    char _Token;
};

#endif // TYPES_H
