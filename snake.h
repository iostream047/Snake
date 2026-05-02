#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "pos.h"
#include "food.h"
#include "Direction.h"

class snake{
    private:
    std::vector<pos> pos_list;
    int speed;//units per second
    void follow_head();

    public:
    snake(int head_x, int head_y, int initial_length);
    const std::vector<pos>& get_coordinates();
    void advance_one_step(Direction dir);
    void consume(food f);

};

#endif
