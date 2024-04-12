#include "car.h"
#include <stdlib.h>

CarStatusList carSimulation(CarStatus car, Command commands[]) {
    CarStatusList ret = *(CarStatusList*)malloc(sizeof(CarStatusList));
    ret.num = 0;

    int i = 0;
    while (commands[i].t != 0) {
        Command curr = commands[i];
        int cmd = commands[i].t;
        if (cmd == 1) {
            car.g += curr.v;
        } else {
            if (car.g < curr.v) break;
            if (cmd == 2) {
                car.x += curr.v;
                car.g -= curr.v;
            } else if (cmd == 3) {
                car.x -= curr.v;
                car.g -= curr.v;
            } else if (cmd == 4) {
                car.y += curr.v;
                car.g -= curr.v;
            } else if (cmd == 5) {
                car.y -= curr.v;
                car.g -= curr.v;
            } else break;

            ret.status[ret.num++] = car;
        }
        i++;
    }

    return ret;
}
