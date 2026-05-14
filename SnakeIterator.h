#ifndef SNAKEITERATOR_H
#define SNAKEITERATOR_H

#include "glm/vec2.hpp"

class SnakeIterator{
    public:
    SnakeIterator(const glm::vec2* circular_buffer,int buffer_size, int head_idx, int snake_length);
    glm::vec2 next();
    bool empty();

    private:
    const glm::vec2* c_buff; //reassignable, non mutable
    int current_idx;  
    int buffer_size;
    int remaining_count;
    //Should know about the implementation details of the Snake class
    //abastracts away Snake class implementation details from other classes
};
#endif