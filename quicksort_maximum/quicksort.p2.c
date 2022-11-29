#include <stdio.h>
#include <stdlib.h>
void swap(int * x , int *y){
    int temp = * x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (pivot >= arr[i]);

        do
        {
            j--;
        } while (pivot < arr[j]);

        if (i < j)
            swap(&arr[i], &arr[j]);
    } while (i < j);

    swap(&arr[l], &arr[j]);
    return j;
}

void quicksort(int arr[], int l, int h)
{
    if (l < h)
    {
        int j = partition(arr, l, h);
        quicksort(arr, l, j);
        quicksort(arr, j + 1, h);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 3, 1, 56, 23, 9, 10, 4};
    int n = sizeof(arr)/sizeof(int);
    quicksort(arr, 0, n);
    for(int i = 0 ; i < n ; i++) printf("%d\n", arr[i]);
    return 0;


}
