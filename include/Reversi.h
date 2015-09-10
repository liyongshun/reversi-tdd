#ifndef _INCL_REVERSI_H_
#define _INCL_REVERSI_H_

#include "Board.h"

struct Reversi
{
    const Board& getBoard() const;

private:
    Board board;
};

#endif