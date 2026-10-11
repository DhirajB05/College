#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Employee
{
    char id[25], name[12], desig[10], branch[11], phone[10];
    struct Employee *next;
};
typedef struct Employee node;

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
    printf("Enter Employee details\n");
    printf("EMP_ID:"); scanf("%24s", p->id);
    printf("NAME:"); scanf("%11s", p->name);
    printf("DESIGNATION:"); scanf("%9s", p->desig);
    printf("BRANCH:"); scanf("%10s", p->branch);
    printf("Phone NO:"); scanf("%9s", p->phone);
    p->next = NULL;
    return p;
}



node *create(node *head)
{
    if(count(head) == MAX)
    {
        printf("List is overflow\n");
        return head;
    }
    node *p = getnode();
    p->next = head;
    return p;
}



node *insertfront(node *head)
{
    return create(head);
}



node *insertrear(node *head)
{
    if(count(head) == MAX)
    {
        printf("List is overflow\n");
        return head;
    }
    node *p = getnode();
    if(head == NULL)
        return p;
    node *q = head;
    while(q->next != NULL)
        q = q->next;
    q->next = p;
    return head;
}



node *deletefront(node *head)
{
    if(head == NULL)
        printf("No data\n");
    else
    {
        node *p = head;
        head = head->next;
        free(p);
    }
    return head;
}



node *deleterear(node *head)
{
    if(head == NULL)
        printf("No data\n");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *p = head;
        while(p->next->next != NULL)
            p = p->next;
        free(p->next);
        p->next = NULL;
    }
    return head;
}



void display(node *head)
{
    node *p = head;
    if(p == NULL)
        printf("No Employee data\n");
    else
    {
        printf("EMP_ID\tNAME\tDESIGNATION\tBRANCH\tPH_NO\n");
        while(p != NULL)
        {
            printf("%s\t%s\t%s\t%s\t%s\n",
                p->id, p->name, p->desig, p->branch, p->phone);
            p = p->next;
        }
    }
    printf("The number of nodes in list is %d\n", count(head));
}



node *insert(node *head)
{
    int ch;
    do
    {
        printf("\nMenu\n1.Insert front\n2.Insert rear\n3.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        if(ch == 1)
            head = insertfront(head);
        else if(ch == 2)
            head = insertrear(head);
        display(head);
    } while(ch == 1 || ch == 2);
    return head;
}



node *delete(node *head)
{
    int ch;
    do
    {
        printf("\nMenu\n1.Delete front\n2.Delete rear\n3.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        if(ch == 1)
            head = deletefront(head);
        else if(ch == 2)
            head = deleterear(head);
        display(head);
    } while(ch == 1 || ch == 2);
    return head;
}



node *stack(node *head)
{
    int ch;
    do
    {
        printf("\nMenu\n1.Insert front\n2.Delete front\n3.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        if(ch == 1)
            head = insertfront(head);
        else if(ch == 2)
            head = deletefront(head);
        display(head);
    } while(ch == 1 || ch == 2);
    return head;
}



int main()
{
    node *head = NULL;
    int ch, i, n;
    do
    {
        printf("\n*...EMPLOYEE DATA...*\n");
        printf("1.Create\n2.Display\n3.Insert\n4.Delete\n5.Stack\n6.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter number of Employees\n");
                scanf("%d", &n);
                for(i = 0; i < n; i++)
                    head = create(head);
                break;
            case 2: display(head); break;
            case 3: head = insert(head); break;
            case 4: head = delete(head); break;
            case 5: head = stack(head); break;
            case 6: return 0;
            default: printf("Invalid choice\n");
        }
    } while(ch >= 1 && ch <= 6);
    return 0;
}
