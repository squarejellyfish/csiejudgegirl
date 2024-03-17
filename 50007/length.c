void init(int length[3]) {
    length[0] = 0;
    length[1] = 0;
    length[2] = 0;
}
void add(int length[3], int i) {
    length[2] += i;
    if (length[2] > 11) {
        length[1] += length[2] / 12;
        length[2] %= 12;
    }
    if (length[1] > 2) {
        length[0] += length[1] / 3;
        length[1] %= 3;
    }
}
void sum(int lengtha[3], int lengthb[3], int lengthc[3]) {
    lengthc[0] = lengtha[0] + lengthb[0];
    lengthc[1] = lengtha[1] + lengthb[1];
    lengthc[2] = lengtha[2] + lengthb[2];
    if (lengthc[2] > 11) {
        lengthc[1] += lengthc[2] / 12;
        lengthc[2] %= 12;
    }
    if (lengthc[1] > 2) {
        lengthc[0] += lengthc[1] / 3;
        lengthc[1] %= 3;
    }
}
void diff(int lengtha[3], int lengthb[3], int lengthc[3]) {
    lengtha[1] += lengtha[0]*3;
    lengtha[0] = 0;
    lengtha[2] += lengtha[1]*12;
    lengtha[1] = 0;
    lengthb[1] += lengthb[0]*3;
    lengthb[0] = 0;
    lengthb[2] += lengthb[1]*12;
    lengthb[1] = 0;
    lengthc[0] = 0;
    lengthc[1] = 0;
    lengthc[2] = lengtha[2] - lengthb[2];
    if (lengthc[2] > 11) {
        lengthc[1] += lengthc[2] / 12;
        lengthc[2] %= 12;
    }
    if (lengthc[1] > 2) {
        lengthc[0] += lengthc[1] / 3;
        lengthc[1] %= 3;
    }
}
