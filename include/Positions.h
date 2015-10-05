#ifndef _INCL_OTHELLO_POSITIONS_H_
#define _INCL_OTHELLO_POSITIONS_H_

#include "Position.h"
#include <list>

struct Positions
{
    Positions(std::initializer_list<Position> positions = {});  

    void push(Position);
    Position pop();
    void clear();

    bool isEmpty() const; 
    bool operator==(const Positions& rhs) const;
    bool operator!=(const Positions& rhs) const;
    Positions& operator+=(const Positions&);

    void print() const;

private:
    bool contains(Position p) const;

private:
    std::list<Position> positions;

};

#endif
