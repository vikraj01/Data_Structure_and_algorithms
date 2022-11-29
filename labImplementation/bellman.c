#include <stdio.h>
#define INT_MAX 100000

void BellmanFord(int graph[][3], int V, int E,
                 int src)
{
    int dis[V];
    int prev[V];
    for (int i = 0; i < V; i++)
    {
        dis[i] = INT_MAX;
        prev[i] = 0;
    }
    dis[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {

        for (int j = 0; j < E; j++)
        {

            if (dis[graph[j][0]] != INT_MAX && dis[graph[j][0]] + graph[j][2] <
                                                   dis[graph[j][1]])
            {
                dis[graph[j][1]] =
                    dis[graph[j][0]] + graph[j][2];
                prev[graph[j][1]] = graph[j][0];
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        int arr[30];

        printf("path of vertex %d:\n", i + 1);
        i = 0;
        arr[0] = i + 1;
        printf("%d-", i + 1);
        int temp_index = i;
        while (temp_index != 0)
        {

            printf("%d-", prev[temp_index] + 1);
            temp_index = prev[temp_index];
        }
        printf("\n");
    }

    for (int i = 0; i < E; i++)
    {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if (dis[x] != INT_MAX && dis[x] + weight < dis[y])
            printf("Graph contains negative weight cycle");
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("1-%d \t\t %d\n", i + 1, dis[i]);

    printf("Predecessor array:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", prev[i]);
}

int main()
{
    int V = 7;
    int E = 10;

    int graph[][3] = {{0, 1, 6}, {0, 2, 5}, {0, 3, 5}, {2, 1, -2}, {3, 2, -2}, {1, 4, -1}, {2, 4, 1}, {3, 5, -1}, {4, 6, 3}, {5, 6, 3}};

    BellmanFord(graph, V, E, 0);
    return 0;
}




// https://stackoverflow.com/questions/20371647/how-to-get-the-actual-path-found-by-bellman-ford
// For finding the path
