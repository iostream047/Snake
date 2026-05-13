#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <unordered_set>
// #include "pos.h"

class GameObject{
    private:
    char symbol;
    // std::unordered_set<pos,pos_hash_functor> pos_array; //why neded again??
    //DO NOT USE: sounds like a nightmare, use an array for the gameboard...

    public:
    game_object(char c);
     
    
    
};

#endif
