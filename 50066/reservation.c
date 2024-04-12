#include "reservation.h"
#include <stdlib.h>
#include <stdio.h>

int isValid(RoomStatus *room, int nP, int st, int et) {
    Reservation *pre = NULL, *cur = room->reservation;
    for (; cur != NULL; pre = cur, cur = cur->next) {
        if (et <= cur->StartTime) break;
        if (st < cur->EndTime) return 0;
    }
    Reservation *new = (Reservation*)malloc(sizeof(Reservation));
    new->nP = nP;
    new->StartTime = st;
    new->EndTime = et;
    if (!pre)
        room->reservation = new;
    else
        pre->next = new;

    new->next = cur;
    return 1;
}

int ReserveRoom(RoomStatus List[], int nR, int nP, int StartTime, int EndTime) {
    for (int i = 0; i < nR; i++) {
        RoomStatus curr = List[i];
        if (curr.capacity < nP) continue;
        if (isValid(&List[i], nP, StartTime, EndTime)) return 1;
    }
    return 0;
}
