#ifndef _INCL_REVERSI_H_
#define _INCL_REVERSI_H_

#include "Board.h"
#include "Positions.h"

struct Removable;

struct Reversi
{
    const Board& getBoard() const;
    void refresh(const Board&);

    const Positions gitAvailablePositions(Position);
    const Positions getAllAvailablePositions(GridStatus);
    const Board& capture(Position move, GridStatus);
    const Board& retract();

private:
    bool hasNext(Position curr, Position moves) const;
    Positions findIn(Position p, const Removable&);

private:
    Board board;
    Board lastBoard;

private:
    Positions capturedPosition[MAX_POSITION_NUM];
};

#endif
