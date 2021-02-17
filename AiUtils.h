#ifndef AIUTILS_H
#define AIUTILS_H

#include "types.h"
#include <string>



bool PlayAITurn(GameMap & Map, AI & AiInstance, int ForcedIndex = -1);

unsigned SelectBestCell(MapState & MapState, TrainingData Data);

void TurnHistoryDataIntoTrainingData(AI & AiInstance, bool hasAIWon);

MapStateData GetMapStateData(const TrainingData & Data, const MapState & MapState);

void SetMapStateData(TrainingData & Data, const MapState & MapState, const MapStateData & MapStateData);

void SaveTrainingData(TrainingData & Data, std::string Path);

TrainingData GetTrainingData(const std::string Path);

bool TryToFill(GameMap & Map, AI & AiInstance, char & TokenToCheck);

#endif // AIUTILS_H
