#include <stdio.h>

void merge(int A[], int B[], int* a[], int* b[]){
    int i = 0, j = 0;
    int size_a = 0, size_b = 0;
    while(a[size_a] != NULL) size_a++;
    while(b[size_b] != NULL) size_b++;
    size_a++, size_b++;

    int** ptr;
    if(A[0] < B[0]){
        ptr = &(a[0]);
        i++;
    }
    else{
        ptr = &(b[0]);
        j++;
    }

    while(i < size_a && j < size_b){
        if(A[i] < B[j]){
            *ptr = &(A[i]);
            ptr = &a[i];
            i++;
        }
        else{
            *ptr = &(B[j]);
            ptr = &b[j];
            j++;
        }
    }
    while(i < size_a){
        *ptr = &(A[i]);
        ptr = &a[i];
        i++;
    }
    while(j < size_b){
        *ptr = &(B[j]);
        ptr = &b[j];
        j++;
    }
}

