#include "../../include/Direction.h"

int* Direction::offsetValue() {
    static int d[2];
    switch (this->dir) {
        case UP:{
            d[0] = 0; d[1] = -20;
            return d;
        }

        case DOWN:{
            d[0] = 0; d[1] = 20;
            return d;
        }

        case LEFT:{
            d[0] = -1; d[1] = 0;
            return d;
        }

        case RIGHT:{
            d[0] = 1; d[1] = 0;
            return d;
        }
    }
    return 0;
}
