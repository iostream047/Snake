#include "GameManager.h"

#include <assert.h>

GameManager::GameManager():
    data(),
    viz(data),
    twister{std::random_device{}()},
    row_dist{0,BOARD_ROWS-1},
    col_dist{0,BOARD_COLS-1}
    {
        //introduce all componets to the game_board here:
        
        //Build snake:
        assert (SNAKE_INITIAL_LENGTH < BOARD_ROWS/2);
        for(int i=0;i<SNAKE_INITIAL_LENGTH;i++){
            data.getSnake().pushBack(glm::vec2(BOARD_ROWS/2,BOARD_COLS/2+i));
        }

        //Draw the snake on the board:
        SnakeIterator s_it = data.getSnake().getIterator();
        while( !s_it.empty() ){
            glm::vec2 pos = s_it.next();
            data.getBoard()
                [static_cast<int>(pos.x)] [static_cast<int>(pos.y)]
                .changeState(CellState::SNAKE);
        }

        //no walls yet

        //food:
        for(int i=0; i<MAX_FOOD_COUNT; i++){
            glm::vec2 random_pos = generateValidRandomPos();
            data.getFoodList()[i].setNutrition(1).setPosition(random_pos);
            data.getBoard()
                [static_cast<int>(random_pos.x)] [static_cast<int>(random_pos.y)]
                .changeState(CellState::FOOD_1);
            // data.getFoodList()[i].setNutrition(1).setPosition(glm::vec2(BOARD_ROWS/4,BOARD_COLS/4+i));
        }
        
}

glm::vec2 GameManager::generateValidRandomPos(){
    int x_pos;
    int y_pos;
    do{
        x_pos = row_dist(twister);
        y_pos = col_dist(twister);
    }while(data.getBoard()[x_pos][y_pos].getCellState() != CellState::EMPTY);    
    
    return glm::vec2(x_pos,y_pos);
}
bool GameManager::gameLogic(){
    //implement...
    return false;
}

const GameData& GameManager::viewGameData(){
    return data;
}