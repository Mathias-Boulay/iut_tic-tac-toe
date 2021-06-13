#ifndef AIUTILS_H
#define AIUTILS_H

#include "types.h"
#include <string>

/*!
 * \file AIUtils.h
 * \brief Un set of functions used by the AI
 * \author BOULAY Mathias
 * \version 1.0
 * \date 15 janvier 2021
 */

/**
 * @brief Make an AI play on the provided GameMap, return true if the AI played.
 * @param[in, out] Map The Gamemap to play on
 * @param[in, out] AiInstance The AI to play with
 * @param[in] ForcedIndex An index to play on instead of the one computed by the AI
 * @fn bool PlayAITurn(GameMap & Map, AI & AiInstance, int ForcedIndex = -1);
 * @return bool
 */
bool PlayAITurn(GameMap & Map, AI & AiInstance, int ForcedIndex = -1);

/**
 * @brief Compute which cell to play on according to the data of the AI
 * @param[in] MapState The state of the map to analyze
 * @param[in] Data The data of the AI
 * @fn unsigned SelectBestCell(const MapState & MapState, const TrainingData Data);
 * @return unsigned
 */
unsigned SelectBestCell(const MapState & MapState, const TrainingData Data);

/**
 * @brief Compute which cell to play on according to the data of the AI
 * @param[in] AiInstance The AI to get the data from
 * @param[in] hasAIWon Tell if the AI won.
 * @fn void TurnHistoryDataIntoTrainingData(AI & AiInstance, bool hasAIWon);
 * @return void
 */
void TurnHistoryDataIntoTrainingData(AI & AiInstance, bool hasAIWon);

/**
 * @brief Get the MapStateData associated to a MapState
 * @param[in] Data The training data to look into
 * @param[in] MapState The MapState to use to look into the Data
 * @fn MapStateData GetMapStateData(const TrainingData & Data, const MapState & MapState);
 * @return MapStateData
 */
MapStateData GetMapStateData(const TrainingData & Data, const MapState & MapState);

/**
 * @brief Set the MapStateData associated to a MapState
 * @param[in, out] Data The training data to write into
 * @param[in] MapState The MapState to use to look into the Data
 * @param[in] MapStateData The data to write
 * @fn void SetMapStateData(TrainingData & Data, const MapState & MapState, const MapStateData & MapStateData);
 * @return void
 */
void SetMapStateData(TrainingData & Data, const MapState & MapState, const MapStateData & MapStateData);

/**
 * @brief Save the training data into the specified file name
 * @param[in] Data The training data to save
 * @param[in] Path The file path
 * @fn void SaveTrainingData(const TrainingData & Data, std::string Path);
 * @return void
 */
void SaveTrainingData(const TrainingData & Data, const std::string Path);

/**
 * @brief Get the training data from a file
 * @param[in] Path The file path
 * @fn TrainingData GetTrainingData(const std::string Path);
 * @return TrainingData
 */
TrainingData GetTrainingData(const std::string Path);

/**
 * @brief Try to fill a cell between two cells of the same token
 * @param[in,out] Map That GameMap to  play on
 * @param[in,out] AiInstance the AI that plays
 * @param[in] TokenToCheck The token to look for.
 * @fn bool TryToFill(GameMap & Map, AI & AiInstance, const char & TokenToCheck);
 * @return bool
 */
bool TryToFill(GameMap & Map, AI & AiInstance, const char & TokenToCheck);

#endif // AIUTILS_H
