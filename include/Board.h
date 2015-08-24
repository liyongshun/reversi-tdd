#ifndef _INCL_BOARD_H_
#define _INCL_BOARD_H_

#include "Position.h"
#include "Grid.h"

struct Board
{
    Board();
    void place(Position, GridStatus);
    void turnOver(Position);
    
    Grid at(Position p) const;
    bool isOccupied(Position) const;
    static bool onBoard(Position);

private:
    enum {MAX_GRID_NUM = h8+1 };
    Grid grids[MAX_GRID_NUM];
};

#endif
