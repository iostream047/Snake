#ifndef GAMECONSTANTS_H
#define GAMECONSTANTS_H

constexpr int BOARD_ROWS = 20;
constexpr int BOARD_COLS = 30;
constexpr int SNAKE_BUFFER_SIZE = BOARD_COLS*BOARD_ROWS+5; //5 extra breathing room
constexpr int SNAKE_INITIAL_LENGTH = 7;
constexpr int MAX_FOOD_COUNT = 2;

constexpr int TARGET_FRAME_RATE = 1;

#endif