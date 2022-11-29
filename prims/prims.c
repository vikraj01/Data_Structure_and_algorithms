#include <stdio.h>
#include <stdlib.h>
#define For(x) for (int x = 0; x < n; x++)
#define INF 1009938
int main(int argc, char const *argv[])
{
    int G[100][100] = {0};
    printf("Enter the number of vertices : ");
    int n;
    scanf("%d", &n);
    For(i) For(j) scanf("%d", &G[i][j]);

    // ---------------------------------------------- Logic ---------------------------------------//
    int visited[100] = {0}, value[100] = {0}, prev[100] = {0}, s = 0;
    For(i) value[i] = INF;

    value[s] = 0;
    prev[0] = -1;

    For(i)
    {
        int min = INF;
        int next;
        For(k)
        {
            if (visited[k] == 0 && value[i] < min)
            {
                min = value[i];
                next = i;
            }
        }

        visited[next] = 1;

        For(j)
        {
            if (G[next][j] && visited[j] == 0 && G[next][j] < value[j])
            {
                prev[j] = next;
                value[j] = G[next][j];
            }
        }
    }



    //------------------------ Printing edges -----------------------------//

    For(i)
        printf("%d - %d  %d\n", prev[i], i , G[i][prev[i]]);

    return 0;
}
