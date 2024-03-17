#ifndef _ARRAY_H
#define _ARRAY_H
 
typedef struct ARRAY {
    int arr[2048];
    int isset[2048];
    int startidx;
    int endidx;
} ARRAY;

void init(ARRAY *a,  int left, int right);
int set(ARRAY *a, int index, int value);
int get(ARRAY *a, int index);
void print(ARRAY *a);
void sort(ARRAY *a); 
 
#endif
