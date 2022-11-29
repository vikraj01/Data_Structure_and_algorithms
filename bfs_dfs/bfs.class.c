#include <stdio.h>
void bfs(int);
int queue[20];
int rear = 0;
int front = 0;
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
	bfs(start);
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			bfs(i);
		}
	}
}
void bfs(int start)
{
	printf("%d\t", start);
	for (int i = 1; i <= n; i++)
	{
		if (adjmat[start][i] && !visit[i])
		{
			queue[rear] = i;
			rear++;
			visit[i] = 1;
		}
	}
	if (front < rear)
	{
		bfs(queue[front++]);
	}
}