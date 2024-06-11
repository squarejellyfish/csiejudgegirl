#include <stdio.h>
#include <string.h>
#include "hangman.h"

int main() {
    int N;
    scanf("%d", &N);
    for (int _ = 0; _ < N; _++) {
        char word[128], guesses[256];
        int G;
        scanf(" %s %d %s", word, &G, guesses);
        Hangman *game = newGame(word, G);

        int glen = strlen(guesses), quit = 1;
        for (int i = 0; i < glen; i++) {
            int stat = guess(game, guesses[i]);
            printf("%d ", stat);
            printStatus(game);
            if (stat == -1) {
                quit = 0;
                printf("You Lose\n");
                break;
            }
            if (solved(game)) {
                quit = 0;
                printf("You Win\n");
                break;
            }
        }
        if (quit) printf("You Quit\n");
    }
    return 0;
}
