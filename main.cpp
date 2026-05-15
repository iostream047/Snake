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
int fps=30;

void setup()
{
    game_over=false;
}

void draw(GameManager& game, GameVisualizer& renderer){
    // system("clear");
    system("cls");
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
    std::cout<<"hello world1";
    GameManager game; //most vexing parse avoided!
    GameVisualizer renderer{game.viewGameData()};
    std::cout<<"hello world2";

    auto start_time=std::chrono::high_resolution_clock::now();
    setup();
   
    
    
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


