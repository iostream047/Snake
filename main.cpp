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
    double calculated_fps = 0;
    int frame_count = 0;
    
    
    while(!game_over){
        auto start_time=std::chrono::high_resolution_clock::now();

        input();
        logic();
        std::stringstream& ss = draw(game,renderer);
        
        // std::this_thread::sleep_for(std::chrono::milliseconds(1000/fps));    
        // std::chrono::duration<double> time_span= std::chrono::duration_cast<std::chrono::duration<double>>(current_time-start_time);
        auto delta_time = std::chrono::high_resolution_clock::now()-start_time;

        ss << "fps: " 
            << calculated_fps /++frame_count 
            << std::endl;
        std::cout << ss.str();

        calculated_fps += 1000000000/ delta_time.count();
        // exit(0);
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


