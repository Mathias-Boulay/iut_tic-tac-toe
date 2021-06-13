#ifndef TYPES_H
#define TYPES_H

#include <vector>
#include <string>
#include <unordered_map>

/*!
 * \file GameUtils.h
 * \brief A set of types just so you know better what you're dealing with
 * \author BOULAY Mathias
 * \version 1.0
 * \date 15 janvier 2021
 */

#define EMPTY_CELL ' '
/**
 * @brief Cell : alias for a char in a GameMap
 * @typedef char Cell;
 */
typedef char Cell;

/**
 * @brief MapState : alias for a string identical to a GameMap
 * @typedef std::string MapState;
 */
typedef std::string MapState;


/**
 * @brief MapStateData : alias for choice data associated to a MapState
 * @typedef std::string MapStateData;
 */
typedef std::string MapStateData;

/**
 * @brief GameMap : alias for a string of length 9.
 * @typedef std::string GameMap;
 */
typedef std::string GameMap;

/**
 * @brief TrainingData : alias for a map of state of its associated data.
 * @typedef std::unordered_map<MapState, MapStateData> TrainingData;
 */
typedef std::unordered_map<MapState, MapStateData> TrainingData;

/**
 * @brief TurnHistory : alias for a verctor of pairs containing the MapState of the choice made by the AI
 * @typedef std::vector<std::pair<MapState, unsigned>> TurnHistory;
 */
typedef std::vector<std::pair<MapState, unsigned>> TurnHistory;

/**
 * @brief The first player token
 */
const char Player1Token = 'X';

/**
 * @brief The second player token
 */
const char Player2Token = 'O';


struct AI{
    TrainingData _Data;
    TurnHistory _History;
    char _Token;
};

#endif // TYPES_H
