#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


static inline int max(int a, int b){
    return ((a)>(b)?(a):(b));
}

int n;
int arr[100005] = {0};

int main(){
    scanf("%d", &n);
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF){
        if(b == 0){
            if(arr[a] - 1 > arr[a + 1] && arr[a] - 1 > arr[a + 2]){
                int s = arr[a];
                arr[a] = s + 1, arr[a + 1] = s + 1, arr[a + 2] = s;
            }
            else{
                int s = max(arr[a + 1], arr[a + 2]);
                arr[a] = s + 2, arr[a + 1] = s + 2, arr[a + 2] = s + 1;
            }
        }
        else if(b == 1){
            if(arr[a + 2] - 1 > arr[a] && arr[a + 2] - 1 > arr[a + 1]){
                int s = arr[a + 2];
                arr[a] = s, arr[a + 1] = s + 1, arr[a + 2] = s + 1;
            }
            else{
                int s = max(arr[a], arr[a + 1]);
                arr[a] = s + 1, arr[a + 1] = s + 2, arr[a + 2] = s + 2;
            }
        }
        else if(b == 2){
            int s = max(max(arr[a], arr[a + 1]), arr[a + 2]);
            arr[a] = s + 1, arr[a + 1] = s + 2, arr[a + 2] = s + 1;
        }
        else if(b == 3){
            if(arr[a] - arr[a + 1] < 1 && arr[a + 2] - arr[a + 1] < 1){
                int s = arr[a + 1];
                arr[a] = s + 2, arr[a + 1] = s + 2, arr[a + 2] = s + 2;
            }
            else{
                int s = max(arr[a], arr[a + 2]);
                arr[a] = s + 1, arr[a + 1] = s + 1, arr[a + 2] = s + 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' ');
    }

}

