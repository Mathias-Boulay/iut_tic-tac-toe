#ifndef GAMEUTILS_H
#define GAMEUTILS_H

#include "types.h"

bool HasSomeoneWon(const GameMap & Map);

bool IsGameMapFull(const GameMap & Map);

bool PutToken(GameMap & Map, const char Token, const unsigned index);

GameMap InitGameMap();


#endif // GAMEUTILS_H
