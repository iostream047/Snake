#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <random>
#include "GameData.h"
#include "GameVisualizer.h"

class GameManager{
    public:
    GameManager();
    void refillFood(Food f);
    //HOW to EMPTY the last cell of the snake?
    

    private:
    GameData data;
    GameVisualizer viz;
    
    //random tools:
    std::mt19937 twister;
    std::uniform_int_distribution<> row_dist;
    std::uniform_int_distribution<> col_dist;

    glm::vec2 generateValidRandomPos() ;
};

#endif