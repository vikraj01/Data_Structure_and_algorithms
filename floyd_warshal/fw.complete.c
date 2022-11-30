#include<stdio.h>
#include<stdlib.h>
#define nv 3
#define max 99999
void printmatrix(int matrix[][nv]){
    for(int i=0;i<nv;i++){
        for(int j=0;j<nv;j++){
            if(matrix[i][j] == max)
                printf("%4s","INF");
            else
                printf("%4d",matrix[i][j]);
        }
        printf("\n");
    }
}
void floyd(int graph[][nv]){
    int matrix[nv][nv],mat[nv][nv] = {0};
    for(int i=0;i<nv;i++){
        for(int j=0;j<nv;j++){
            matrix[i][j] = graph[i][j];
        }
    }
    for(int k=0;k<nv;k++){
        for(int i=0;i<nv;i++){
            for(int j=0;j<nv;j++){
                if(matrix[i][k]+matrix[k][j] < matrix[i][j]){
                    mat[i][j] = k+1;
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
        printmatrix(matrix);
        printf("\n\n");
    }
    for(int i=0;i<nv;i++){
        for(int j=0;j<nv;j++){
            if(i != j){
                printf("%d ->",i+1);
                if(mat[i][j] != 0){
                    printf("%d ->",mat[i][j]);
                }
                printf("%d: ",j+1);
                printf(" %d\n",matrix[i][j]);
            }
        }
    }
}
int main(){
    int graph[nv][nv] = {
        {0, 4, 11},
        {6, 0, 2},
        {3, max, 0},
    };
    floyd(graph);
    return 0;
}
