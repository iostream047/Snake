#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <array>
#include <optional>
#include "BoardCell.h"
#include "Snake.h"
#include "Food.h"
#include "GameConstants.h"

class GameData{
    public:
    GameData();
    std::array<std::array<BoardCell,BOARD_COLS>,BOARD_ROWS>& getBoard(); //will mutate board
    const std::array<std::array<BoardCell,BOARD_COLS>,BOARD_ROWS>& viewBoard()const; //will mutate board
    
    std::array<Food,MAX_FOOD_COUNT>& getFoodList();
    Snake& getSnake(); //want to be able to mutate through methods
    int getScore() const;

    private:
    std::array<std::array<BoardCell,BOARD_COLS>,BOARD_ROWS> game_board;//allocate and initialize default here.
    std::array<Food,MAX_FOOD_COUNT> food_arry; //GameManager sets uasable values.
    Snake snake;//allocate using compile time values, GameManager adds uasble values.
    int score;
};

#endif