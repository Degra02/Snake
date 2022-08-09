#ifndef SNAKEGAME_DIRECTION_H
#define SNAKEGAME_DIRECTION_H

enum Dir{
    UP, DOWN, LEFT, RIGHT
};

class Direction {
public:
    const Dir dir;
    int* offsetValue();
};


#endif //SNAKEGAME_DIRECTION_H
