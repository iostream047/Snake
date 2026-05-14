#ifndef FOOD_H
#define FOOD_H

#include <glm/vec2.hpp>

class Food{
    public:
        Food(int nutrition, glm::vec2 pos);

        glm::vec2 getPos() const;
        int getNutrition() const;
        void reposition(); //move random generating machinery here...

    private:
        glm::vec2 pos; 
        int nutrition;
};

#endif