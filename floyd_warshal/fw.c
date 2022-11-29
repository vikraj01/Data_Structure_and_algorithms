#include <stdio.h>
#include <stdlib.h>
#define INF 839393
int main(int argc, char const *argv[])
{
    int G[100][100];
    printf("Enter the number of vertices : ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
            if (G[i][j] == 0 && i != j)
            {
                G[i][j] = INF;
            }
        }
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G[i][j] = G[i][k] + G[k][j] < G[i][j] ? G[i][k] + G[k][j] : G[i][j];


    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%d\t",G[i][j]);
        }
        printf("\n");
    }

    return 0;
}


/*
0 3 0 5
2 0 0 4
0 1 0 0
0 0 2 0

*/
