#ifndef SNAKEGAME_POSITION_H
#define SNAKEGAME_POSITION_H


#include "Direction.h"

class Position {
private:
    int x;
    int y;

public:
    Position();
    Position(int x, int y);
    void updatePos(const int* offsetValues);
    int getX() const;
    int getY() const;
};

#endif //SNAKEGAME_POSITION_H
