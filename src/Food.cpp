#include "../include/Food.h"

Food::Food(int xSize, int ySize, int bodySize) {
    this->xSize = xSize;
    this->ySize = ySize;
    this->bodySize = bodySize;
    this->setFillColor(sf::Color::Cyan);
    this->setSize({static_cast<float>(bodySize), static_cast<float>(bodySize)});
    this->setPosition({0, 0});
}

void Food::newPos() {
    /**
     *
        Should use the <random> C++11 library for "true" randomness.
        Will maybe change in the future

    **/
    this->setPosition({static_cast<float>((rand() % xSize) * bodySize),
                       static_cast<float>((rand() % ySize) * bodySize)});
}
