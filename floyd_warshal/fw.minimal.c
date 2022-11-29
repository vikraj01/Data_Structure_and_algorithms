#include <stdio.h>
#include <stdlib.h>
#define INF 839393
#define For(x) for (int x = 0; x < n; x++)
int main(int argc, char const *argv[])
{
    int n;
    int G[100][100];
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    For(i) For(j)
    {
        scanf("%d", &G[i][j]);
        G[i][j] = G[i][j] == 0 && i != j ? INF : G[i][j];
    }
    For(k) For(i) For(j) G[i][j] = G[i][k] + G[k][j] < G[i][j] ? G[i][k] + G[k][j] : G[i][j];
    For(i)
    {
        For(j)
            printf("%d\t", G[i][j]);
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
