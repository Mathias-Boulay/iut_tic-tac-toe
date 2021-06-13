#ifndef GAMEUTILS_H
#define GAMEUTILS_H

#include "types.h"

/*!
 * \file GameUtils.h
 * \brief A set of functions to deal with game mechanics
 * \author BOULAY Mathias
 * \version 1.0
 * \date 15 janvier 2021
 */



/**
 * @brief Tells if someone won.
 * @param[in] Map The GameMap to Check on
 * @fn bool HasSomeoneWon(const GameMap & Map);
 * @return bool
 */
bool HasSomeoneWon(const GameMap & Map);


/**
 * @brief Tell if the map is full.
 * @param[in] Map The GameMap to Check on
 * @fn bool HasSomeoneWon(const GameMap & Map);
 * @return bool
 */
bool IsGameMapFull(const GameMap & Map);


/**
 * @brief Put a token "X,O..." on the GameMap.
 * @param[in, out] Map The GameMap to put the token on
 * @param[in] Token The token to put
 * @param[in] index The index to put the token at.
 * @fn PutToken(GameMap & Map, const char Token, const unsigned index);
 * @return bool
 */
bool PutToken(GameMap & Map, const char Token, const unsigned index);

/**
 * @brief Return an empty GameMap
 * @fn GameMap InitGameMap();
 * @return GameMap
 */
GameMap InitGameMap();


#endif // GAMEUTILS_H
