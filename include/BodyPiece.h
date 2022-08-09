#include <SFML/Graphics.hpp>

#ifndef SNAKEGAME_BODYPIECE_H
#define SNAKEGAME_BODYPIECE_H


class BodyPiece {
    private:
        double size;
        sf::Color color;

    public:
        double* position;
        BodyPiece(double size, sf::Color color, double* position);

};


#endif //SNAKEGAME_BODYPIECE_H
