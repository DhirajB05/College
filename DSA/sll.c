#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Employee {
    char id[25];
    char name[12];
    char desig[10];
    char branch[11];
    char phone[15];
    struct Employee *next;
} node;

int count(node *h) {
    int n = 0;
    while (h) {
        n++;
        h = h->next;
    }
    return n;
}

node *getnode() {
    node *p = malloc(sizeof(node));
    if (!p) {
        exit(1);
    }
    printf("Enter Employee details\nEMP_ID:");
    scanf("%24s", p->id);
    printf("NAME:");
    scanf("%11s", p->name);
    printf("DESIGNATION:");
    scanf("%9s", p->desig);
    printf("BRANCH:");
    scanf("%10s", p->branch);
    printf("Phone NO:");
    scanf("%14s", p->phone);
    p->next = NULL;
    return p;
}

node *create(node *h) {
    if (count(h) == MAX) {
        puts("List is overflow");
        return h;
    }
    node *p = getnode();
    p->next = h;
    return p;
}

node *rear(node *h) {
    if (count(h) == MAX) {
        puts("List is overflow");
        return h;
    }
    node *p = getnode();
    node *q = h;
    if (!h) {
        return p;
    }
    while (q->next) {
        q = q->next;
    }
    q->next = p;
    return h;
}

node *delFront(node *h) {
    if (!h) {
        puts("No data");
        return h;
    }
    node *p = h;
    h = h->next;
    free(p);
    return h;
}

node *delRear(node *h) {
    if (!h) {
        puts("No data");
        return h;
    }
    if (!h->next) {
        free(h);
        return NULL;
    }
    node *p = h;
    while (p->next->next) {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
    return h;
}

void display(node *h) {
    if (!h) {
        puts("No Employee data");
    } else {
        printf("EMP_ID\tNAME\tDESIGNATION\tBRANCH\tPH_NO\n");
        for (node *p = h; p != NULL; p = p->next) {
            printf("%s\t%s\t%s\t%s\t%s\n",
                p->id,
                p->name,
                p->desig,
                p->branch,
                p->phone);
        }
    }
    printf("The number of nodes in list is %d\n", count(h));
}

node *insert(node *h, int mode) {
    int ch;
    do {
        if (mode == 1) {
            printf("\nMenu\n1.Insert front\n2.Insert rear\n3.Exit\n");
        } else if (mode == 2) {
            printf("\nMenu\n1.Delete front\n2.Delete rear\n3.Exit\n");
        } else {
            printf("\nMenu\n1.Insert front\n2.Delete front\n3.Exit\n");
        }

        printf("Enter your choice\n");
        scanf("%d", &ch);

        if (mode == 1) {
            if (ch == 1) {
                h = create(h);
            } else if (ch == 2) {
                h = rear(h);
            }
        } else if (mode == 2) {
            if (ch == 1) {
                h = delFront(h);
            } else if (ch == 2) {
                h = delRear(h);
            }
        } else {
            if (ch == 1) {
                h = create(h);
            } else if (ch == 2) {
                h = delFront(h);
            }
        }
        display(h);
    } while (ch == 1 || ch == 2);

    return h;
}

int main() {
    node *h = NULL;
    int ch, n, i;

    do {
        printf("\n\t*...EMPLOYEE DATA...*\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.Stack\n6.Exit\nEnter your choice\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter number of Employees\n");
                scanf("%d", &n);
                for (i = 0; i < n && count(h) < MAX; i++) {
                    h = create(h);
                }
                break;
            case 2:
                display(h);
                break;
            case 3:
                h = insert(h, 1);
                break;
            case 4:
                h = insert(h, 2);
                break;
            case 5:
                h = insert(h, 3);
                break;
            case 6:
                return 0;
            default:
                puts("Invalid choice");
        }
    } while (ch >= 1 && ch <= 6);

    return 0;
}
