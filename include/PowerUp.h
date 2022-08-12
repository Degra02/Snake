#ifndef SNAKEGAME_POWERUP_H
#define SNAKEGAME_POWERUP_H


class PowerUp {
private:
    int* coordinates;

public:
    PowerUp();
    explicit PowerUp(const int* coordinates);
    void newCoords();
};


#endif //SNAKEGAME_POWERUP_H
