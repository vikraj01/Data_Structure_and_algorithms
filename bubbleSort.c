#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void l(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n)
{

    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int main(int argc, char const *argv[])
{

    int arr[100];
    for (int i = 0; i < 100; i++)
        arr[i] = rand() % 100;


    bubbleSort(arr, 100);
    l(arr, 100);

    return 0;
}
