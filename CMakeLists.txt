cmake_minimum_required(VERSION 3.22)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics audio system window)

add_executable(SnakeGame src/main.cpp src/Logic/BodyPiece.cpp src/Logic/Position.cpp
        src/Logic/BoardLogic.cpp src/Logic/BodyFull.cpp src/Logic/Direction.cpp include/Direction.h src/GUI/BoardGui.cpp include/BoardGui.h src/Logic/PowerUp.cpp include/PowerUp.h)

target_link_libraries(SnakeGame -lsfml-window -lsfml-graphics -lsfml-system)