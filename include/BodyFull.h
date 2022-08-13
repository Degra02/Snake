#include "BodyPiece.h"
#include <list>

#ifndef SNAKEGAME_BODYFULL_H
#define SNAKEGAME_BODYFULL_H


class BodyFull {
private:
    std::list<BodyPiece> pieces;
    int length;
    int size;

public:
    explicit BodyFull(int length, int size, sf::Vector2<float> headPos);
    void initSnakeBody();
    std::list<BodyPiece>& getPieces();
    void addPiece(sf::Vector2<float> pos);
    int getLength();
};


#endif //SNAKEGAME_BODYFULL_H
