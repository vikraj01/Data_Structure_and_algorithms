#include <stdio.h>
#include <stdlib.h>
#define V 3
#define INF 78838

void print_mat(int G[V][V])
{
	printf("\n");
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (G[i][j] == INF)
			{
				printf("%4s", "INF");
			}
			else
			{
				printf("%4d", G[i][j]);
			}
		}
		printf("\n");
	}
}

void floyd(int G[V][V])
{

	int mat[V][V];
	int path[V][V];
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			mat[i][j] = G[i][j];
			path[i][j] = -1;
		}
	}

	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (mat[i][k] + mat[k][j] < mat[i][j])
				{
					mat[i][j] = mat[i][k] + mat[k][j];
					path[i][j] = k;
				}
			}
		}
		print_mat(mat);
	}

	print_mat(path);

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (i != j)
			{
				if (path[i][j] != -1)
				{
					printf("%d -> %d -> %d : %d\n", i + 1, path[i][j] + 1, j + 1, mat[i][j]);
				}
				else if (mat[i][j] != -1)
				{
					printf("%d -> %d : %d\n", i + 1, j + 1, mat[i][j]);
				}
			}
		}
	}
}

void main()
{
	int G[V][V] = {{0, 4, 11}, {6, 0, 2}, {3, INF, 0}};
	print_mat(G);
	floyd(G);
}
