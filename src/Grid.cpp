#include "Grid.h"

Grid::Grid()
{
    reset();
}

void Grid::place(GridStatus status)
{
    if(status == EMPTY) return;
    this->status = status;
}

void Grid::reset()
{
    status = EMPTY;
}

void Grid::turnOver()
{
    if( ! isOccupied()) return;

    status = isBlack() ? WHITE : BLACK;
}

bool Grid::isOccupied() const
{
    return isBlack() || isWhite();
}

bool Grid::isBlack() const
{
    return status == BLACK;
}

bool Grid::isWhite() const
{
    return status == WHITE;
}
