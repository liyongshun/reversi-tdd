#include "Reversi.h"
#include "Direction.h"

const Board& Reversi::getBoard() const
{
    return board;
}

bool Reversi::hasNext(Position curr, Position moves) const
{
    return board.isOccupied(moves) && board.at(moves) != board.at(curr);
}

void Reversi::find(Position p, const Removable& direction)
{
    if( ! board.isOccupied(p)) return;

    Position next = p;
    do
    {
        next =  direction.move(next);
    }while(hasNext(p, next));

    if( ! board.onBoard(next)) return;

    if( ! board.isOccupied(next) && next != direction.move(p))
    {
        availablePositions.push(next);
        movesOriginalPosition[next].push(p);
    }
}

const Positions& Reversi::gitAvailablePositions(Position p)
{
    availablePositions.clear();

    find(p, _up);
    find(p, _down);
    find(p, _left);
    find(p, _right);
    find(p, _left_up);
    find(p, _left_down);
    find(p, _right_up);
    find(p, _right_down);

    return availablePositions;
}

void Reversi::refresh(const Board& newBoard)
{
    board = newBoard;
}

const Positions& Reversi::getAllAvailablePositions(GridStatus gridStatus)
{
    allPositions.clear();
    for(int i = a1; i < MAX_POSITION_NUM; ++i)
    {
        Position p = static_cast<Position>(i);
        if(board.at(p).getStatus() == gridStatus)
        {
            allPositions = allPositions + gitAvailablePositions(p);
        }
    }

    return allPositions;
}

bool Reversi::isReachable(Position from, Position to, const Removable& direction)
{
    enum { MAX_STEP = 8 };
    for(int i = a1; i <  MAX_STEP; ++i)
    {
        from = direction.move(from);

        if( ! Board::onBoard(from)) return false;
        if(from == to) return true;
    }

    return false;
}

void Reversi::doTurn(Position from, Position to, const Removable& direction)
{
    if(isReachable(from, to, direction))
    {
        Position next = direction.move(from);
        while(next != to)
        {
            board.turnOver(next);
            next = direction.move(next);
        }
    }
}

void Reversi::turn(Position original, Position moves)
{
    doTurn(original, moves, _up);
    doTurn(original, moves, _down);
    doTurn(original, moves, _left);
    doTurn(original, moves, _right);
    doTurn(original, moves, _left_up);
    doTurn(original, moves, _left_down);
    doTurn(original, moves, _right_up);
    doTurn(original, moves, _right_down);
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
