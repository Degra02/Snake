#ifndef SNAKEGAME_FOOD_H
#define SNAKEGAME_FOOD_H

#include <SFML/Graphics/RectangleShape.hpp>

class Food : public sf::RectangleShape{
private:
    int xSize, ySize;
    int bodySize;
public:
    Food(int xSize, int ySize, int bodySize);
    void newPos();
};


#endif //SNAKEGAME_FOOD_H
