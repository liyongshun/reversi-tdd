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

private:
    bool hasNext(Position curr, Position moves) const;
    typedef Position (*MoveFun)(Position p);
    void find(Position p, MoveFun);

private:
    Board board;

private:
    Positions availablePositions;
    Positions allPositions;
};

#endif