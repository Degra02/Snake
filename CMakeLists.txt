cmake_minimum_required(VERSION 3.22)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics audio system window)

add_executable(SnakeGame src/main.cpp src/BodyPiece.cpp
        src/BoardLogic.cpp src/BodyFull.cpp src/Food.cpp include/Food.h)

target_link_libraries(SnakeGame -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio)