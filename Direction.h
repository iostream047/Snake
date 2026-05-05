#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>

class Direction{
    private:
    enum DirectionName{
        UP,
        RIGHT,
        DOWN,
        LEFT
    };
    static const int VALUE_COUNT = 4;

    DirectionName direction;
    const DirectionName values[];

    public:
    //Direction (int i);
    Direction (DirectionName d);
    std::string getName();
    int getTotalDirections();
    //const getValues();
        
};
#endif
