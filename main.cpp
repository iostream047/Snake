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
    std::chrono::nanoseconds frame_time_sum = std::chrono::nanoseconds{0};
    int frame_count = 0;
    double average_fps = 0;
    std::chrono::nanoseconds average_frame_time = std::chrono::nanoseconds{0};
    
    
    while(!game_over){
        std::chrono::time_point start_time=std::chrono::steady_clock::now();

        input();
        game_over = game.gameLogic();
        std::stringstream& ss = draw(game,renderer);
        
        // std::this_thread::sleep_for(std::chrono::milliseconds(1000/fps));    
        std::chrono::nanoseconds delta_time = std::chrono::steady_clock::now()-start_time;
        frame_time_sum += delta_time;

        ss << "average fps: " 
            << average_fps
            << std::endl
            << "average frame time: "
            << std::chrono::duration_cast<std::chrono::milliseconds> (average_frame_time).count()
            << " ms.";
        std::cout << ss.str();

        fps_sum += 1'000'000'000/ delta_time.count();
        
        frame_count++;
        average_fps = fps_sum/frame_count;
        average_frame_time = frame_time_sum/frame_count;
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


