#include <stdio.h>
#include <stdlib.h>

int *ht, c = 0, n, m;

void display() {
    printf("The hash table is:\n");
    for (int i = 0; i < m; i++)
        printf("%d -> %d\n", i, ht[i]);
}



void insert(int key) {
    int j = key % m, flag = 0;
    while (ht[j] != -1) {
        j = (j + 1) % m;
        flag = 1;
    }
    if (flag)
        printf("Collision detected and solved using linear probing.\n");
    ht[j] = key;
    c++;
    display();
}



int main() {
    printf("Enter the number of keys: ");
    scanf("%d", &n);
    printf("Enter the memory size: ");
    scanf("%d", &m);
    ht = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        ht[i] = -1;
    for (int i = 0; i < n && c < m; i++) {
        int key;
        printf("\nEnter the key: ");
        scanf("%d", &key);
        insert(key);
    }
    if (c == m && n > c)
        printf("The hash table is full\n");
    free(ht);
    return 0;
}
