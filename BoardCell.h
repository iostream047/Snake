#ifndef BOARDCELL_H
#define BOARDCELL_H

#include <assert.h>
#include "CellState.h"


class BoardCell{
    public:
    BoardCell(); //mandatory default constructor for array construction
    void changeState(CellState state); //modifies
    CellState getCellState() const;
    char getCharRepr() const;

    private:
    CellState cell_state; //mutable
    char representation;  //mutable
};

#endif