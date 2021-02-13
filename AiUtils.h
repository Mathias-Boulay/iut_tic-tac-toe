#ifndef AIUTILS_H
#define AIUTILS_H

#include "types.h"



void PlayTurn(GameMap & Map, AI & AiInstance);

unsigned SelectBestCell(MapState & MapState, TrainingData Data);

void TurnHistoryDataIntoTrainingData(AI & AiInstance, bool hasAIWon);

MapStateData GetMapStateData(const TrainingData & Data, const MapState & MapState);

void SetMapStateData(TrainingData & Data, MapStateData & MapStateData);




#endif // AIUTILS_H
