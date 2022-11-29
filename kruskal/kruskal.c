#include <stdio.h>
#include <string.h>
#define I 2000
#define C 20

typedef struct st
{
    int v1;
    int v2;
    int c;
} Edge;

Edge edge[C];
int set[C];
int included[C] = {0};
Edge result[C];

void join(int p1, int p2)
{
    if (set[p1] < set[p2])
    {
        set[p1] = set[p1] + set[p2];
        set[p2] = p1;
    }
    else
    {
        set[p2] = set[p2] + set[p1];
        set[p1] = p2;
    }
}

int find(int x)
{
    int temp = x;
    while (set[temp] > 0)
        temp = set[temp];
    return temp;
}

void printResult(int v)
{
    for (int i = 0; i < v; i++)
        printf("%d edge , v1 = %d && v2 = %d \n", i, result[i].v1, result[i].v2);
}

void kruskal(int edges, int vertices)
{
    int i = 0, j, k, min, u, v;
    while (i < vertices - 1)
    {
        min = I;
        for (j = 0; j < edges; j++)
        {
            if (included[j] == 0 && edge[j].c < min)
            {
                min = edge[j].c;
                k = j;
                u = edge[j].v1;
                v = edge[j].v2;
            }
        }
        if (find(u) != find(v))
        {
            result[i].v1 = u;
            result[i].v2 = v;
            join(find(u), find(v));
            i++;
        }
        included[k] = 1;
    }
    printResult(v);
}

int main(int argc, char const *argv[])
{
    int e, v;
    printf("Enter the no. of edges in the graph: ");
    scanf("%d", &e);
    printf("Enter the no. of vertices in the graph: ");
    scanf("%d", &v);
    for (int i = 0; i < e; i++)
    {
        scanf("%d%d%d", &edge[i].v1, &edge[i].v2, &edge[i].c);
    }

    memset(set, -1, (v + 2) * sizeof(set[0]));

    kruskal(e, v);

    return 0;
}

/*
1 2 25
1 6 5
2 3 12
2 7 10
3 4 8
4 5 16
4 7 14
5 6 20
5 7 18
*/
