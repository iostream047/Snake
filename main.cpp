#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "GameManager.h"
#include "GameVisualizer.h"

// void setup();
std::stringstream& draw(GameManager& game, GameVisualizer& renderer); 
void input();
void logic();




int main(int argc, char * argv[])
{
    //setup():
    GameManager game; //most vexing parse avoided!
    GameVisualizer renderer{game.viewGameData()};
    bool game_over=false;
    int fps=30;

    auto start_time=std::chrono::high_resolution_clock::now();
    double fps_sum = 0;
    int frame_count = 0;
    double average_fps = 0;
    
    
    while(!game_over){
        auto start_time=std::chrono::high_resolution_clock::now();

        input();
        game_over = game.gameLogic();
        std::stringstream& ss = draw(game,renderer);
        
        // std::this_thread::sleep_for(std::chrono::milliseconds(1000/fps));    
        std::chrono::nanoseconds delta_time = std::chrono::high_resolution_clock::now()-start_time;

        ss << "average fps: " 
            << average_fps
            << std::endl;
        std::cout << ss.str();

        fps_sum += 1'000'000'000/ delta_time.count();
        average_fps = fps_sum/++frame_count;
        if(frame_count > 30*10){
            exit(0);
        }
        
    }
 
    return 0;
}

std::stringstream& draw(GameManager& game, GameVisualizer& renderer){
    system(renderer.getClearCommand());
    return renderer.visualizeGameBoard();
}
void input()
{
    return;
}  
void logic(){
    return;
}


