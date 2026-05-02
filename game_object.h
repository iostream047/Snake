#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <unordered_set>
#include "pos.h"

class game_object{
    private:
    char symbol;
    std::unordered_set<pos,pos_hash_functor> pos_array;

    public:
    game_object(char c);
     
    
    
};

#endif
