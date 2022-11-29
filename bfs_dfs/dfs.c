#include <stdio.h>
void dfs(int);
int stack[20];
int top = -1;
int adjmat[20][20];
int n;
int visit[20] = {0};
int main()
{
    int start;
    printf("enter no.of vertex");
    scanf("%d", &n);
    printf("enter adj mat :- ");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &adjmat[i][j]);

    printf("enter staring vertex :- ");
    scanf("%d", &start);
    visit[start] = 1;
    dfs(start);
    for (int i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            dfs(i);
        }
    }
}
void dfs(int start)
{
    printf("%d\t", start);
    for (int i = 1; i <= n; i++)
    {
        if (adjmat[start][i] && !visit[i])
        {
            // queue[rear]=i;
            stack[++top] = i;
            // rear++;
            visit[i] = 1;
        }
    }
    if (top > -1)
    {
        dfs(stack[top--]);
    }
}