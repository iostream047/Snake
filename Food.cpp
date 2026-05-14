#include "Food.h"

Food::Food(int nutrition, glm::vec2 pos):
    nutrition(nutrition),
    pos(pos){

}

glm::vec2 Food::getPos() const{
    return pos;
}
int Food::getNutrition() const{
    return nutrition;
}