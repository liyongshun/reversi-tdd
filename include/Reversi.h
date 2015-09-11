#ifndef _INCL_REVERSI_H_
#define _INCL_REVERSI_H_

#include "Board.h"
#include "Positions.h"

struct Reversi
{
    const Board& getBoard() const;
    void refresh(const Board&);

    const Positions& gitAvailablePositions(Position);
    const Positions& getAllAvailablePositions(GridStatus);
    const Board& capture(Position move);
    const Board& retract();

private:
    bool hasNext(Position curr, Position moves) const;
    typedef Position (*MoveFun)(Position p);
    void find(Position p, MoveFun);
    bool isReachable(Position from, Position to, MoveFun);
    void turn(Position original, Position moves);
    void doTurn(Position from, Position to, MoveFun);

private:
    Board board;
    Board lastBoard;

private:
    Positions availablePositions;
    Positions allPositions;
    Positions movesOriginalPosition[MAX_GRID_NUM];
};

#endif