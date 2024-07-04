#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define is_op(c) (((c) == '+') || ((c) == '-') || ((c) == '*') || ((c) == '/'))
#define is_dig(c) (((c) >= '0') && ((c) <= '9'))
#define max(a,b) ((a)>(b)?(a):(b))

typedef struct{
    int is_valid;
    int val;
    int next_idx;
} info;

int n;
char s[1000005];

info eval_num(int start){
    int ans = 0;
    while(is_dig(s[start]) && start < n){
        ans = ans * 10 + (s[start] - '0');
        start++;
    }
    return (info) {1, ans, start};
}

info solve(int start){
    info l, r; char op;
    if(s[start] == '('){
        start++;
        if(is_dig(s[start])){
            l = eval_num(start);
            op = s[l.next_idx];
            if(!is_dig(s[l.next_idx + 1])) return (info) {0, 0, 0};
            r = eval_num(l.next_idx + 1);
        }
        else if(s[start] == '('){
            l = solve(start);
            op = s[l.next_idx];
            if(s[l.next_idx + 1] != '(') return (info) {0, 0, 0};
            r = solve(l.next_idx + 1);
        }
    }
    else{
        return (info) {0, 0, 0};
    }

    if((!l.is_valid) || (!r.is_valid) || (!is_op(op)) || (s[r.next_idx]) != ')'){
        return (info) {0, 0, 0};
    }

    if(op == '+') return (info) {1, l.val + r.val, r.next_idx + 1};
    if(op == '-') return (info) {1, l.val - r.val, r.next_idx + 1};
    if(op == '*') return (info) {1, l.val * r.val, r.next_idx + 1};
    if(op == '/') return (info) {1, l.val / r.val, r.next_idx + 1};
}

int main(){
    while(scanf("%s", s) != EOF){
        n = strlen(s);
        info rtv = solve(0);
        if(rtv.is_valid == 1 && rtv.next_idx == n) printf("%d\n", rtv.val);
        else printf("invalid\n");
    }
}

