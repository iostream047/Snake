#ifndef SNAKE_H
#define SNAKE_H

#include "glm/vec2.hpp"
#include "Direction.h"
#include "SnakeIterator.h"
#include "GameConstants.h"

class Snake{
    
    public:
    Snake();
    // ~Snake();
    void pushBack(glm::vec2 pos);

    //getters:
    glm::vec2 getHeadPos() const;
    glm::vec2 getTailPos() const;
    int getSnakeLen() const;
    SnakeIterator getIterator() const;
    

    //movement:
    void changeDirection(Direction d);
    glm::vec2 moveOnce(); //return prev_tail
    

    private:
    // glm::vec2* circular_buffer; //if size is run time passed in through constructor.
    glm::vec2 circular_buffer[SNAKE_BUFFER_SIZE]; //Why pretend not known at compile time?
    glm::vec2 direction_offset;
    int head_idx;
    int tail_idx;
    int snake_len;
    int buffer_size;


};

#endif
