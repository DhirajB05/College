#include <stdio.h>
#include <stdlib.h>

int a[10][10];
int v[10];
int n;
int q[10];
int f;
int r;

void dfs(int s) {
    v[s] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[s][i] && !v[i]) {
            printf("Officer %d -> Officer %d\n", s, i);
            dfs(i);
        }
    }
}

void bfs(int s) {
    int x;
    v[s] = 1;
    q[++r] = s;
    printf("Reachable officers from %d are:\n", s);
    while (f <= r) {
        x = q[f++];
        for (int i = 1; i <= n; i++) {
            if (a[x][i] && !v[i]) {
                v[i] = 1;
                q[++r] = i;
                printf("Officer %d\n", i);
            }
        }
    }
}

int main() {
    int ch, s;

    while (1) {
        printf("\n1.Create Graph 2.DFS 3.BFS 4.Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter the number of officers: ");
            scanf("%d", &n);
            printf("Enter the adjacency matrix:\n");
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    scanf("%d", &a[i][j]);
                }
            }
        } else if (ch == 2 || ch == 3) {
            for (int i = 1; i <= n; i++) {
                v[i] = 0;
            }
            printf("Enter Source Officer for %s: ", (ch == 2) ? "DFS" : "BFS");
            scanf("%d", &s);
            f = 0;
            r = -1;
            if (ch == 2) {
                dfs(s);
            } else {
                bfs(s);
            }
            for (int i = 1; i <= n; i++) {
                if (!v[i]) {
                    printf("Officer %d is disconnected\n", i);
                }
            }
        } else if (ch == 4) {
            return 0;
        } else {
            puts("Invalid choice");
        }
    }
}
