#include <SFML/Graphics.hpp>
#include "../../include/BodyPiece.h"

BodyPiece::BodyPiece(double size, sf::Color color, Pos position) {
    this->size = size;
    this->color = color;
    this->position = position;
}

Pos BodyPiece::forward(Pos nextPos) {
    Pos prevPos = this->position;
    this->position = nextPos;
    return prevPos;
}
