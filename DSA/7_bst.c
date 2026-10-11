#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    int data;
    struct BST *lc, *rc;
} node;

node *create(node *root, int x)
{
    if(root == NULL)
    {
        node *p = malloc(sizeof(node));
        p->data = x;
        p->lc = p->rc = NULL;
        return p;
    }
    if(x < root->data)
        root->lc = create(root->lc, x);
    else if(x > root->data)
        root->rc = create(root->rc, x);
    return root;
}



void search(node *root, int key)
{
    if(root == NULL)
        printf("The key is not found\n");
    else if(key == root->data)
        printf("The key is found\n");
    else if(key < root->data)
        search(root->lc, key);
    else
        search(root->rc, key);
}



void inorder(node *r)
{
    if(r != NULL)
    {
        inorder(r->lc);
        printf("%d\t", r->data);
        inorder(r->rc);
    }
}



void preorder(node *r)
{
    if(r != NULL)
    {
        printf("%d\t", r->data);
        preorder(r->lc);
        preorder(r->rc);
    }
}



void postorder(node *r)
{
    if(r != NULL)
    {
        postorder(r->lc);
        postorder(r->rc);
        printf("%d\t", r->data);
    }
}



void traversal(node *root)
{
    int ch;
    do
    {
        printf("\n1.Inorder 2.Preorder 3.Postorder 4.Exit\nChoice: ");
        scanf("%d", &ch);
        if(ch == 1)
            inorder(root);
        else if(ch == 2)
            preorder(root);
        else if(ch == 3)
            postorder(root);
    } while(ch >= 1 && ch <= 3);
}



int main()
{
    node *root = NULL;
    int n, x, key, ch, i;
    while(1)
    {
        printf("\n1.Create 2.Search 3.Traversal 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                printf("Enter the elements: ");
                for(i = 0; i < n; i++)
                {
                    scanf("%d", &x);
                    root = create(root, x);
                }
                break;
            case 2:
                printf("Enter the element to be searched: ");
                scanf("%d", &key);
                search(root, key);
                break;
            case 3:
                traversal(root);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
