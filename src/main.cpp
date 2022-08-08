#include <SFML/Graphics.hpp>
#include <thread>


int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "SnakeGame");
    sf::RectangleShape  rectangle({50, 100});
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(200, 200);

    auto rectangleRotate = [](sf::RectangleShape *shape){
        int i = 0;
        while (true){
            shape->rotate(i/100000);
            i++;
        }
    };

    std::thread first(rectangleRotate, &rectangle);


    while (window.isOpen()){
        sf::Event event{};
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(rectangle);
        window.display();
    }


    return 0;
}
