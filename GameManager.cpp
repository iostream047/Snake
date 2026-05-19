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

        //generate food and draw on board:
        for(int i=0; i<MAX_FOOD_COUNT; i++){
            glm::vec2 random_pos = generateValidRandomPos();
            data.getFoodAry()[i].setNutrition(1).setPosition(random_pos);
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
bool GameManager::gameTick(){
    
    // constexpr int target_fps = TARGET_FRAME_RATE;
    // constexpr std::chrono::nanoseconds target_frame_duration = 
    //     std::chrono::nanoseconds{1'000'000'000/target_fps};
    glm::vec2 prev_head_pos = data.getSnake().getHeadPos();
    glm::vec2 prev_tail_pos = data.getSnake().moveOnce(); //board doesn't know



    //handle new head out of board:


    //check if food is eaten:



    //regenerate food, and draw on board


    //implement...
    return false;
}

const GameData& GameManager::viewGameData(){
    return data;
}

Food& GameManager::repositionFood(glm::vec2 food_pos){
    bool found = false;
    int food_idx = 0;
    auto food_ary = data.getFoodAry();
    for(std::size_t i=0; i<food_ary.size(); i++ ){
        if(food_ary[i].getPos() == food_pos){
            found = true;
            food_ary[i].setPosition(generateValidRandomPos());
            food_idx = i;
        }
    }
    if(!found){
        throw std::invalid_argument("Food position provided does not exist");
    }
    return food_ary[food_idx];
}
void GameManager::drawFood(const Food& f){
    BoardCell& target_cell = data.getBoard()[f.getPos().x][f.getPos().y];
    assert(target_cell.getCellState() == CellState::EMPTY);
    target_cell.changeState(CellState::FOOD_1);
}

    void GameManager::flipFoodChar(const Food& f){
        BoardCell& target_cell = data.getBoard()[f.getPos().x][f.getPos().y];
        switch (target_cell.getCellState())
        {
        case CellState::FOOD_1:
            target_cell.changeState(CellState::FOOD_2);
            break;
        case CellState::FOOD_2:
            target_cell.changeState(CellState::FOOD_2);
            break;
        default:
            throw std::invalid_argument("expected food position is not food represnetation");  
            break;
        }
    }