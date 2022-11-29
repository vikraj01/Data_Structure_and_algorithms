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

    // Loop goes from 1 to n - 1 but it won't hurt if it goes for  0 to n
    for (int i = 0; i < n; i++)
    {
        int min = INF;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && min > dist[i])
            {
                min = dist[i];
                next = i;
            }
        }
        visited[next] = 1;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                if (dist[next] + cost[next][i] < dist[i])
                {
                    dist[i] = dist[next] + cost[next][i];
                    prev[i] = next;
                };
            }
        }
    }

    // Printing the distance
    for (int i = 0; i < n; i++)
        if (i != s)
        {
            printf("\nDistance from source to %d: %d   %d", i, dist[i], prev[i]);
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
