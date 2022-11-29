#include<stdio.h>

int binary(int arr[], int key, int low, int high){
	int mid;
	while( low <= high){
		 mid = (high + low ) / 2;
		if ( key == arr[mid] )
			return mid;
		else if ( key > arr[mid])
			low = mid + 1;
		else 
			high = mid - 1;
	}
	return -1;
}




void merge(int A[], int low , int mid, int high){

	int i = low , j = mid+1, k = low, B[100];
	while( i <= mid && j <= high ){
		if(A[i] < A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	
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
	
	
	int arr[100];
	int n;
	scanf("%d",&n);
	
	for(int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
		
	mergeSort(arr, 0, n - 1);
	for( int i = 0 ; i < n ; i++)
		printf("%d\t",arr[i]);
	printf("key : ");
	int x;
	scanf("%d",&x);
	int index = binary( arr, x, 0 , n-1);
	printf("index : %d",index);

}
