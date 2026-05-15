#include "Snake.h"

#include <stdexcept>

Snake::Snake():
    direction_offset{0,-1}, //go left
    head_idx(0),
    tail_idx(0),
    snake_len(0),
    buffer_size(SNAKE_BUFFER_SIZE)
    {
    // circular_buffer = new glm::vec2[buffer_size]; //NO need - known at compile time
}

void Snake::pushBack(glm::vec2 pos){
    circular_buffer[tail_idx] = pos;
    tail_idx = (tail_idx+1+buffer_size)%buffer_size;
    snake_len++;
}

//getters:
glm::vec2 Snake::getHeadPos() const{
    return circular_buffer[head_idx];
}
glm::vec2 Snake::getTailPos() const{
    return circular_buffer[tail_idx];
}
int Snake::getSnakeLen() const{
    return snake_len;
}
SnakeIterator Snake::getIterator() const{
    return SnakeIterator(circular_buffer,buffer_size,head_idx,snake_len);//copy elision
}

//movement:
void Snake::changeDirection(Direction d){
    switch (d)
    {
    case Direction::UP:
        direction_offset.x = -1;
        direction_offset.y = 0;
        break;
    case Direction::RIGHT:
        direction_offset.x = 0;
        direction_offset.y = 1;
        break;
    case Direction::DOWN:
        direction_offset.x = 1;
        direction_offset.y = 0;
        break;
    case Direction::LEFT:
        direction_offset.x = 0;
        direction_offset.y = -1;
        break;
    
    default:
        throw std::runtime_error("impossible direction");
        break;
    }
}
glm::vec2 Snake::moveOnce() {//return prev_tail
    //move tail:
    glm::vec2 old_tail_pos = circular_buffer[tail_idx];
    tail_idx = (tail_idx-1+buffer_size)%buffer_size;

    //move head:
    int new_head_idx = (head_idx-1+buffer_size)%buffer_size;
    circular_buffer[new_head_idx] = circular_buffer[head_idx]+direction_offset;
    head_idx = new_head_idx;

    return old_tail_pos;
}