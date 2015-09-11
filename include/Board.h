#ifndef _INCL_BOARD_H_
#define _INCL_BOARD_H_

#include "Position.h"
#include "Grid.h"

struct Positions;
struct Board
{
    Board();
    void place(Position, GridStatus);
    void place(const Positions&, GridStatus);
    void turnOver(Position);
    
    Grid at(Position p) const;
    bool isOccupied(Position) const;
    bool operator==(const Board& rhs) const;
    
    static bool onBoard(Position);

private:
    enum {MAX_GRID_NUM = h8+1 };
    Grid grids[MAX_GRID_NUM];
};

#endif
