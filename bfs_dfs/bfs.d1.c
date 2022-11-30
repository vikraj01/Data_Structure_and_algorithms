#include <stdio.h>
#include <stdlib.h>
#define For(i) for (int i = 0; i < n; i++)

int queue[100] = {0};
int rear = 0;
int front = 0;

void bfs(int G[100][100], int visited[], int s, int n)
{
    visited[s] = 1;
    queue[rear++] = s;
    while (front != rear)
    {
        int u = queue[front++];
        printf("%d\t", u + 1);
        For(i) if (visited == 0 && G[u][i] == 1)
        {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }
}

void BFSDis(int G[100][100], int n)
{
    int visited[100] = {0};
    bfs(G, visited, 3, n);
    For(i) if (visited[i] == 0)
        bfs(G, visited, i, n);
}

int main(int argc, char const *argv[])
{
    int G[100][100] = {0};

    printf("Enter the number of vertices: ");
    int n;
    scanf("%d", &n);
    For(i) For(j) scanf("%d", &G[i][j]);
    BFSDis(G, n);

    return 0;
}
