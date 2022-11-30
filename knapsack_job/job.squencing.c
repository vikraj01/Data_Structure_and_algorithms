#include <stdio.h>
#include <stdlib.h>
#define For(x) for (int i = 0; i < n; i++)
#define FOR(i) for (int j = 0; j < n - i - 1; j++)

typedef struct job
{
    char id;
    int dl;
    int p;
} Job;

int min(int x, int y)
{
    return x < y ? x : y;
}

void swap(Job *x, Job *y)
{
    Job t = *x;
    *x = *y;
    *y = t;
}

int main(int argc, char const *argv[])
{
    Job arr[] = {{'a', 2, 100},
                 {'b', 1, 19},
                 {'c', 2, 27},
                 {'d', 1, 25},
                 {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf(
        "Following is maximum profit sequence of jobs \n");

    For(i) FOR(j) if (arr[j].p < arr[j + 1].p) swap(&arr[j], &arr[j + 1]);

    // For(i) printf("\n%c %d %d\n", arr[i].id, arr[i].dl, arr[i].p);
    int slot[100] = {0}, result[100] = {0};

    For(i)
    {
        for (int j = min(n, arr[i].dl) - 1; j >= 0; j--)
        {
            if (slot[j] == 0)
            {
                result[j] = i;
                slot[j] = 1;
                break;
            }
        }
    }


    For(i) if(slot[i]) printf("%c ", arr[result[i]].id);

    return 0;
}
