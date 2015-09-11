#include "Reversi.h"

const Board& Reversi::getBoard() const
{
    return board;
}

namespace
{
    const Position INVALID_POSITION = static_cast<Position>(h8+1);

    Position up(Position p)
    {
        return static_cast<Position>(p-8);
    }

    Position down(Position p)
    {
        return static_cast<Position>(p+8);
    }

    bool onARow(Position l, Position r)
    {
        return l/8 == r/8;
    }

    Position left(Position p)
    {
        Position leftPos = static_cast<Position>(p-1);
        return onARow(p, leftPos) ? leftPos : INVALID_POSITION;
    }

    Position right(Position p)
    {
        Position rightPos = static_cast<Position>(p+1);
        return onARow(p, rightPos) ? rightPos : INVALID_POSITION;
    }

    Position leftUp(Position p)
    {
        return left(up(p));
    }

    Position leftDown(Position p)
    {
        return left(down(p));
    }

    Position rightUp(Position p)
    {
        return right(up(p));
    }

    Position rightDown(Position p)
    {
        return right(down(p));
    }
}

bool Reversi::hasNext(Position curr, Position moves) const
{
    return board.isOccupied(moves) && board.at(moves) != board.at(curr);
}

void Reversi::find(Position p, MoveFun move)
{
    if( ! board.isOccupied(p)) return;

    Position next = p;
    do
    {
        next =  move(next);
    }while(hasNext(p, next));

    if( ! board.onBoard(next)) return;

    if( ! board.isOccupied(next) && next != move(p))
    {
        availablePositions.push(next);
    }
}

const Positions& Reversi::gitAvailablePositions(Position p)
{
    availablePositions.clear();

    find(p, up);
    find(p, down);
    find(p, left);
    find(p, right);
    find(p, leftUp);
    find(p, leftDown);
    find(p, rightUp);
    find(p, rightDown);

    return availablePositions;
}