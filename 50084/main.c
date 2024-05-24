#include <stdio.h>
#include <limits.h>

typedef struct Job {
    int arrive, n, finished;
    int task[512][2];
} Job;

int mac[512] = {0};
Job jobs[512];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int m = 0; m < M; m++) {
        int Q;
        Job job;
        scanf("%d %d", &job.arrive, &Q);
        job.n = Q;
        job.finished = 0;
        for (int q = 0; q < Q; q++) {
            scanf("%d %d", &job.task[q][0], &job.task[q][1]);
        }
        jobs[m] = job;
    }

    while (1) {
        Job *selection;
        int earliest = INT_MAX, chosenmac;
        for (int m = 0; m < M; m++) {
            if (jobs[m].finished < jobs[m].n) {
                int mi = jobs[m].task[jobs[m].finished][0], time = jobs[m].task[jobs[m].finished][1];
                int comptime = (jobs[m].arrive <= mac[mi]) ? mac[mi] + time : jobs[m].arrive + time;
                if (comptime < earliest) {
                    earliest = comptime;
                    selection = &jobs[m];
                    chosenmac = mi;
                }
            }
        }
        if (earliest == INT_MAX) break;
        mac[chosenmac] = earliest;
        selection->finished++;
        selection->arrive = earliest;
//        printf("schedule job to machine %d, its arrive is now %d\n",chosenmac, selection->arrive);
    }
    for (int i = 0; i < M; i++) {
        printf("%d\n", jobs[i].arrive);
    }

    return 0;
}
