#include <SFML/Graphics.hpp>
#include "../../include/BodyPiece.h"

BodyPiece::BodyPiece(double size, sf::Color color, Position position) {
    this->size = size;
    this->color = color;
    this->position = position;
}

BodyPiece::BodyPiece() {

}

BodyPiece::BodyPiece(Position position) {
    this->position = position;
}

Position BodyPiece::forward(Position nextPos) {
    Position prevPos = this->position;
    this->position = nextPos;
    return prevPos;
}

Position BodyPiece::getPosition() {
    return this->position;
}

void BodyPiece::setPosition(Position position) {
     this->position = position;
}
