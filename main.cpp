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

    std::chrono::steady_clock::time_point loop_start_time;
    std::chrono::steady_clock::time_point loop_end_time;
    std::chrono::nanoseconds delta_time = std::chrono::nanoseconds{0};
    double fps_sum = 0;
    std::chrono::nanoseconds frame_time_sum = std::chrono::nanoseconds{0};
    int frame_count = 0;
    double average_fps = 0;
    std::chrono::nanoseconds average_frame_time = std::chrono::nanoseconds{0};
    
    
    while(!game_over){
        loop_start_time=std::chrono::steady_clock::now();

        //prvious loop accounting, except the first loop
        if(delta_time != std::chrono::nanoseconds{0}){
            frame_time_sum += delta_time;//from previous loop
            fps_sum += 1'000'000'000/ delta_time.count();
            frame_count++;
            average_fps = fps_sum/frame_count;
            average_frame_time = frame_time_sum/frame_count;
        }

        //process this loop:
        input();
        game_over = game.gameTick();
        std::stringstream& ss = draw(game,renderer);

        ss << "average fps: " 
            << average_fps
            << std::endl
            << "average frame time: "
            << std::chrono::duration_cast<std::chrono::milliseconds> (average_frame_time).count()
            << " ms.";
        std::cout << ss.str();
        
        if(frame_count > 10){//30*10){
            exit(0);
        }
        
        //Sleep after all work done:
        // std::chrono::nanoseconds time_left_in_frame = std::chrono::steady_clock::now() - ;
    
        loop_end_time = std::chrono::steady_clock::now();
        delta_time = loop_end_time-loop_start_time;//pass to the next loop
        
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


