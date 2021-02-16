#ifndef GAMEUTILS_H
#define GAMEUTILS_H

#include "types.h"

bool hasSomeoneWon(const GameMap & Map);

bool putToken(GameMap & Map, const char Token, const unsigned index);

#endif // GAMEUTILS_H
