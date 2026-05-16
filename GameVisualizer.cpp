#include "GameVisualizer.h"

GameVisualizer::GameVisualizer(const GameData& data):
    data_view(data),
    clear_command{}{
    #if defined(_WIN64)
        clear_command = "cls";
    #elif defined(_WIN32)
        clear_command = "cls";
    #elif defined(__linux__)
        clear_command = "clear";
    #endif
}


const char* GameVisualizer::getClearCommand() const{
    return clear_command.c_str();
}

std::stringstream& GameVisualizer::visualizeGameBoard(){
    ss.str("");
    ss.clear();
    
    const std::array<std::array<BoardCell,BOARD_COLS>,BOARD_ROWS>& game_board 
        = data_view.viewBoard();

    for(int i=0;i<BOARD_COLS;i++){
        ss<<"#";     
    }ss<<std::endl;

    ss << "score:" << data_view.getScore() << std::endl;
    for(std::size_t i=0; i<game_board.size(); i++){
        for(std::size_t j=0; j<game_board[i].size();j++){
            ss << game_board[i][j].getCharRepr();
            if( j != game_board[i].size() ){
                ss << " ";
            }
        }
        ss << "\n";
    }

    for(int i=0;i<BOARD_COLS;i++){
        ss<<"#";     
    }ss<<std::endl;
    return ss;
}

