#ifndef _INCL_OTHELLO_POSITIONS_H_
#define _INCL_OTHELLO_POSITIONS_H_

#include "Position.h"
#include <vector>

struct Positions
{
    Positions(std::initializer_list<Position> positions = {});  

    void push(Position);
    void clear();

    bool isEmpty() const; 
    bool operator==(const Positions& rhs) const;
    bool operator!=(const Positions& rhs) const;
    Position at(int index) const;
    size_t size() const;

private:
    bool contains(Position p) const;

private:
    std::vector<Position> positions;

};

#endif