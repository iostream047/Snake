#ifndef GAMEVISUALIZER_H
#define GAMEVISUALIZER_H

#include <array>
#include <string>
#include <sstream>

#include "GameConstants.h"
#include "GameData.h"

class GameVisualizer{
    public:
    GameVisualizer(const GameData& data);

    
    const char* getClearCommand() const;
    std::stringstream& visualizeGameBoard();
    
    private:
    std::stringstream ss;
    std::string clear_command;
    const GameData& data_view;
};

#endif