#include "GameVisualizer.h"
#include<iostream>

GameVisualizer::GameVisualizer(const GameData& data):data_view(data){
    
}

void GameVisualizer::printGameBoard(){
    const std::array<std::array<BoardCell,BOARD_COLS>,BOARD_ROWS>& game_board 
        = data_view.viewBoard();

    for(int i=0;i<BOARD_COLS;i++){
        std::cout<<"#";     
    }std::cout<<std::endl;

    std::cout << "score:" << data_view.getScore() << std::endl;
    for(std::size_t i=0; i<game_board.size(); i++){
        for(std::size_t j=0; j<game_board[i].size();j++){
            std::cout << game_board[i][j].getCharRepr();
            if( j != game_board[i].size() ){
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    for(int i=0;i<BOARD_COLS;i++){
        std::cout<<"#";     
    }std::cout<<std::endl;
}

