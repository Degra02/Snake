#include <SFML/Graphics.hpp>
#include "Position.h"

#ifndef SNAKEGAME_BODYPIECE_H
#define SNAKEGAME_BODYPIECE_H


class BodyPiece {
    private:
        double size;
        Position position;
        sf::Color color;
public:
        BodyPiece();
        explicit BodyPiece(Position position);
        BodyPiece(double size, sf::Color color, Position position);
        Position forward(Position nextPos);
        Position getPosition();
        void setPosition(Position position);
};


#endif //SNAKEGAME_BODYPIECE_H
