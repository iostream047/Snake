#include "Direction.h"
#include <cassert>
#include <stdexcept>

/*Direction::Direction(int i){
    if(i < 0 || i>VALUE_COUNT-1){
        throw std::invalid_argument("Direction index must be valid");
    }    
    direction = static_cast<DirectionName>(i);    
}*/

Direction::Direction(DirectionName d):direction{d}{}
int Direction::getTotalDirections(){
    return VALUE_COUNT;
}
std::string Direction::getName(){
    switch(direction){
        case(DirectionName::UP):
            return "UP";
        case(DirectionName::RIGHT):
            return "RIGHT";
        case(DirectionName::DOWN):
            return "DOWN";
        case(DirectionName::LEFT):
            return "LEFT";
        default:
            assert(false);
    }    
}
