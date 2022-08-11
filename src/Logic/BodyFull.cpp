#include "../../include/BodyFull.h"

BodyFull::BodyFull(int length) {
    this->length = length;
    this->pieces.emplace_back(BodyPiece(Position(10, 10)));
    initSnakeBody(this->pieces.begin()->getPosition());
}

void BodyFull::initSnakeBody(Position position){
    static int offset[] = {-1, 0};
    for (int i = 1; i < this->length; ++i) {
        this->pieces.emplace_back(BodyPiece());
    }
    Position p = Position(position.getX(), position.getY());
    for (auto & piece: this->pieces) {
        p.updatePos(offset);
        piece = BodyPiece(p);
    }
}

void BodyFull::moveSnake(Direction direction) {
    this->pieces.begin()->getPosition().updatePos(direction.offsetValue());

    std::list<BodyPiece>::iterator it;
    it = this->pieces.end();
    while (it.operator--() != this->pieces.begin()){
        it->setPosition(it.operator--()->getPosition());
    }
}

std::list<BodyPiece> BodyFull::getPieces() {
    return this->pieces;
}

