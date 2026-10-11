#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct poly
{
    int cf, px, py, pz, flag;
    struct poly *next;
} Node;

Node *getnode()
{
    Node *p = malloc(sizeof(Node));
    if(p == NULL)
        exit(1);
    p->flag = 0;
    p->next = p;
    return p;
}



void insert_rear(int c, int x, int y, int z, Node *h)
{
    Node *p = getnode(), *q = h;
    p->cf = c;
    p->px = x;
    p->py = y;
    p->pz = z;
    while(q->next != h)
        q = q->next;
    q->next = p;
    p->next = h;
}



void display(Node *h)
{
    Node *p = h->next;
    if(p == h)
    {
        printf("Polynomial is empty\n");
        return;
    }
    while(p != h)
    {
        printf("%dx^%dy^%dz^%d", p->cf, p->px, p->py, p->pz);
        if(p->next != h)
            printf(" + ");
        p = p->next;
    }
    printf("\n");
}



Node *read_poly(Node *h)
{
    int c, x, y, z, ch;
    h->next = h;
    do
    {
        printf("Enter coeff and powers of x, y, z (space-separated): ");
        scanf("%d%d%d%d", &c, &x, &y, &z);
        insert_rear(c, x, y, z, h);
        printf("Continue? (1 for Yes / 0 for No): ");
        scanf("%d", &ch);
    } while(ch != 0);
    return h;
}



Node *add_poly(Node *h1, Node *h2, Node *h3)
{
    Node *p, *q;
    int found;
    h3->next = h3;
    for(p = h1->next; p != h1; p = p->next)
    {
        found = 0;
        for(q = h2->next; q != h2; q = q->next)
        {
            if(p->px == q->px && p->py == q->py && p->pz == q->pz)
            {
                insert_rear(p->cf + q->cf, p->px, p->py, p->pz, h3);
                q->flag = 1;
                found = 1;
                break;
            }
        }
        if(!found)
            insert_rear(p->cf, p->px, p->py, p->pz, h3);
    }
    for(q = h2->next; q != h2; q = q->next)
    {
        if(!q->flag)
            insert_rear(q->cf, q->px, q->py, q->pz, h3);
        q->flag = 0;
    }
    return h3;
}



void evaluate(Node *h)
{
    int x, y, z;
    double sum = 0;
    Node *p = h->next;
    printf("\nEnter x, y, z terms to evaluate: ");
    scanf("%d%d%d", &x, &y, &z);
    while(p != h)
    {
        sum += p->cf * pow(x, p->px) * pow(y, p->py) * pow(z, p->pz);
        p = p->next;
    }
    printf("Polynomial result is: %.2f\n", sum);
}



int main()
{
    Node *h1 = getnode(), *h2 = getnode(), *h3 = getnode();
    int ch;
    while(1)
    {
        printf("\n--- Polynomial Operations ---\n");
        printf("1. Evaluate polynomial\n2. Add two polynomials\n3. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);
        if(ch == 1)
        {
            printf("\nEnter polynomial:\n");
            read_poly(h1);
            printf("The polynomial is: ");
            display(h1);
            evaluate(h1);
        }
        else if(ch == 2)
        {
            printf("\nEnter the first polynomial:\n");
            read_poly(h1);
            printf("\nEnter the second polynomial:\n");
            read_poly(h2);
            add_poly(h1, h2, h3);
            printf("\nFirst polynomial: ");
            display(h1);
            printf("Second polynomial: ");
            display(h2);
            printf("Sum of polynomials: ");
            display(h3);
        }
        else if(ch == 3)
            break;
        else
            printf("Invalid choice.\n");
    }
    return 0;
}
