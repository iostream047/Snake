#include "food.h"

food::food(int nutrition, pos& position): nutrition_value(nutrition), position(position){};

/*food::food(int nutrition, int scaling_factor){
    this->nutrition_value=nutrition;
    this->scaling_factor=scaling_factor;
}*/

void food::disappear(){
    position.invalidate();
}

