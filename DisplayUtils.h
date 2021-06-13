#ifndef DISPLAYUTILS_H
#define DISPLAYUTILS_H

#include "types.h"

/*!
 * \file DisplayUtils.h
 * \brief A set of functions simplifying work with the terminal
 * \author BOULAY Mathias
 * \version 1.0
 * \date 15 janvier 2021
 */

/**
 * @brief Clear the display
 * @fn void ClearDisplay();
 * @return void
 */
void ClearDisplay();

/**
 * @brief Display the GameMap
 * @param[in] The GameMap to display
 * @fn void DisplayGameMap(const GameMap & Map);
 * @return void
 */
void DisplayGameMap(const GameMap & Map);

#endif // DISPLAYUTILS_H
