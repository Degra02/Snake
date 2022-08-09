#include <SFML/Graphics.hpp>
#include "../../include/BodyPiece.h"

BodyPiece::BodyPiece(double size, sf::Color color, Pos position) {
    this->size = size;
    this->color = color;
    this->position = position;
}

BodyPiece::BodyPiece() {

}

BodyPiece::BodyPiece(Pos position) {
    this->position = position;
    // this->color = sf::Color::White;
}

Pos BodyPiece::forward(Pos nextPos) {
    Pos prevPos = this->position;
    this->position = nextPos;
    return prevPos;
}
