#include <vector>
#include "BodyPiece.h"
#include "Direction.h"

#ifndef SNAKEGAME_BODYFULL_H
#define SNAKEGAME_BODYFULL_H


class BodyFull {
private:
    std::vector<BodyPiece> pieces;

public:
    void moveSnake(Direction direction);
};


#endif //SNAKEGAME_BODYFULL_H
