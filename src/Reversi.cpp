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

Positions Reversi::findIn(Position p, const Removable& direction)
{
    Positions availablePositions;
    Positions capturedPositions;
    Position next = direction.move(p);

    while(hasNext(p, next))
    {
        capturedPositions.push(next);
        next = direction.move(next);
    };

    if(board.onBoard(next) && !board.isOccupied(next) && next != direction.move(p))
    {
        availablePositions.push(next);
        capturedPosition[next] += capturedPositions;
    }

    return availablePositions;
}

const Positions Reversi::gitAvailablePositions(Position p)
{
    Positions availablePositions;

    for(auto direction : directions)
    {
        availablePositions += findIn(p, *direction);
    }

    return availablePositions;
}

const Positions Reversi::getAllAvailablePositions(GridStatus gridStatus)
{
    Positions allPositions;

    Positions gridPositions = board.getAll(gridStatus);
    while( ! gridPositions.isEmpty())
    {
        allPositions += gitAvailablePositions(gridPositions.pop());
    }

    return allPositions;
}

void Reversi::refresh(const Board& newBoard)
{
    board = newBoard;
}

const Board& Reversi::capture(Position movePosition, GridStatus status)
{
    lastBoard = board;

    while( ! capturedPosition[movePosition].isEmpty())
    {
        board.turnOver(capturedPosition[movePosition].pop());
    }

    board.place(movePosition, status);

    return board;
}

const Board& Reversi::retract()
{
    board = lastBoard;
    return board;
}
