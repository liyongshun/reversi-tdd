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
    Positions given = positions;
    while( ! given.isEmpty())
    {
        Position p = given.pop();
        place(p, status);   
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
        if(grid.getStatus() != rhs.grids[counter++].getStatus()) return false;
    }

    return true;
}

namespace
{
    char to_c(Grid grid)
    {

        switch(grid.getStatus())
        {
            case EMPTY: return '_';
            case BLACK: return 'B';
            case WHITE: return 'W';
            default: return '@';
        }
    }
}

void Board::print() const
{
    std::cout <<  "\n" << "a b c d e f g h" << std::endl;

    enum { COLUMN_NUM = 8 };
    for(int i = a1; i < MAX_POSITION_NUM; ++i)
    {
        if(i % COLUMN_NUM == 0 && i != 0)
        {
            std::cout << " " << i/COLUMN_NUM << "\n";
        }
        std::cout << to_c(grids[i]) << " ";
    }

    std::cout << " " << COLUMN_NUM << "\n";
}




