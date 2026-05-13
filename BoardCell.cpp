#include "BoardCell.h"

BoardCell::BoardCell():cell_state(CellState::EMPTY),representation('-'){
    //empty cell created by default
}

void BoardCell::changeState(CellState state){
    if(cell_state != state){ // if state change needed
        switch (state)
            {//most common to least common:
            case CellState::FOOD_1:
                representation = 'O';
                break;
            case CellState::FOOD_2:
                representation = '.';
                break;
            case CellState::SNAKE:
                representation = 's';
                break;
            case CellState::EMPTY:
                representation = '-';
                break;
            case CellState::WALL:
                representation = 'X';
                break;    
            default:
                assert(false);
                break;
            }
            cell_state = state;
    }  
}
CellState BoardCell::getCellState() const{
    return cell_state;
}
char BoardCell::getCharRepr() const{
    return representation;
}