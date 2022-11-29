#include <stdio.h>
#include <stdlib.h>
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int n[100];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            n[k++] = arr[i++];
        else
            n[k++] = arr[j++];
    }

    while (i <= mid)
        n[k++] = arr[i++];
    while (j <= high)
        n[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = n[i];
}

void mergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 37, 21, 32, 53, 27, 34, 384, 21, 100, 191, 12};
    // int brr[] = { 1, 3, 5 , 7 , 9 , 2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
    // merge(brr, 0 , 4, 9);
    // printArray(brr, 10);

    return 0;
}
