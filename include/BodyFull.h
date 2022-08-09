#include "BodyPiece.h"
#include "Direction.h"
#include <list>

#ifndef SNAKEGAME_BODYFULL_H
#define SNAKEGAME_BODYFULL_H


class BodyFull {
private:
    std::list<BodyPiece> pieces;
    int length;

public:
    explicit BodyFull(int length);
    void moveSnake(Direction direction);
    void initSnakeBody(Pos position);
    std::list<BodyPiece> getPieces();
};


#endif //SNAKEGAME_BODYFULL_H
