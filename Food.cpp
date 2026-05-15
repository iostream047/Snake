#include "Food.h"
Food::Food():
    pos(0,0),
    nutrition{1}{
        //default construction - not necessarily ready to use
        //a valid but empty state.
}

glm::vec2 Food::getPos() const{
    return pos;
}
int Food::getNutrition() const{
    return nutrition;
}

Food& Food::setPosition(glm::vec2 pos){
    this -> pos = pos;
    return *this;
}
Food& Food::setNutrition(int n){
    nutrition = n;
    return *this;
}