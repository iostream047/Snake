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
        
        //snake:
        assert (SNAKE_INITIAL_LENGTH < BOARD_ROWS/2);
        data.getSnake().buildSnake(SNAKE_INITIAL_LENGTH,BOARD_ROWS,BOARD_COLS);
        //use Snake::push_back(glm::vec2 pos)
        //put the snake on the board:
        for(glm::vec2 node : data.getSnake().viewSnakeBody()){
            data.getBoard()
                [static_cast<int>(node.x)] [static_cast<int>(node.y)]
                .changeState(CellState::SNAKE);
        }

        //no walls yet

        //food:
        for(int i=0; i<MAX_FOOD_COUNT; i++){
            data.getFoodList()[i].setNutritionValue(1).setPosition(generateValidRandomPos());
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