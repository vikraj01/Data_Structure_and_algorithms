#include <stdio.h>
#include <stdlib.h>
#define S 7

// Algo For Undirected graph

typedef struct st
{
    int size;
    int front;
    int rear;
    int *q;
} Q;

Q que;
int V[S] = {0};

void enqueue(int x)
{
    if ((que.rear + 1) % que.size == que.front)
    {
        printf("que is full\n");
    }
    else
    {
        que.q[que.rear] = x;
        que.rear = (que.rear + 1) % que.size;
    }
}

int dequeue()
{
    int x = -1;
    // printf("%d %d ",que.rear, que.front);

    if (que.front != que.rear)
    {
        x = que.q[que.front];
        que.front = (que.front + 1) % que.size;
    }
    return x;
}

void bfs(int G[S][S], int s)
{
    V[s] = 1;
    enqueue(s);
    while (que.front != que.rear)
    {
        int d = dequeue();
        printf("%d\t", d+1);
        
        for (int i = 0; i < S; i++)
        {
            if (G[d][i] == 1 && V[i]==0)
            {
                V[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    // printf("Enter the size of vertex in array : ");
    // scanf("%d", &que.size);
    que.size = S + 1;
    que.q = (int *)malloc(sizeof(int) * que.size);
    // queue is ready to use : )

    // Valid for seven vertex array

    int G[S][S] = {
        {0, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0}};

    bfs(G,0);
    return 0;
}
