#include <SFML/Graphics.hpp>
#include "../include/BodyFull.h"
#include "../include/Food.h"

#define BODY_SIZE 50
#define ROWS 30
#define COLUMNS 20
#define X_SIZE (ROWS * BODY_SIZE)
#define Y_SIZE (COLUMNS * BODY_SIZE)

bool checkCollision(std::list<BodyPiece>& body);
bool checkFoodEaten(std::list<BodyPiece>& body, sf::Vector2<float> foodPos);
bool outOfBoundaries(sf::Vector2<float> headPos);

int main() {
    srand(time(nullptr));
    // The eaten piece doesn't immediately appear on screen, it waits for the end of the
    // snake body to get added to it

    sf::RenderWindow window(sf::VideoMode(X_SIZE, Y_SIZE), "SnakeGame");
    BodyFull snake = BodyFull(7, BODY_SIZE, {X_SIZE / 2, Y_SIZE / 2});

    Food food = Food(ROWS, COLUMNS, BODY_SIZE);
    food.newPos();
    printf("%f, %f", food.getPosition().x, food.getPosition().y);

    sf::Vector2<float> offset = {0, 0};
    int frame = 0;
    bool keyPressed = false, foodEaten = false;
    sf::Vector2<float> tailPos;

    while (window.isOpen()){
        sf::Event event{};
        while(window.pollEvent(event)){
            switch (event.type) {
                case sf::Event::Closed:{
                    // Put a confirmation window here
                    window.close();
                    break;
                }

                case sf::Event::KeyPressed:{
                    keyPressed = true;
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                        offset = {0, -50};
                    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                        offset = {0, 50};
                    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                        offset = {-50, 0};
                    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                        offset = {50, 0};
                    }
                }

                default:
                    break;
            }
        }
        window.clear();

        if ((frame % 500  == 0) && keyPressed) {
            tailPos = snake.getPieces().end().operator--()->getPosition();
            for (std::_List_iterator<BodyPiece> it = snake.getPieces().end().operator--();
                 it != snake.getPieces().begin(); --it) {
                it->setPosition(std::prev(it)->getPosition());
            }
            if (foodEaten){
                snake.addPiece(tailPos);
                foodEaten = false;
            }
            snake.getPieces().begin()->move(offset);
        }


        if (checkFoodEaten(snake.getPieces(), food.getPosition())){
            foodEaten = true;
            food.newPos();
        }

        if (checkCollision(snake.getPieces()) && keyPressed)
            window.close();

        if (outOfBoundaries(snake.getPieces().begin()->getPosition()))
            window.close();

        for(const auto & i : snake.getPieces()){
            window.draw(i);
        }
        window.draw(food);

        frame++;
        window.display();
    }


    return 0;
}

bool checkCollision(std::list<BodyPiece>& body){
    sf::Vector2<float> headPos = body.begin()->getPosition();
    for (std::_List_iterator<BodyPiece> piece = ++body.begin(); piece != body.end() ; ++piece) {
        if (piece->getPosition().x == headPos.x && piece->getPosition().y == headPos.y)
            return true;
    }
    return false;
}

bool checkFoodEaten(std::list<BodyPiece>& body, sf::Vector2<float> foodPos){
    if(body.begin()->getPosition().x == foodPos.x &&
        body.begin()->getPosition().y == foodPos.y)
        return true;

    return false;
}

bool outOfBoundaries(sf::Vector2<float> headPos){
    if(headPos.x >= X_SIZE || headPos.x < 0 || headPos.y >= Y_SIZE || headPos.y < 0)
        return true;

    return false;
}
