#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13,17,};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    int brr[] = {2 ,4, 6, 8, 10};
    int n2 = sizeof(brr) / sizeof(brr[0]);

    int n[100];
    int i = 0 , j = 0 , k = 0;
    while ( i < n1 && j < n2){
        if(arr[i] < brr[j]){
            n[k++] = arr[i++];
        }else{
            n[k++] = brr[j++];
        }
    }

    while( i < n1) n[k++] = arr[i++];
    while ( j < n2) n[k++] = brr[j++];

    for(  i = 0 ; i < k ; i++){
        printf("%d\t", n[i]);
    }

}
