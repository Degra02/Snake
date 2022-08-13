#include <SFML/Graphics.hpp>

#ifndef SNAKEGAME_BODYPIECE_H
#define SNAKEGAME_BODYPIECE_H


class BodyPiece : public sf::RectangleShape{
public:
        BodyPiece();
        BodyPiece(sf::Vector2<float> position, int size);
};


#endif //SNAKEGAME_BODYPIECE_H
