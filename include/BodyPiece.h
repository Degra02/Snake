#include <SFML/Graphics.hpp>
#include "Position.h"

#ifndef SNAKEGAME_BODYPIECE_H
#define SNAKEGAME_BODYPIECE_H


class BodyPiece {
    private:
        double size;
        sf::Color color;

    public:
        Pos position;
        BodyPiece(double size, sf::Color color, Pos position);
        Pos forward(Pos nextPos);
};


#endif //SNAKEGAME_BODYPIECE_H
