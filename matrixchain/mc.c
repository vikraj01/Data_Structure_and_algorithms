#include <stdio.h>
#include <stdlib.h>
#define SZ 6
#define INF 789989

int min(int a, int b)
{
    return a < b ? a : b;
}

void mc(int arr[])
{
    int dp[SZ][SZ] = {0};

    for (int gap = 2; gap < SZ; gap++)
    {
        for (int i = 1; i + gap - 1 < SZ; i++)
        {
            int j = i + gap - 1;
            dp[i][j] = INF;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
            }
        }
    }
    for (int i = 0; i < SZ; i++)
    {
        for (int j = 0; j < SZ; j++)
            printf("%d\t", dp[i][j]);
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {4, 10, 3, 12, 20, 7};
    int n = sizeof(arr) / sizeof(int);

    mc(arr);
    return 0;
}
