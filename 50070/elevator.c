#include <stdio.h>
#include <stdlib.h>
#include "elevator.h"

struct Elevator {
    int curr;
    int u, d, F;
    int *visited;
    int last, count;
};

Elevator* newElevator(int u, int d, int F) {
    Elevator *ret = (Elevator*)malloc(sizeof(Elevator));
    ret->curr = 1;
    ret->u = u;
    ret->d = d;
    ret->F = F;
    ret->visited = (int*)malloc(sizeof(int)*(F + 1));
    for (int i = 1; i < F + 1; i++) ret->visited[i] = 0;
    ret->visited[1] = 1; // visit 1st floor
    ret->last = 0;
    ret->count = 0;
    return ret;
}

int up(Elevator* elevator) {
    int next = elevator->curr + elevator->u;
    if (next <= elevator->F) {
        elevator->curr = next;
        elevator->visited[next] = 1;
        elevator->count = 0;
        elevator->last = 0;
        return 1;
    }
    else {
        if (elevator->last == 1) { // if last is up
            elevator->count++;
            if (elevator->count > 3) return -1;
        } else { // last is down / nothing, restart streak
            elevator->last = 1;
            elevator->count = 1;
        }
        return 0;
    }
}

int down(Elevator* elevator) {
    int next = elevator->curr - elevator->d;
    if (next > 0) {
        elevator->curr = next;
        elevator->visited[next] = 1;
        elevator->count = 0;
        elevator->last = 0;
        return 1;
    }
    else { // invalid
        if (elevator->last == 2) { // if last is down
            elevator->count++;
            if (elevator->count > 3) return -1;
        } else { // last is up / nothing, restart streak
            elevator->last = 2;
            elevator->count = 1;
        }
        return 0;
    }
}

int visited(struct Elevator* elevator, int floor) {
    return elevator->visited[floor];
}

int getPosition(struct Elevator* elevator) {
    return elevator->curr;
}
