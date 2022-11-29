#include<stdio.h>
#include<stdlib.h>

void swap(int * x, int *y){
    int temp = * x;
    *x = *y;
    *y = temp;
}


int partition(int A[], int l , int h){
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do{i++;}while(pivot >= A[i]);
        do{j--;}while(pivot < A[j]);

        if(i < j)
            swap(&A[i],&A[j]);
    } while (i < j);
    swap(&A[l],&A[j]);
    return j;
}
void quicksort(int arr[], int l , int h){
    if(l < h){
        int j = partition(arr, l, h);
        quicksort(arr, l , j);
        quicksort(arr, j+1, h);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {23, 82, 1, 38, 293, 4, 39};
    int n = sizeof(arr)/sizeof(int);
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n - 1; i++)
        printf("%d ", arr[i]);
    return 0;
}
