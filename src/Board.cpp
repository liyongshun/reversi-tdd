#include "Board.h"
#include "Positions.h"
#include <iostream>

Board::Board()
{
    for(Grid& status: grids)
    {
        status.reset();
    }

    grids[e4].place(BLACK);
    grids[d5].place(BLACK);
    grids[d4].place(WHITE);
    grids[e5].place(WHITE);
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

void Board::place(const Positions& positions, GridStatus status)
{
    for(size_t index = 0; index < positions.size(); ++index)
    {
        place(positions.at(index), status);
    }
}

void Board::turnOver(Position p)
{
    grids[p].turnOver();
}

bool Board::operator==(const Board& rhs) const
{
    size_t counter = 0;
    for(const auto grid : grids)
    {
        if(grid != rhs.grids[counter++]) return false;

    }

    return true;
}




