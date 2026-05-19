#include "GameData.h"

GameData::GameData():
    score(0){
        //default construct all members
    }

std::array<std::array<BoardCell,BOARD_COLS>,BOARD_ROWS>& GameData::getBoard() {
    return game_board; //return type ensures by reference
}
const std::array<std::array<BoardCell,BOARD_COLS>,BOARD_ROWS>& GameData::viewBoard() const{
    return game_board; //return type ensures by reference
}
std::array<Food,MAX_FOOD_COUNT>& GameData::getFoodAry() {
    return food_arry;
}
Snake& GameData::getSnake(){
    return snake;
}
int GameData::getScore()const{
    return score;
}
