#ifndef GAME_H
#define GAME_H


/*!
 * \file Game.h
 * \brief Here lies functions related to different game modes
 * \author BOULAY Mathias
 * \version 1.0
 * \date 15 janvier 2021
 */

/**
 * @brief Train the AI on a set number of games
 * @param[in] nbGame How many games the AI should train on
 * @fn void TrainAI(const unsigned nbGame = 1000000);
 * @return void
 */
void TrainAI(const unsigned nbGame = 1000000);

/**
 * @brief Play against the AI
 * @fn void PlayAgainstAI();
 * @return void
 */
void PlayAgainstAI();


#endif // GAME_H
