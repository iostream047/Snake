#include "snake.h"

snake::snake(int head_x, int head_y, int initial_length){
    for(int i=0;i<initial_length;i++){
        pos_list.push_back(pos(head_x,head_y-i));
    }        
}

const std::vector<pos>& snake::get_coordinates(){
    return pos_list;
}

void snake::follow_head(){
    for(int i=1;i<pos_list.size();i++){
        pos_list.at(i)= pos_list.at(i-1); //shallow copy assignment
    }
}

void snake::advance_one_step(Direction dir){
    switch (dir){

    case up:
        follow_head();
        pos_list.at(0).inc_y();
    
        break;

    case down:
        follow_head();
        pos_list.at(0).dec_y();
        break;

    case left:
        follow_head();
        pos_list.at(0).dec_x();
        break;

    case right:
        follow_head();
        pos_list.at(0).inc_x();
        break;    

    }    
}

void snake::consume(food f){
    f.disappear();
}

