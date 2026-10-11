#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Student
{
    char usn[10], name[25], dept[12], phone[11];
    float m1, m2, m3;
    struct Student *prev, *next;
};
typedef struct Student node;

int count(node *head)
{
    int n = 0;
    while(head != NULL)
    {
        n++;
        head = head->next;
    }
    return n;
}



node *getnode()
{
    node *p = malloc(sizeof(node));
    printf("Enter Student details\n");
    printf("USN:"); scanf("%s", p->usn);
    printf("Name:"); scanf("%s", p->name);
    printf("Department:"); scanf("%s", p->dept);
    printf("Phone NO:"); scanf("%s", p->phone);
    printf("Enter the 3 subject Marks:\n");
    scanf("%f%f%f", &p->m1, &p->m2, &p->m3);
    p->prev = p->next = NULL;
    return p;
}



node *create(node *head)
{
    node *p = getnode(), *q = head;
    if(head == NULL)
        return p;
    while(q->next != NULL)
        q = q->next;
    q->next = p;
    p->prev = q;
    return head;
}



node *insertfront(node *head)
{
    if(count(head) == MAX)
        printf("Insertion is not possible\n");
    else
    {
        node *p = getnode();
        p->next = head;
        if(head != NULL)
            head->prev = p;
        head = p;
    }
    return head;
}



node *insertrear(node *head)
{
    if(count(head) == MAX)
        printf("Insertion is not possible\n");
    else
        head = create(head);
    return head;
}



void display(node *head)
{
    node *p = head;
    if(p == NULL)
        printf("No data\n");
    else
    {
        printf("USN\tNAME\tDEPARTMENT\tPhoneNO\tMARKS1\tMARKS2\tMARKS3\tTOTAL\tAVERAGE\n");
        while(p != NULL)
        {
            float total = p->m1 + p->m2 + p->m3;
            printf("%s\t%s\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
                p->usn, p->name, p->dept, p->phone,
                p->m1, p->m2, p->m3, total, total / 3);
            p = p->next;
        }
    }
    printf("The number of nodes in list is %d\n", count(head));
}



node *deletefront(node *head)
{
    if(head == NULL)
        printf("No data\n");
    else
    {
        node *p = head;
        head = head->next;
        if(head != NULL)
            head->prev = NULL;
        free(p);
    }
    return head;
}



node *deleterear(node *head)
{
    if(head == NULL)
        printf("No data\n");
    else
    {
        node *p = head;
        while(p->next != NULL)
            p = p->next;
        if(p->prev == NULL)
            head = NULL;
        else
            p->prev->next = NULL;
        free(p);
    }
    return head;
}



int main()
{
    node *head = NULL;
    int ch, i, n;
    do
    {
        printf("\n*....STUDENT DATA....*\n");
        printf("1.Create\n2.Display\n3.Insert_Front\n");
        printf("4.Insert_Rear\n5.Delete_Front\n");
        printf("6.Delete_Rear\n7.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter number of Student\n");
                scanf("%d", &n);
                for(i = 0; i < n; i++)
                    head = create(head);
                break;
            case 2: display(head); break;
            case 3: head = insertfront(head); break;
            case 4: head = insertrear(head); break;
            case 5: head = deletefront(head); break;
            case 6: head = deleterear(head); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    } while(ch >= 1 && ch <= 6);
    return 0;
}
