#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

char strs[64][16];

typedef struct {
    int leader, member[64], n;
} Group;

int cmp(const void *p1, const void *p2) {
    Group a = *(Group*)p1;
    Group b = *(Group*)p2;
    return strcmp(strs[a.leader], strs[b.leader]);
}

int dist(char s1[11], char s2[11], int m) {
    int ret = 0;
    for (int i = 0; i < m; i++) {
        ret += abs(s1[i] - s2[i]);
    }
    return ret;
}
int dist_mean(char s[11], int mean[11], int m) {
    int ret = 0;
    for (int i = 0; i < m; i++) {
        ret += abs(s[i] - mean[i]);
    }
    return ret;
}

int main() {
    int N, L, R;
    scanf("%d %d %d", &N, &L, &R);

    for (int n = 0; n < N; n++) {
        scanf(" %s", strs[n]);
    }

    Group groups[3];
    groups[0].leader = 0; groups[0].n = 0;
    groups[1].leader = 1; groups[1].n = 0;
    groups[2].leader = 2; groups[2].n = 0;
    for (int r = 0; r < R; r++) {
        for (int n = 0; n < N; n++) { // in strs
            int min = INT_MAX, mini;
            for (int g = 0; g < 3; g++) { // looking for a leader
                int d = dist(strs[groups[g].leader], strs[n], L);
                if (d < min) {
                    min = d;
                    mini = g;
                }
                else if (d == min && strcmp(strs[groups[g].leader], strs[groups[mini].leader]) < 0) {
                    mini = g;
                }
            }
//            printf("%s's leader is %s, mini = %d\n", strs[n], strs[groups[mini].leader], mini);
            groups[mini].member[groups[mini].n++] = n;
        }

        for (int g = 0; g < 3; g++) { // for every group mean
            int mean[16] = {0};
            Group this = groups[g];
            for (int i = 0; i < this.n; i++) { // for every member
                for (int l = 0; l < L; l++) { // for every char
                    mean[l] += strs[this.member[i]][l];
                }
            }
            for (int l = 0; l < L; l++) {
                mean[l] /= this.n;
            }
            int min = INT_MAX, mini;
            for (int i = 0; i < this.n; i++) { // for every member
                int d = dist_mean(strs[this.member[i]], mean, L);
                if (d < min) {
                    min = d;
                    mini = this.member[i];
                } else if (d == min && strcmp(strs[this.member[i]], strs[mini]) < 0) {
                    mini = this.member[i];
                }
            }

            groups[g].leader = mini;
            groups[g].n = 0;
        }
    }
    qsort(groups, 3, sizeof(Group), cmp);
    printf("%s\n%s\n%s\n", strs[groups[0].leader], strs[groups[1].leader], strs[groups[2].leader]);

    return 0;
}
