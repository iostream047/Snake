#ifndef FOOD_H
#define FOOD_H

#include "pos.h"

class food{
    private:
    int nutrition_value;
    pos position; 
    //int scaling_factor;
       
 
    public: 
    food(int nutrition, pos& position);
    //food(int nutrition, int scaling_factor);
    void disappear();
};

#endif
