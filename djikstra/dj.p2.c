#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 89837
#define For(x) for (int x = 0; x < n; x++)

int main(int argc, char const *argv[])
{
    printf("Enter the number of vertices : ");
    int n;
    scanf("%d", &n);
    int G[100][100];
    For(i)
        For(j)
    {
        scanf("%d", &G[i][j]);
        G[i][j] = G[i][j] == 0 && i != j ? INF : G[i][j];
    }

    // ------------------------ LOGIC --------------------- //

    int visited[100] = {100}, dist[100], prev[100], s = 0, next;
    For(i)
    {
        dist[i] = G[s][i];
        prev[i] = s;
    }
    dist[s] = 0;
    visited[s] = 1;

    For(i)
    {
        int min = INF;

        For(j)
        {
            if (visited[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                next = j;
            }
        }

        visited[next] = 1;

        For(k)
        {

            if (dist[next] + G[next][k] < dist[k])
            {
                dist[k] = dist[next] + G[next][k];
                prev[next] = k;
            }
        }
    }

    For(t) printf("%d\t", dist[t]);
    return 0;
}
