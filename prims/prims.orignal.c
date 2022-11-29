#include <stdio.h>
#define V 5
#define I 100000

int minkey(int val[], int mstset[])
{
    int minimum = I;
    int vertex;
    for (int i = 0; i < V; i++)
    {
        if (mstset[i] == 0 && val[i] < minimum)
        {
            minimum = val[i];
            vertex = i;
        }
    }
    return vertex;
}

void findMST(int graph[V][V])
{
    int mstset[V] = {0}, value[V], parent[V] = {0};
    for (int i = 0; i < V; i++)
    {
        value[i] = I;
    }
    value[0] = 0;
    parent[0] = -1;

    {
        int u = minkey(value, mstset);
        mstset[u] = 1;
        printf("u = %d\n", u);

        for (int i = 0; i < V ; i++)
        {
            if (graph[u][i] != 0 && mstset[i] == 0 && graph[u][i] < value[i])
            {
                value[i] = graph[u][i];
                parent[i] = u;  
            }
        }
    }

    for (int i = 1; i < V; ++i)
        printf("%d -> %d\n", parent[i], i);
}

int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    findMST(graph);

    return 0;
}