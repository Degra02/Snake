#ifndef SNAKEGAME_POSITION_H
#define SNAKEGAME_POSITION_H


class Position {
private:
    int x;
    int y;

public:
    Position(int x, int y);
    void updatePos();
};

typedef Position* Pos;

#endif //SNAKEGAME_POSITION_H
