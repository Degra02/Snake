#ifndef SNAKEGAME_BOARDLOGIC_H
#define SNAKEGAME_BOARDLOGIC_H


#include "BodyFull.h"

class BoardLogic {
private:
    BodyFull snake;


public:
    const int size = 20;
    BoardLogic* buildBoard();
};


#endif //SNAKEGAME_BOARDLOGIC_H
