// #ifndef SNAKENODE_H
// #define SNAKENODE_H

// #include "glm/vec2.hpp"

// class SnakeNode{
//     //elect for a circular buffer implementation instead... unused...
//     public:
//     SnakeNode(glm::vec2 pos);

//     ~SnakeNode(){
//         //You better isolate a node if you want it deleted separately
//         delete next_node;
//         next_node = nullptr;
//         delete prev_node;
//         prev_node = nullptr;
//     }

//     glm::vec2 getPos();
//     SnakeNode* getNextNode();
//     SnakeNode* getPrevNode();
//     void setNextNode(SnakeNode* next_ptr);
//     void setPrevNode(SnakeNode* prev_ptr);

//     private:
//     glm::vec2 pos;
//     SnakeNode* next_node;
//     SnakeNode* prev_node;
// };

// #endif