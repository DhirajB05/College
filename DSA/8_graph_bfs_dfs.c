#include <stdio.h>
#include <stdlib.h>

int a[10][10], v[10], u[10], n;
int q[10], front, rear;

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
    int m;
    u[s] = 1;
    q[++rear] = s;
    printf("Reachable officers from %d are:\n", s);
    while (front <= rear) {
        m = q[front++];
        for (int i = 1; i <= n; i++) {
            if (a[m][i] && !u[i]) {
                u[i] = 1;
                q[++rear] = i;
                printf("Officer %d\n", i);
            }
        }
    }
}



int main() {
    int s, ch;
    while (1) {
        printf("\n1.Create Graph 2.DFS 3.BFS 4.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter the number of officers: ");
            scanf("%d", &n);
            printf("Enter the adjacency matrix:\n");
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    scanf("%d", &a[i][j]);
        }
        else if (ch == 2 || ch == 3) {
            int *visited = (ch == 2) ? v : u;
            for (int i = 1; i <= n; i++)
                visited[i] = 0;
            printf("Enter Source Officer for %s: ",
                   ch == 2 ? "DFS" : "BFS");
            scanf("%d", &s);
            front = 0;
            rear = -1;
            if (ch == 2)
                dfs(s);
            else
                bfs(s);
            for (int i = 1; i <= n; i++)
                if (!visited[i])
                    printf("Officer %d is disconnected\n", i);
        }
        else if (ch == 4)
            exit(0);
        else
            printf("Invalid choice\n");
    }
}
