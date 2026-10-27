#include <stdio.h>
#include <stdlib.h>

#define MS 50

char in[MS];
char post[MS];
char st[MS];
int top = -1;

void push(char c) {
    if (top == MS - 1) {
        printf("The stack is overflow\n");
        exit(1);
    }
    st[++top] = c;
}

char pop() {
    if (top < 0) {
        printf("stack underflow\n");
        exit(1);
    }
    return st[top--];
}

int prec(char c) {
    if (c == '^') {
        return 3;
    }
    if (c == '*' || c == '/' || c == '%') {
        return 2;
    }
    if (c == '+' || c == '-') {
        return 1;
    }
    if (c == '(') {
        return 0;
    }
    return -1;
}

int main() {
    int i;
    int k = 0;
    char c, t;

    printf("Enter the infix expression :\n");
    fgets(in, sizeof(in), stdin);

    for (i = 0; in[i] != '\0' && in[i] != '\n'; i++) {
        c = in[i];
        if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top >= 0 && (t = pop()) != '(') {
                post[k++] = t;
            }
        } else if (prec(c) > 0) {
            while (top >= 0 && prec(st[top]) >= prec(c)) {
                post[k++] = pop();
            }
            push(c);
        } else {
            post[k++] = c;
        }
    }

    while (top >= 0) {
        post[k++] = pop();
    }
    post[k] = '\0';

    printf("The postfix expression is:\n%s\n", post);
    return 0;
}
