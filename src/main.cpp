#include <SFML/Graphics.hpp>
#include <thread>
#include "../include/BodyFull.h"

int main() {
    srand(time(0));
    BodyFull snake = BodyFull(5);
    for (auto &piece: snake.getPieces()) {
        printf("\n %d %d", piece.getPosition().getX(), piece.getPosition().getY());
    }

    // The eaten piece doesn't immediately appear on screen, it waits for the end of the
    // snake body to get added to it


    sf::RenderWindow window(sf::VideoMode(1000, 800), "SnakeGame");

    sf::RectangleShape  rectangle({50, 50});
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(window.getSize().x/2, window.getSize().y/2);


    sf::Vector2<float> offset = {0, 0};
    int frame = 0;
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

        if (frame % 1920 == 0){
            rectangle.move(offset);
        }
        frame++;

        window.draw(rectangle);
        window.display();
    }


    return 0;
}
