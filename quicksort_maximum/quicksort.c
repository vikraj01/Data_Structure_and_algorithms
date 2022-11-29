#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);

        do
        {
            j--;
        } while (A[j] > pivot);

        if (i < j)
            swap(&A[i], &A[j]);

    } while (i < j);

    swap(&A[l], &A[j]);
    return j;
}

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int j = partition(arr, l, h);
        quickSort(arr, l, j);
        quickSort(arr, j + 1, h);
    }
}

int main(int argc, char const *argv[])
{

    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, 10000}, i;
    int n = sizeof(A) / sizeof(A[0]);
    quickSort(A, 0, n - 1);
    for (i = 0; i < n - 1; i++)
        printf("%d ", A[i]);

    return 0;
}
