#include<stdio.h>

void merge(int A[], int low , int mid, int high){

	int i = low , j = mid+1, k = low, B[100];
	while( i <= mid && j <= high ){
		if(A[i] < A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	//for(int i  = low ; i <= high; i++)
	//	printf("%d\t",B[i]);
	
	while( i <= mid )
		B[k++] = A[i++];
	while( j <= high )
		B[k++] = A[j++];

	for(  i = low ; i <= high ; i++)
		A[i] = B[i];
}

void mergeSort(int arr[], int low, int high){
	int mid;
	if(low < high) {
		mid = ( low + high ) / 2;
		mergeSort(arr, low,mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low , mid , high);
	}
}

void main(){
	int arr[] = {1,3,5,7,9,2,4,6,8,10};
	mergeSort(arr, 0, 9);
	for(int i = 0; i < 10; i++)
		printf("%d\t",arr[i]);
		
		

}
