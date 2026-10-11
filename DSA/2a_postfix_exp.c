#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MS 50

char postfix[50];

struct stack
{
    int top;
    int item[MS];
} s;

void push(int value)
{
    if(s.top == MS - 1)
    {
        printf("overflow\n");
    }
    else
    {
        s.item[++s.top] = value;
    }
}



int pop()
{
    if(s.top == -1)
    {
        printf("\n stack underflow");
        exit(0);
    }
    return s.item[s.top--];
}



int empty()
{
    if(s.top == -1)
        return 1;
    else
        return 0;
}



int operation(int a, int b, char c)
{
    switch(c)
    {
        case '^': return pow(a, b);
        case '*': return a * b;
        case '%': return a % b;
        case '/': return a / b;
        case '+': return a + b;
        case '-': return a - b;
    }
    return 0;
}



int evaluate()
{
    int i, a, b, ans, value;
    char symb;
    for(i = 0; postfix[i] != '\0'; i++)
    {
        symb = postfix[i];
        if(symb >= '0' && symb <= '9')
        {
            push(symb - '0');
        }
        else
        {
            a = pop();
            b = pop();
            value = operation(b, a, symb);
            push(value);
        }
    }
    ans = pop();
    return ans;
}



int main()
{
    int ans;
    s.top = -1;
    printf("Enter the postfix expression\n");
    fgets(postfix, sizeof(postfix), stdin);
    ans = evaluate();
    printf("The resultant ans is %d\n", ans);
    return 0;
}
