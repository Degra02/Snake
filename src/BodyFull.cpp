#include "../include/BodyFull.h"

BodyFull::BodyFull(int length, int size, sf::Vector2<float> headPos) {
    this->length = length;
    this->size = size;
    this->pieces.emplace_back(headPos, size);
    initSnakeBody();
}

void BodyFull::initSnakeBody(){
    sf::Vector2<float> offset = {-50, 0};
    sf::Vector2<float> pos = this->pieces.begin()->getPosition();
    for (int i = 1; i < this->length; ++i) {
        pos += offset;
        this->pieces.emplace_back(pos, this->size);
    }
}

int BodyFull::getLength() {
    return this->length;
}

std::list<BodyPiece>& BodyFull::getPieces() {
    return this->pieces;
}

void BodyFull::addPiece(sf::Vector2<float> pos) {
    this->pieces.emplace_back(pos, this->size);
}

