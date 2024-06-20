#include <stdio.h>
#include <string.h>

int main() {
    int T;
    int table[26][26] = {0};

    char word[128];
    scanf("%d", &T);
    while (scanf(" %s", word) != EOF) {
        int len = strlen(word);
        for (int i = 0; i < len - 1; i++) {
            table[word[i] - 'a'][word[i + 1] - 'a']++;
        }
    }

    char result[32], a, b;
    int used[26] = {0}, curr = 1, max = -1;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (table[i][j] > max) {
                max = table[i][j]; a = i + 'a'; b = j + 'a';
            }
        }
    }
    result[0] = a; result[1] = b;
    used[a - 'a'] = 1; used[b - 'a'] = 1;

    while (1) {
        int next = -1;
        max = -1;
        for (int i = 0; i < 26; i++) {
            int count = table[result[curr] - 'a'][i];
            if (count > T && !used[i] && count > max) {
                max = count;
                next = i;
            } 
//                printf("%c after %c doesn't fit used = %d, max = %d, count = %d, T = %d\n", i + 'a', result[curr], used[i], max, count, T);
        }
        if (next == -1) break;
        result[curr + 1] = next + 'a';
        used[next] = 1;
        curr++;
    }
    result[curr + 1] = '\0';

    for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) printf("%d%c", table[i][j], " \n"[j==25]);
    printf("%s\n", result);

    return 0;
}
