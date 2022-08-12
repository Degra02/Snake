#include <SFML/Graphics.hpp>
#include <thread>
#include "../include/BodyFull.h"

#define SIZE 6

int main() {
    srand(time(0));
    BodyFull snake = BodyFull(5);
    for (auto &piece: snake.getPieces()) {
        printf("\n %d %d", piece.getPosition().getX(), piece.getPosition().getY());
    }

    // The eaten piece doesn't immediately appear on screen, it waits for the end of the
    // snake body to get added to it

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SnakeGame");

    // Just for testing purposes

    int initialOffset = 0;
    sf::RectangleShape snakeBody[SIZE];

    for(int i = 0; i < SIZE; i++){
        snakeBody[i] = sf::RectangleShape({50, 50});
        snakeBody[i].setFillColor(sf::Color::White);
        snakeBody[i].setPosition(window.getSize().x/2 + initialOffset, window.getSize().y/2);
        initialOffset -= 50;
    }

    sf::Vector2<float> offset = {0, 0};
    int frame = 0;
    bool keyPressed = false;
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

        if (frame % 1920 == 0 && keyPressed){
            printf("\n\n\n");
            for(int i = SIZE-1; i > 0; --i){
                snakeBody[i].setPosition(snakeBody[i-1].getPosition());
            }
            snakeBody[0].move(offset);
        }

        for(const auto & i : snakeBody){
            window.draw(i);
            if(frame % 1920 == 0)
                printf("\n%f %f", i.getPosition().x, i.getPosition().y);
        }

        frame++;
        window.display();
    }


    return 0;
}
