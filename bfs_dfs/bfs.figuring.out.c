#include <stdio.h>
#include <stdlib.h>

int queue[100] = {0};
int rear = 0;
int front = 0;

void BFS(int G[100][100], int s, int visited[], int n){
    visited[s] = 1;
    queue[rear++] = s;
    while(rear != front){
        int u = queue[front++];
        printf("%d\t",u);
        for(int i = 0 ; i < n ; i++){
            if(visited[i] == 0 && G[u][i] == 1){
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

}


void BFSDis(int G[100][100], int n){
    int visited[100]  = {0};
    for(int i = 0 ; i < n ;i++){
        if(visited[i] == 0){
            BFS(G, i, visited, n);
        }
    }
} 

int main(int argc, char const *argv[])
{
    int G[100][100];
    printf("Enter the number of vertices : ");
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    BFSDis(G, n);

    return 0;
}
