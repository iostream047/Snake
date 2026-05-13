#ifndef GAMEVISUALIZER_H
#define GAMEVISUALIZER_H

#include <array>
#include "GameConstants.h"
#include "GameData.h"

class GameVisualizer{
    public:

    GameVisualizer(const GameData& data);
    void printGameBoard();
    
    private:
    const GameData& data_view;
};

#endif