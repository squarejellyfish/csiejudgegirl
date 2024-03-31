#include <stdio.h>
#include <string.h>

typedef struct {
    char name[64];
    int selling;
} Author;

typedef struct {
    char name[64];
    char author[64];
} Book;

int main() {
    int m, n = 0;
    Book books[128];
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        char author[64], book_name[64];
        scanf(" %s %s", author, book_name);
        strcpy(books[n].name, book_name);
        strcpy(books[n++].author, author);
    }

    int o = 0;
    Author authors[128];
    for (int i = 0; i < 128; i++) authors[i].selling = 0;
    for (int i = 0; i < n; i++) { // for every books
        char book_name[64], author[64];
        int selling;
        scanf(" %s %d", book_name, &selling);
        for (int b = 0; b < n; b++) { // finding book's author
            if (strcmp(books[b].name, book_name) == 0) {
                strcpy(author, books[b].author);
                break;
            }
        }
        int found = 0;
        for (int a = 0; a < o; a++) { // adding selling
            if (strcmp(authors[a].name, author) == 0) {
                found = 1;
//                printf("%s's selling %d += %d\n", authors[a].name, authors[a].selling, selling);
                authors[a].selling += selling;
                break;
            }
        }
        if (!found) {
            strcpy(authors[o].name, author);
            authors[o++].selling += selling;
//            printf("%s, author: %s\n", books[i].name, books[i].author);
//            printf("%s's selling is now %d\n", authors[o-1].name, authors[o-1].selling);
        }
    }
    int maxi = 0;
    for (int i = 1; i < o; i++) {
        if (authors[i].selling > authors[maxi].selling) {
            maxi = i;
        } else if (authors[i].selling == authors[maxi].selling && strcmp(authors[i].name, authors[maxi].name) < 0) {
            maxi = i;
        }
    }
    printf("%s %d\n", authors[maxi].name, authors[maxi].selling);

    return 0;
}
