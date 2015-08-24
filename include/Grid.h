#ifndef _INCL_GRID_H_
#define _INCL_GRID_H_

enum GridStatus { _, B, W };

struct Grid
{
    Grid();

    void place(GridStatus);
    void reset();
    void turnOver();

    bool isOccupied() const;
    bool isBlack() const;
    bool isWhite() const;
private:
    GridStatus status;
};

#endif
