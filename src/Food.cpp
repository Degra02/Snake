#include "../include/Food.h"

Food::Food(int xSize, int ySize, int bodySize) {
    this->xSize = xSize;
    this->ySize = ySize;
    this->bodySize = bodySize;
    this->setOutlineThickness(-3);
    this->setOutlineColor(sf::Color::Black);
    this->setFillColor(sf::Color::Cyan);
    this->setSize({static_cast<float>(bodySize), static_cast<float>(bodySize)});
    this->setPosition({0, 0});
}

void Food::newPos() {
    this->setPosition({static_cast<float>((rand() % xSize) * bodySize),
                       static_cast<float>((rand() % ySize) * bodySize)});
}
