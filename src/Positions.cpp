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

void Positions::clear()
{
    positions.clear();
}

Position Positions::at(int index) const
{
    return positions.at(index);
}

size_t Positions::size() const
{
    return positions.size();
}

Positions& Positions::operator+(const Positions& rhs)
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
        std::cout << position << ", ";
    }

    std::cout << "\n";

}

