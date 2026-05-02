#include <iostream>
//#include <conio.h>
//#include <windows.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "food.h"
#include "snake.h"

void setup();
void draw(); 
void input();
void logic();

bool game_over=false;
const int height=20;
const int width=20;
int fps=30;

int main(int argc, char * argv[])
{
    auto start_time=std::chrono::high_resolution_clock::now();
    setup();
    while(!game_over){
        draw();
        input();
        logic();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/fps));
        
        auto current_time=std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_span= std::chrono::duration_cast<std::chrono::duration<double>>(current_time-start_time);
        if(time_span.count()>5){
            game_over=true;
            printf("%18s","Game OVER!\n");
        }
    }
 
    return 0;
}

void setup()
{
    game_over=false;
    snake my_snake=snake(width/2,height/2,3); 
}

void draw(){
    system("clear");
    const std::vector<pos> snake_body;

    for(int i=0;i<width;i++){
        std::cout<<"#";     
    }std::cout<<std::endl;

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j == 0 || j == width-1){
                std::cout<<"#";
            }else{
                //draw objects
                
                    

                std::cout<<" ";
            


            }
        }std::cout<<std::endl;
    }

    for(int i=0;i<width;i++){
        std::cout<<"#";     
    }std::cout<<std::endl;

}
void input()
{
    return;
}  
void logic(){
    return;
}
