#include "SnakeIterator.h"

#include <stdexcept>

SnakeIterator::SnakeIterator(const glm::vec2* circular_buffer,int buffer_size, int head_idx,  int snake_length):
    c_buff(circular_buffer),
    buffer_size(buffer_size),
    current_idx(head_idx),
    remaining_count(snake_length)
    {
        //constructor
}

bool SnakeIterator::end(){
    return (remaining_count > 0) ? false : true;
}
glm::vec2 SnakeIterator::next(){
    if( end() ){
        throw std::runtime_error("Cannot acces itarator past end");
    }
    remaining_count --;
    glm::vec2 current_pos = c_buff[current_idx];
    current_idx = (current_idx+1+buffer_size)%buffer_size;
    return current_pos;
}
