#include "locker.h"

void init(Lock *lock) {
    lock->locked = 0;
}

int lock(Lock *lock, int combination) {
    if (isLocked(lock)) {
        return -1;
    }
    if (combination < 0 || combination > 9999) return 10000;
    lock->combination = combination;
    lock->locked = 1;
    return combination;
}

int unlock(Lock *lock, int combination) {
    if (!isLocked(lock)) {
        return -1;
    }
    if (combination == lock->combination) {
        lock->locked = 0;
        return 0;
    } else {
        return 1;
    }
}

int isLocked(Lock *lock) {
    return (lock->locked) ? 1 : 0;
}
