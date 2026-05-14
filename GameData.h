#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <array>
#include <vector>
#include "GameConstants.h"
#include "BoardCell.h"
#include "Snake.h"
#include "Food.h"

class GameData{
    public:
    GameData();
    std::array<std::array<BoardCell,BOARD_COLS>,BOARD_ROWS>& getBoard(); //will mutate board
    const std::array<std::array<BoardCell,BOARD_COLS>,BOARD_ROWS>& viewBoard()const; //will mutate board
    
    std::array<Food,MAX_FOOD_COUNT>& getFoodList(); //will directly and delete into the vector
    Snake& getSnake(); //want to be able to mutate through methods
    int getScore() const;

    private:
    std::array<std::array<BoardCell,BOARD_COLS>,BOARD_ROWS> game_board;//allocate memory when constructing
    std::vector<Food> food_arry; //GameManager initializes this...
    Snake snake;//declare now, allocate in initialiser list
    int score;
};

#endif