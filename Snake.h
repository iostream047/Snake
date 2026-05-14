#ifndef SNAKE_H
#define SNAKE_H

#include "glm/vec2.hpp"
#include "Direction.h"
#include "SnakeIterator.h"

class Snake{
    
    public:
    Snake();
    ~Snake();
    void build(int buffer_size);
    int pushBack(glm::vec2 pos);

    //getters:
    glm::vec2 getHeadPos() const;
    glm::vec2 getTailPos() const;
    int getSnakeLen() const;
    SnakeIterator getIterator() const;
    

    //movement:
    void changeDirection(Direction d);
    glm::vec2 moveOnce(); //return prev_tail
    

    private:
    glm::vec2* circular_buffer;
    glm::vec2 direction_offset;
    int head_idx;
    int tail_idx;
    int snake_len;
    int buffer_size;


};

#endif
