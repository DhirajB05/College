#include <stdio.h>

int a[20];
int fr[20];
int n;

int main() {
    int i, j, c;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n && i < 20; i++) {
        scanf("%d", &a[i]);
    }

    n = (n < 20) ? n : 20;

    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n\nElement / Frequency\n-------------------\n");

    for (i = 0; i < n; i++) {
        if (fr[i]) {
            continue;
        }
        c = 1;
        for (j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                c++;
                fr[j] = 1;
            }
        }
        printf("%d | ", a[i]);
        for (j = 0; j < c; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
