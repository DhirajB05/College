#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MS 50

char post[MS];
int st[MS];
int top = -1;

void push(int x) {
    if (top == MS - 1) {
        printf("overflow\n");
        exit(1);
    }
    st[++top] = x;
}

int pop() {
    if (top < 0) {
        printf("\n stack underflow");
        exit(1);
    }
    return st[top--];
}

int op(int a, int b, char c) {
    switch (c) {
        case '^':
            return (int)pow(a, b);
        case '*':
            return a * b;
        case '%':
            return a % b;
        case '/':
            return a / b;
        case '+':
            return a + b;
        case '-':
            return a - b;
    }
    return 0;
}

int main() {
    int i, a, b;

    printf("Enter the postfix expression\n");
    fgets(post, sizeof(post), stdin);

    for (i = 0; post[i] != '\0' && post[i] != '\n'; i++) {
        char c = post[i];
        if (c >= '0' && c <= '9') {
            push(c - '0');
        } else {
            a = pop();
            b = pop();
            push(op(b, a, c));
        }
    }

    printf("The resultant ans is %d\n", pop());
    return 0;
}
