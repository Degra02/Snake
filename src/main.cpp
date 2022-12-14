    #include <SFML/Graphics.hpp>
#include "../include/BodyFull.h"
#include "../include/Food.h"
#include <thread>
#include <functional>
#include <cmath>

#define GAME_SPEED 7

#define BODY_SIZE 50
#define ROWS 30
#define COLUMNS 20
#define X_SIZE (ROWS * BODY_SIZE)
#define Y_SIZE (COLUMNS * BODY_SIZE)

bool checkCollision(std::list<BodyPiece>& body);
bool checkFoodEaten(std::list<BodyPiece>& body, sf::Vector2<float> foodPos);
bool outOfBoundaries(sf::Vector2<float> headPos);
bool equalPos(sf::Vector2<float> p1, sf::Vector2<float> p2);
bool validFoodPos(sf::Vector2<float> foodPos, std::list<BodyPiece>& pieces);
void game(sf::RenderWindow* window);

int main() {
    srand(time(nullptr));

    sf::RenderWindow window(sf::VideoMode(X_SIZE, Y_SIZE), "SnakeGame");
    sf::Font font;
    font.loadFromFile("04B_30__.TTF");
    window.setFramerateLimit(60);

    sf::Text loseScreen;
    loseScreen.setCharacterSize(50);
    loseScreen.setFont(font);
    loseScreen.setString("\t Play Again?\nPress y (yes) or n (no)");
    loseScreen.setPosition(window.getSize().x/2 - 450,
                           window.getSize().y/2 - 150);

    sf::Thread gameThread(game, &window);

    bool playAgain;

    do{
        playAgain = false;
        gameThread.launch();
        gameThread.wait();
        window.clear();
        window.draw(loseScreen);
        window.display();

        while (window.isOpen() && !playAgain){
            sf::Event event{};
            while(window.pollEvent(event)){
                switch (event.type) {
                    case sf::Event::Closed:{
                        window.close();
                        break;
                    }

                    case sf::Event::KeyPressed:{
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)){
                            playAgain = true;
                        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::N)){
                            playAgain = false;
                            window.close();
                        }
                    }

                    default:
                        break;
                }
            }
        }
    }while(playAgain);

    return 0;
}

void game(sf::RenderWindow* window){
    sf::Font font;
    font.loadFromFile("04B_30__.TTF");

    sf::Text score;
    score.setPosition(50, 50);
    score.setCharacterSize(35);
    score.setFont(font);

    BodyFull snake = BodyFull(1, BODY_SIZE, {X_SIZE / 2, Y_SIZE / 2});

    Food food = Food(ROWS, COLUMNS, BODY_SIZE);
    food.newPos();

    std::list<sf::Vector2<float>> piecesToAdd;

    unsigned int s = 0;

    sf::Vector2<float> offset = {0, 0};
    int frame = 0;
    bool keyPressed = false;
    sf::Vector2<float> tailPos;

    bool endGame = false;

    while (window->isOpen() && !endGame){
        sf::Event event{};
        while(window->pollEvent(event)){
            switch (event.type) {
                case sf::Event::Closed:{
                    // Put a confirmation window here
                    return;
                }

                case sf::Event::KeyPressed:{
                    keyPressed = true;
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                        if(equalPos(offset, {0, 50}))
                            break;
                        offset = {0, -50};
                    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                        if(equalPos(offset, {0, -50}))
                            break;
                        offset = {0, 50};
                    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                        if(equalPos(offset, {50, 0}))
                            break;
                        offset = {-50, 0};
                    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                        if(equalPos(offset, {-50, 0}))
                            break;
                        offset = {50, 0};
                    }
                }

                default:
                    break;
            }
        }
        window->clear();

        if ((frame % GAME_SPEED * 100  == 0) && keyPressed) {
            tailPos = snake.getPieces().end().operator--()->getPosition();
            for (std::_List_iterator<BodyPiece> it = snake.getPieces().end().operator--();
                 it != snake.getPieces().begin(); --it) {
                it->setPosition(std::prev(it)->getPosition());
            }
            if (!piecesToAdd.empty()){
                if(equalPos(tailPos, *piecesToAdd.begin())){
                    snake.addPiece(tailPos);
                    piecesToAdd.pop_front();
                }
            }
            snake.getPieces().begin()->move(offset);
        }

        if (checkFoodEaten(snake.getPieces(), food.getPosition())){
            s++;
            score.setString(std::to_string(s));

            piecesToAdd.emplace_back(food.getPosition());
            do{
                food.newPos();
            }while(!validFoodPos(food.getPosition(), snake.getPieces()));
        }

        if (checkCollision(snake.getPieces()) && keyPressed){
            endGame = true;
        }

        if (outOfBoundaries(snake.getPieces().begin()->getPosition())){
            endGame = true;
        }

        for(const auto & i : snake.getPieces()){
            window->draw(i);
        }
        window->draw(food);
        window->draw(score);

        frame++;

        if(endGame){
            window->clear(sf::Color::Black);
        }

        window->display();
    }
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

bool equalPos(sf::Vector2<float> p1, sf::Vector2<float> p2){
    return (p1.x == p2.x && p1.y == p2.y);
}

bool validFoodPos(sf::Vector2<float> foodPos, std::list<BodyPiece>& pieces){
    for(auto const &piece: pieces){
        if(equalPos(piece.getPosition(), foodPos))
            return false;
    }
    return true;
}
