// Write steps in your copy

#include<stdio.h>
#include<stdlib.h>
#define INF 100000

int main(int argc, char const *argv[])
{
    int G[100][100];
    printf("Enter the number of vertices : ");
    int n ;
    scanf("%d",&n);
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < n; j++){
            scanf("%d",&G[i][j]);
            if(G[i][j]==0 && i != j){
                G[i][j] = INF;   
            }
        }
    }

    // Djikstra part
    int visited[100] = {0}, dist[100] , prev[100];
    int s = 0 ;

    for(int i = 0 ; i < n; i++){
        dist[i] = G[s][i];
        prev[i] = s;
    }

    dist[s] = 0;
    visited[s] = 1;
    int next;

    for(int i = 0 ; i < n; i++){
        int min = INF;
        for(int i = 0 ; i < n ; i++){
            if(visited[i] == 0 && dist[i] < min){
                min = dist[i];
                next = i;
            }
        }
        printf("\n%d \n",next);
        visited[next] = 1;
        for(int i = 0; i < n ;i++){
            if(dist[next] + G[next][i] < dist[i]){
                dist[i] = dist[next] + G[next][i];
                prev[i] = next;
            }
        }
    }

    for(int i= 0 ; i < n; i++){
        printf("%d\t",dist[i]);
    }

    return 0;
}
