#ifndef TYPES_H
#define TYPES_H

#include <vector>
#include <string>
#include <unordered_map>

#define EMPTY_CELL ' '

typedef char Cell;
typedef std::string MapState;
typedef std::string MapStateData;

//Note that the GameMap size should always be 9.
typedef std::string GameMap;

typedef std::unordered_map<MapState, MapStateData> TrainingData;

typedef std::vector<std::pair<MapState, unsigned>> TurnHistory;

const char Player1Token = 'X';

const char Player2Token = 'O';


struct AI{
    TrainingData _Data;
    TurnHistory _History;
    char _Token;
};

#endif // TYPES_H
