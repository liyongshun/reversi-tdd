#include "Grid.h"

Grid::Grid()
{
    reset();
}

void Grid::place(GridStatus s)
{
    if(s == _) return;
    status = s;
}

void Grid::reset()
{
    status = _;
}

void Grid::turnOver()
{
    if( ! isOccupied()) return;

    status = isBlack() ? W : B;
}

bool Grid::isOccupied() const
{
    return isBlack() || isWhite();
}

bool Grid::isBlack() const
{
    return status == B;
}

bool Grid::isWhite() const
{
    return status == W;
}
