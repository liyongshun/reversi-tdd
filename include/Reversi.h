#ifndef _INCL_REVERSI_H_
#define _INCL_REVERSI_H_

#include "Board.h"
#include "Positions.h"

struct Removable;

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
    void find(Position p, const Removable&);
    bool isReachable(Position from, Position to, const Removable&);
    void turn(Position original, Position moves);
    void doTurn(Position from, Position to, const Removable&);

private:
    Board board;
    Board lastBoard;

private:
    Positions availablePositions;
    Positions allPositions;
    Positions movesOriginalPosition[MAX_POSITION_NUM];
};

#endif