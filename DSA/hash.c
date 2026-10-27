#include <stdio.h>
#include <stdlib.h>

int *ht;
int m;
int n;
int c;

void display() {
    printf("The hash table is:\n");
    for (int i = 0; i < m; i++) {
        printf("%d -> %d\n", i, ht[i]);
    }
}

void insert(int key) {
    int j = key % m;
    int start = j;

    while (ht[j] != -1) {
        j = (j + 1) % m;
        if (j == start) {
            puts("The hash table is full");
            return;
        }
    }

    if (j != key % m) {
        puts("Collision detected and solved using linear probing.");
    }

    ht[j] = key;
    c++;
    display();
}

int main() {
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    printf("Enter the memory size: ");
    scanf("%d", &m);

    if (m <= 0) {
        return 1;
    }

    ht = malloc(m * sizeof(int));
    if (!ht) {
        return 1;
    }

    for (int i = 0; i < m; i++) {
        ht[i] = -1;
    }

    for (int i = 0; i < n && c < m; i++) {
        int key;
        printf("\nEnter the key: ");
        scanf("%d", &key);
        insert(key);
    }

    if (c == m && n > c) {
        puts("The hash table is full");
    }

    free(ht);
    return 0;
}
