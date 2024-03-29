#include "SpiralSnake.h"
#include <stdio.h>

void SpiralSnake(int N, int *snake, int *result)
{
    int pos[2] = {N / 2, N / 2};
    int dir = 0;
    int dirXY[2][4] = {{0, -1, 0, 1}, {-1, 0, 1, 0}};

    result[N * pos[0] + pos[1]] = snake[0];
    int step = 1, dumstep = step, step_count = 0;
    for (int i = 1; i < N * N; i++)
    {
        pos[0] += dirXY[0][dir];
        pos[1] += dirXY[1][dir];
//        printf("(%d, %d) is %d\n", pos[0], pos[1], snake[i]);
        result[N * pos[0] + pos[1]] = snake[i];
        dumstep--;

        if (dumstep == 0)
        {
            step_count++;
            if (step_count == 2)
            {
                step_count = 0;
                step++;
            }
            dir = (dir + 1) % 4;
            dumstep = step;
        }
    }
}
