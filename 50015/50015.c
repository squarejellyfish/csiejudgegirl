#include <stdio.h>
#include <string.h>

int rule[26][26] = {{0}}, count[26] = {0};
char word[64];
int len;

void dfs(int step) {
    if (step == len) {
        word[step] = '\0';
        printf("%s\n", word);
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (!count[i]) continue;
        if (step > 0 && rule[word[step - 1] - 'a'][i] == 1) continue;
        word[step] = i + 'a';
        count[i]--;
        dfs(step + 1);
        count[i]++;
    }
}

int main() {
    int n;
    scanf("%s %d", word, &n);
    len = strlen(word);
    for (int i = 0; i < len; i++) {
        count[word[i] - 'a']++;
    }
    for (int i = 0; i < n; i++) {
        char foo, bar;
        scanf(" %c%c", &foo, &bar);
        rule[foo - 'a'][bar - 'a'] = 1;
    }
    dfs(0);
    return 0;
}
