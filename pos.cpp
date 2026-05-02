#include "pos.h"
#include <functional> //for std::hash 

pos::pos(int x,int y) : x(x), y(y) 
{
    is_invalid=false;   
}

int pos::get_x()const{
    return x;
}

int pos::get_y()const{
    return y;
}

void pos::inc_x(){
    x++;
}
void pos::dec_x(){
    x--;
}
void pos::inc_y(){
    y++;
}

void pos::dec_y(){
    y--;
}

void pos::invalidate()
{
    is_invalid=true;
}

bool pos::get_is_invalid()const{
    return is_invalid;
}
bool operator==(const pos& current_pos,const pos& other){
    return ((current_pos.x==other.x) && (current_pos.y==other.y));
}
std::size_t pos_hash_functor::operator()(const pos& position) const{
    return ( (std::hash<int>()(position.x)) ^ ((std::hash<int>()(position.y))<<1 ) );
}

/*std::size_t std::hash<pos>::operator()(const pos& position) const{
    return (std::hash<int>()(position.x))^((std::hash<int>()(position.y))<< 1); 
    //the second coordinate is bitshifted to reduce chances of collisions.
    //example: (1,2) vs (2,1)
}*/
