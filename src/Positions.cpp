#include "Positions.h"
#include <iostream>

Positions::Positions(std::initializer_list<Position> positions)
{
    for(auto position : positions)
    {
        push(position);
    }
}

bool Positions::isEmpty() const
{
    return positions.size() == 0;
}

bool Positions::operator==(const Positions& rhs) const
{
    if(positions.size() != rhs.positions.size()) return false;

    for(auto item : rhs.positions)
    {
        if( ! contains(item)) return false;
    }

    return true;
}

bool Positions::operator!=(const Positions& rhs) const
{
    return !operator==(rhs);
}

bool Positions::contains(Position p) const
{
    for(auto item : positions)
    {
        if(item == p) return true;
    }

    return false;
}

void Positions::push(Position p)
{
    if(contains(p)) return;

    positions.push_back(p);
}

Position Positions::pop()
{
    Position front = positions.front();
    positions.pop_front();
    return front;
}

void Positions::clear()
{
    positions.clear();
}

Positions& Positions::operator+=(const Positions& rhs)
{
    for(auto position : rhs.positions)
    {
        push(position);
    }

    return *this;
}

void Positions::print() const
{
    for(auto position : positions)
    {
        std::cout << to_str(position) << ", ";
    }

    std::cout << "\n";

}

