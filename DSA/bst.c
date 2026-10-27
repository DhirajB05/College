#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int data;
    struct BST *lc;
    struct BST *rc;
} node;

node *create(node *r, int x) {
    if (!r) {
        r = malloc(sizeof(node));
        if (!r) {
            exit(1);
        }
        r->data = x;
        r->lc = NULL;
        r->rc = NULL;
    } else if (x < r->data) {
        r->lc = create(r->lc, x);
    } else if (x > r->data) {
        r->rc = create(r->rc, x);
    }
    return r;
}

void search(node *r, int k) {
    if (!r) {
        puts("The key is not found");
    } else if (k == r->data) {
        puts("The key is found");
    } else if (k < r->data) {
        search(r->lc, k);
    } else {
        search(r->rc, k);
    }
}

void inorder(node *r) {
    if (r) {
        inorder(r->lc);
        printf("%d\t", r->data);
        inorder(r->rc);
    }
}

void preorder(node *r) {
    if (r) {
        printf("%d\t", r->data);
        preorder(r->lc);
        preorder(r->rc);
    }
}

void postorder(node *r) {
    if (r) {
        postorder(r->lc);
        postorder(r->rc);
        printf("%d\t", r->data);
    }
}

int main() {
    node *root = NULL;
    int ch, n, x, k, i, t;

    while (1) {
        printf("\n1.Create 2.Search 3.Traversal 4.Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter the number of elements: ");
            scanf("%d", &n);
            printf("Enter the elements: ");
            for (i = 0; i < n; i++) {
                scanf("%d", &x);
                root = create(root, x);
            }
        } else if (ch == 2) {
            printf("Enter the element to be searched: ");
            scanf("%d", &k);
            search(root, k);
        } else if (ch == 3) {
            do {
                printf("\n1.Inorder 2.Preorder 3.Postorder 4.Exit\nChoice: ");
                scanf("%d", &t);
                if (t == 1) {
                    inorder(root);
                } else if (t == 2) {
                    preorder(root);
                } else if (t == 3) {
                    postorder(root);
                }
            } while (t >= 1 && t <= 3);
        } else if (ch == 4) {
            return 0;
        } else {
            puts("Invalid choice");
        }
    }
}
