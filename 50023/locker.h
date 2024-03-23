#ifndef _LOCKER_H
#define _LOCKER_H
 
/*
    define structure Lock
*/
typedef struct {
    int locked;
    int combination;
} Lock;
 
void init(Lock *lock);
int lock(Lock *lock, int combination);
int unlock(Lock *lock, int combination);
int isLocked(Lock *lock);
#endif
