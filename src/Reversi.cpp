#include "Reversi.h"
#include <iostream>

const Board& Reversi::getBoard() const
{
    return board;
}

namespace
{
    const Position INVALID_POSITION = static_cast<Position>(MAX_GRID_NUM);

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
        movesOriginalPosition[next].push(p);
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

void Reversi::refresh(const Board& newBoard)
{
    board = newBoard;
}

const Positions& Reversi::getAllAvailablePositions(GridStatus gridStatus)
{
    allPositions.clear();
    for(int i = a1; i < MAX_GRID_NUM; ++i)
    {
        Position p = static_cast<Position>(i);
        if(board.at(p).getStatus() == gridStatus)
        {
            allPositions = allPositions + gitAvailablePositions(p);
        }
    }

    return allPositions;
}

bool Reversi::isReachable(Position from, Position to, MoveFun move)
{
    enum { MAX_STEP = 8 };
    for(int i = a1; i <  MAX_STEP; ++i)
    {
        from = move(from);
        
        if( ! Board::onBoard(from)) return false;
        if(from == to) return true;
    }

    return false;
}

void Reversi::doTurn(Position from, Position to, MoveFun move)
{
    if(isReachable(from, to, move))
    {
        Position next = move(from);
        while(next != to)
        {
            board.turnOver(next);
            next = move(next);
        }
    }
}

void Reversi::turn(Position original, Position moves)
{
    doTurn(original, moves, up);
    doTurn(original, moves, down);
    doTurn(original, moves, left);
    doTurn(original, moves, right);
    doTurn(original, moves, leftUp);
    doTurn(original, moves, leftDown);
    doTurn(original, moves, rightUp);
    doTurn(original, moves, rightDown);
}

const Board& Reversi::capture(Position movePosition)
{
    lastBoard = board;
    while( ! movesOriginalPosition[movePosition].isEmpty())
    {
        Position originalPosition = movesOriginalPosition[movePosition].pop();
        board.place(movePosition, board.at(originalPosition).getStatus());
        turn(originalPosition, movePosition);
    }

    return board;
}

const Board& Reversi::retract()
{
    board = lastBoard;
    return board;
}
