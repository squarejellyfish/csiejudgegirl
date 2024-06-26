#include <stdio.h>
#include <stdlib.h>
 
#define MAX 1000
 
int adj[MAX][MAX] = {0};
int visited[MAX] = {0};
int path[MAX] = {0};
 
int dfs(int n, int index, int depth) {
    if(n == depth) {
        if(adj[0][path[n-1]]) {
            return 1;
        }
        return 0;
    }
 
    int last = depth == 0 ? -1 : path[depth-1];
    for(int i=0;i<n;i++) {
        if(last!=-1 && (visited[i] || adj[last][i] == 0)) {
            continue;
        }
        if(depth == n-1 && adj[0][i] == 0) {
            continue;
        }
        path[depth] = i;
        visited[i] = 1;
        if(dfs(n, i, depth+1)) {
            return 1;
        }else {
            visited[i] = 0;
        }
    }
    return 0;
}
 
int main() {
    int n, e;
    scanf("%d%d", &n, &e);
    int a, b;
    for(int i=0;i<e;i++) {
        scanf("%d%d", &a, &b);
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
 
    if(dfs(n, 0, 0)) {
        for(int i=0;i<n;i++) {
            printf("%d ", path[i]);
        }
        printf("0\n");
    } else {
        printf("NO SOLUTION\n");
    }
}
