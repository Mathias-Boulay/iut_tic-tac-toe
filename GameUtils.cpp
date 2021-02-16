#include "GameUtils.h"

bool hasSomeoneWon(const GameMap & Map){
    for(unsigned i(0); i<3; ++i){
        //Check horizontal alignement
        if(Map[(i*2) + i] == Map[(i*2) + i+1] && Map[(i*2) + i] == Map[(i*2) + i+2] && Map[(i*2) + i] != ' '){
            return true;
        }

        //Check vertical alignement
        if(Map[i] == Map[i+3] && Map[i] == Map[i+6] && Map[i] != ' '){
            return true;
        }
    }

    //Check diagonals
    if(((Map[0] == Map[4] && Map[0] == Map[8]) &&(Map[2] == Map[4] && Map[2] == Map[6])) && (Map[4] != ' ')){
        return true;
    }

    return false;
}

bool putToken(GameMap & Map, const char Token, const unsigned index){
    if(index > 9) return false;
    if(Map[index] != ' ') return false;

    Map[index] = Token;
    return true;
}


