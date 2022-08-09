#include "../../include/BodyFull.h"

BodyFull::BodyFull(int length) {
    this->length = length;
    this->pieces.begin()->position = new Position(10, 10);
    initSnakeBody(this->pieces.begin()->position);
}

void BodyFull::initSnakeBody(Pos position){
    static int offset[] = {-1, 0};
    for (auto & piece: this->pieces) {
        position->updatePos(offset);
        piece = BodyPiece(position);
    }
}

void BodyFull::moveSnake(Direction direction) {
    this->pieces.begin()->position->updatePos(direction.offsetValue());

    std::list<BodyPiece>::iterator it;
    it = this->pieces.end();
    while (it.operator--() != this->pieces.begin()){
        it->position = it.operator--()->position;
    }
}

std::list<BodyPiece> BodyFull::getPieces() {
    return this->pieces;
}

