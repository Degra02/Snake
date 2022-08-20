#include <SFML/Graphics.hpp>
#include "../include/BodyPiece.h"

BodyPiece::BodyPiece() {
    this->setFillColor(sf::Color::White);
}

BodyPiece::BodyPiece(sf::Vector2<float> position, int size) {
    this->setOutlineThickness(-3);
    this->setOutlineColor(sf::Color::Black);
    this->setSize({static_cast<float>(size), static_cast<float>(size)});
    this->setPosition(position);
}