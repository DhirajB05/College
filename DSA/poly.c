#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct poly {
    int cf;
    int x;
    int y;
    int z;
    int flag;
    struct poly *next;
} Node;

Node *getnode() {
    Node *p = malloc(sizeof(Node));
    if (!p) {
        exit(1);
    }
    p->flag = 0;
    p->next = p;
    return p;
}

void addterm(Node *h, int c, int x, int y, int z) {
    Node *p = getnode();
    Node *q = h;
    p->cf = c;
    p->x = x;
    p->y = y;
    p->z = z;
    while (q->next != h) {
        q = q->next;
    }
    q->next = p;
    p->next = h;
}

void display(Node *h) {
    Node *p = h->next;
    if (p == h) {
        puts("Polynomial is empty");
        return;
    }
    while (p != h) {
        printf("%dx^%dy^%dz^%d", p->cf, p->x, p->y, p->z);
        if (p->next != h) {
            printf(" + ");
        }
        p = p->next;
    }
    printf("\n");
}

void readpoly(Node *h) {
    int c, x, y, z, ch;
    h->next = h;
    do {
        printf("Enter coeff and powers of x, y, z (space-separated): ");
        scanf("%d%d%d%d", &c, &x, &y, &z);
        addterm(h, c, x, y, z);
        printf("Continue? (1 for Yes / 0 for No): ");
        scanf("%d", &ch);
    } while (ch != 0);
}

Node *sumPoly(Node *a, Node *b, Node *s) {
    Node *p;
    Node *q;
    int found;
    s->next = s;

    for (p = a->next; p != a; p = p->next) {
        found = 0;
        for (q = b->next; q != b; q = q->next) {
            if (p->x == q->x && p->y == q->y && p->z == q->z) {
                addterm(s, p->cf + q->cf, p->x, p->y, p->z);
                q->flag = 1;
                found = 1;
                break;
            }
        }
        if (!found) {
            addterm(s, p->cf, p->x, p->y, p->z);
        }
    }

    for (q = b->next; q != b; q = q->next) {
        if (!q->flag) {
            addterm(s, q->cf, q->x, q->y, q->z);
        }
        q->flag = 0;
    }

    return s;
}

void evaluate(Node *h) {
    int x, y, z;
    double ans = 0;

    printf("\nEnter x, y, z terms to evaluate: ");
    scanf("%d%d%d", &x, &y, &z);

    for (Node *p = h->next; p != h; p = p->next) {
        ans += p->cf * pow(x, p->x) * pow(y, p->y) * pow(z, p->z);
    }

    printf("Polynomial result is: %.2f\n", ans);
}

int main() {
    Node *a = getnode();
    Node *b = getnode();
    Node *s = getnode();
    int ch;

    while (1) {
        printf("\n--- Polynomial Operations ---\n1. Evaluate polynomial\n2. Add two polynomials\n3. Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("\nEnter polynomial:\n");
            readpoly(a);
            printf("The polynomial is: ");
            display(a);
            evaluate(a);
        } else if (ch == 2) {
            printf("\nEnter the first polynomial:\n");
            readpoly(a);
            printf("\nEnter the second polynomial:\n");
            readpoly(b);
            sumPoly(a, b, s);
            printf("\nFirst polynomial: ");
            display(a);
            printf("Second polynomial: ");
            display(b);
            printf("Sum of polynomials: ");
            display(s);
        } else if (ch == 3) {
            return 0;
        } else {
            puts("Invalid choice.");
        }
    }
}
