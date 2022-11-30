
#include <stdio.h>
#define For(i) for (int i = 0; i < n; i++)

int G[10][10], visited[10] = {0}, n;

void DFS(int i)
{
    int j;
    printf("\n%d", i);
    visited[i] = 1;
    For(j) if (!visited[j] && G[i][j] == 1) DFS(j);
}
void main()
{
    int i, j;
    printf("Enter number of vertices:");
    scanf("%d", &n);
    printf("\nEnter adjecency matrix of the graph:");

    For(i) For(j) scanf("%d", &G[i][j]);
    For(i) if (visited[i] == 0) DFS(i);
}
