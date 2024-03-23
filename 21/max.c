#include "max.h"

int max(int array[5][5]) {
    int ret = array[0][0];
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) {
        if (array[i][j] > ret) ret = array[i][j];
    }
    return ret;
}
