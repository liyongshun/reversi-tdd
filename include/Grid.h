#ifndef _INCL_GRID_H_
#define _INCL_GRID_H_

enum GridStatus { EMPTY, BLACK, WHITE };

struct Grid
{
    Grid();

    void place(GridStatus);
    void reset();
    void turnOver();

    bool isOccupied() const;
    bool isBlack() const;
    bool isWhite() const;
    bool operator!=(const Grid& rhs) const;
private:
    GridStatus status;
};

#endif
