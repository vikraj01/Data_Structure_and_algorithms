#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {3, 45, 67, 98, 102, 333, 789, 999};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    int index = binarySearch(arr, n, key);
    if (index == -1)
    {
        printf("%d is not there", key);
    }
    else
    {
        printf("%d is found at place %d", key, index);
    }
    return 0;
}
