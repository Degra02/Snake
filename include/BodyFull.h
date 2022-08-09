#include "BodyPiece.h"
#include "Direction.h"
#include <list>

#ifndef SNAKEGAME_BODYFULL_H
#define SNAKEGAME_BODYFULL_H


class BodyFull {
private:
    std::list<BodyPiece> pieces;

public:
    void moveSnake(Direction direction);
};


#endif //SNAKEGAME_BODYFULL_H
