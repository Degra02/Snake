#ifndef SNAKEGAME_POSITION_H
#define SNAKEGAME_POSITION_H


#include "Direction.h"

class Position {
private:
    int x;
    int y;

public:
    Position(int x, int y);
    void updatePos(int* offsetValues);
    int getX() const;
    int getY() const;
};

typedef Position* Pos;

#endif //SNAKEGAME_POSITION_H
