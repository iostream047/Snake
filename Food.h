#ifndef FOOD_H
#define FOOD_H

#include <glm/vec2.hpp>

class Food{
    public:
        Food(); //default valid but empty initialization

        glm::vec2 getPos() const;
        int getNutrition() const;


        Food& setPosition(glm::vec2 pos); // must remember to use
        Food& setNutrition(int n); //must remember to use

    private:
        glm::vec2 pos; 
        int nutrition;
};

#endif