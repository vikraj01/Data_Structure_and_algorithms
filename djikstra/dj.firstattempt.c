#include <stdio.h>
#include <stdlib.h>
#define INF 19019

void dj(int G[100][100], int n, int s)
{
    int cost[100][100], dist[100], prev[100], visited[100];
    int next;

    // Creating cost matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (G[i][j] == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = G[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }

    // Get the starting vertex row, initialising visited array with 0 && previous array to starting vertex
    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[s][i];
        visited[i] = 0;
        prev[i] = s;
    }

    // Setting starting vertex distance to zero and marking as visited : )
    dist[s] = 0;
    visited[s] = 1;

    //
    for (int i = 1; i < n - 1; i++)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d\t", visited[i]);
        }
        printf("\n");

        for (int i = 0; i < n; i++)
        {
            printf("%d\t", dist[i]);
        }
        printf("\n");
        int min = INF;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && min > dist[i])
            {
                min = dist[i];
                next = i;
            }
        }

        printf("\nNextnode%d\n", next);

        visited[next] = 1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                if (min + cost[next][i] < dist[i])
                {
                    dist[i] = min + cost[next][i];
                    prev[i] = next;
                };
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the no of vertices: ");
    scanf("%d", &n);
    int G[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    dj(G, n, 0);

    return 0;
}
