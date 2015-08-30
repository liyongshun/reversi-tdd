#include "Board.h"

Board::Board()
{
    for(Grid& status: grids)
    {
        status.reset();
    }

    grids[e4].place(B);
    grids[d5].place(B);
    grids[d4].place(W);
    grids[e5].place(W);
}

Grid Board::at(Position p) const
{
    if( ! onBoard(p))
    {
        static Grid nullGrid;
        return nullGrid;
    } 
    
    return grids[p];
}

bool Board::isOccupied(Position p) const
{
    if( ! onBoard(p)) return false;
    return grids[p].isOccupied();
}

bool Board::onBoard(Position p)
{
    return p >= a1 && p <= h8;
}

void Board::place(Position p, GridStatus s)
{
    grids[p].place(s);
}

void Board::turnOver(Position p)
{
    grids[p].turnOver();
}




