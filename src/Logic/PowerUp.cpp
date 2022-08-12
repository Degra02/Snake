#include "../../include/PowerUp.h"
#include <iostream>

PowerUp::PowerUp() {
    this->coordinates = nullptr;
}

PowerUp::PowerUp(const int *coordinates) {
    this->coordinates = new int[2];
    try {
        this->coordinates[0] = coordinates[0];
        this->coordinates[1] = coordinates[1];
    } catch (const char* exception) {
        printf("\n %s \n", exception);
    }
}

void PowerUp::newCoords() {
    /**
     *
        Should use the <random> C++11 library for "true" randomness.
        Will maybe change in the future

    **/
    this->coordinates[0] = rand() % 20;
    this->coordinates[1] = rand() % 20;
}
