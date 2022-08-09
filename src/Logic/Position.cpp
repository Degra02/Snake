#include "../../include/Position.h"

Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

void Position::updatePos(int* offsetValues) {
    this->x += offsetValues[0];
    this->y += offsetValues[1];
}

int Position::getX() const {
    return this->x;
}

int Position::getY() const {
    return this->y;
}
