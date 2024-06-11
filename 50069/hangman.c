#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "hangman.h"
struct Hangman {
   int L, G, g, guessed[26];
   char answer[128];
};
Hangman* newGame(char * answer, int G) {
    Hangman *ret = (Hangman*)malloc(sizeof(Hangman));
    int l = strlen(answer);
    ret->L = l;
    ret->G = G;
    ret->g = 0;
    for (int i = 0; i < 26; i++) ret->guessed[i] = 0;
    strcpy(ret->answer, answer);
    return ret;
}
int guess(Hangman* hangman, char ch) {
    for (int i = 0; i < hangman->L; i++) {
        if (hangman->answer[i] == ch) {
            if (!hangman->guessed[ch - 'a']) 
                hangman->guessed[ch - 'a'] = 1;
            return 1;
        }
    }
    hangman->g++;
    if (hangman->g >= hangman->G) return -1;
    else return 0;
}
void printStatus(Hangman* hangman) {
    for (int i = 0; i < hangman->L; i++) {
        if (hangman->guessed[hangman->answer[i] - 'a']) printf("%c", hangman->answer[i]);
        else printf("*");
    }
    printf("\n");
}
int solved(Hangman* hangman) {
    for (int i = 0; i < hangman->L; i++) {
        if (!hangman->guessed[hangman->answer[i] - 'a']) {
            return 0;
        }
    }
    return 1;
}
