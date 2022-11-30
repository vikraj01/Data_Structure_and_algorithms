#include <stdio.h>
#define For(i) for (int i = 0; i < n; i++)

int stack[100] = {0};
int top = 0;

void dfs(int G[100][100], int visited[], int s, int n)
{
    visited[s] = 1;
    stack[top++] = s;

    while (top > -1)
    {
        int u = stack[top--];
        printf("%d\t", u);
        For(i) if (visited[i] == 0 && G[u][i] == 1)
        {
            stack[top++] = i;
        }
    }
}

int main(int argc, char const *argv[])
{
    int G[100][100] = {0};

    printf("Enter the number of vertices: ");
    int n;
    scanf("%d", &n);
    For(i) For(j) scanf("%d", &G[i][j]);

    return 0;
}
