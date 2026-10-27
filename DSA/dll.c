#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Student {
    char usn[10];
    char name[25];
    char dept[12];
    char phone[11];
    float m1, m2, m3;
    struct Student *prev;
    struct Student *next;
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
    printf("Enter Student details\nUSN:");
    scanf("%9s", p->usn);
    printf("Name:");
    scanf("%24s", p->name);
    printf("Department:");
    scanf("%11s", p->dept);
    printf("Phone NO:");
    scanf("%10s", p->phone);
    printf("Enter the 3 subject Marks:\n");
    scanf("%f%f%f", &p->m1, &p->m2, &p->m3);
    p->prev = NULL;
    p->next = NULL;
    return p;
}

node *create(node *h) {
    if (count(h) == MAX) {
        puts("Insertion is not possible");
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
    p->prev = q;
    return h;
}

node *front(node *h) {
    if (count(h) == MAX) {
        puts("Insertion is not possible");
        return h;
    }
    node *p = getnode();
    p->next = h;
    if (h) {
        h->prev = p;
    }
    return p;
}

void display(node *h) {
    if (!h) {
        puts("No data");
    } else {
        printf("USN\tNAME\tDEPARTMENT\tPhoneNO\tMARKS1\tMARKS2\tMARKS3\tTOTAL\tAVERAGE\n");
        for (node *p = h; p != NULL; p = p->next) {
            float t = p->m1 + p->m2 + p->m3;
            printf("%s\t%s\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
                p->usn,
                p->name,
                p->dept,
                p->phone,
                p->m1,
                p->m2,
                p->m3,
                t,
                t / 3);
        }
    }
    printf("The number of nodes in list is %d\n", count(h));
}

node *delFront(node *h) {
    if (!h) {
        puts("No data");
        return h;
    }
    node *p = h;
    h = h->next;
    if (h) {
        h->prev = NULL;
    }
    free(p);
    return h;
}

node *delRear(node *h) {
    if (!h) {
        puts("No data");
        return h;
    }
    node *p = h;
    while (p->next) {
        p = p->next;
    }
    if (p->prev) {
        p->prev->next = NULL;
    } else {
        h = NULL;
    }
    free(p);
    return h;
}

int main() {
    node *h = NULL;
    int ch, n, i;

    do {
        printf("\n*....STUDENT DATA....*\n1.Create\n2.Display\n3.Insert_Front\n4.Insert_Rear\n5.Delete_Front\n6.Delete_Rear\n7.Exit\nEnter your choice\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter number of Student\n");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    h = create(h);
                }
                break;
            case 2:
                display(h);
                break;
            case 3:
                h = front(h);
                break;
            case 4:
                h = create(h);
                break;
            case 5:
                h = delFront(h);
                break;
            case 6:
                h = delRear(h);
                break;
            case 7:
                exit(0);
            default:
                puts("Invalid choice");
        }
    } while (ch >= 1 && ch <= 6);

    return 0;
}
