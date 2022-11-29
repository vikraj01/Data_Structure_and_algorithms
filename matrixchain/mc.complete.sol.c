#include <stdio.h>
#include <stdlib.h>
#define SIZE 7
int s[7][7];

int MatrixChainOrder(int p[], int n)
{
    int m[7][7];
    int i, j, k, d, q;

    for (i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (d = 2; d < n; d++)
    {
        for (i = 1; i < n - d + 1; i++)
        {
            j = i + d - 1;
            m[i][j] = 99999999;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    
    
    printf("DP Matrix\n");
    for (int i = 1; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    
    printf("S Matrix\n");
    for (int i = 1; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }

    return m[1][n - 1];
}

void print_chain(int s[SIZE][SIZE], int i, int j)
{
    if (i == j)
    {
        printf(" A%d ", i);
    }
    else
    {
        printf("(");
        print_chain(s, i, s[i][j]);
        print_chain(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main()
{
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(p) / sizeof(int);

    int min_mul = MatrixChainOrder(p, n);
    printf("Minimum = %d", min_mul);

    printf("\n");

    print_chain(s, 1, 6);

    return 0;
}