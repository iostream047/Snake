#include <iostream>
//#include <conio.h>
//#include <windows.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "GameManager.h"
#include "GameVisualizer.h"

void setup();
void draw(); 
void input();
void logic();

bool game_over=false;
std::string CLEAR_COMMAND = "Tomato";
int fps=30;

void setup()
{
    game_over=false;
    #if defined(_WIN64)
        CLEAR_COMMAND = "cls";
    #elif defined(_WIN32)
        CLEAR_COMMAND = "cls";
    #elif defined(__linux__)
        CLEAR_COMMAND = "clear";

    #endif
}

void draw(GameManager& game, GameVisualizer& renderer){
    // system("clear");
    // system("cls");
    system(CLEAR_COMMAND.c_str());
    renderer.printGameBoard();
}
void input()
{
    return;
}  
void logic(){
    return;
}


int main(int argc, char * argv[])
{
    GameManager game; //most vexing parse avoided!
    GameVisualizer renderer{game.viewGameData()};
    setup();

    auto start_time=std::chrono::high_resolution_clock::now();
    
   
    
    
    while(!game_over){
        std::cout<<"loop";
        draw(game,renderer);
        input();
        logic();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/fps));
        
        auto current_time=std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_span= std::chrono::duration_cast<std::chrono::duration<double>>(current_time-start_time);
        // if(time_span.count()>5){
        //     game_over=true;
        //     printf("%18s","Game OVER!\n");
        // }
    }
 
    return 0;
}


