#include<stdio.h>
#define sz 7

int s[sz][sz] = {0};


void chain(int arr[sz]){
	int m[sz][sz] = {0};
	int j , q;
	for(int d = 0; d < sz - 1 ; d++){
		for(int i=0 ; i < sz - d ; i++){
			int min = 36666;
			j = d + i;
			for (int k = i; k <= j - 1 ; k++){
				q = m[i][k] + m[k+1][j] + arr[i-1]*arr[j]*arr[k];
				if ( q < min){
					min = q;
					s[i][j] = k;
				}
				m[i][j] = min;			
			}				
				
		}
	}
	printf(" %d \n",m[1][sz-1]);

	printf(" Matrix \n");
	for (int i = 1 ; i < sz; i++){
		for ( int j = i+1 ; j < sz ;j++) {
			printf("m[%d][%d] =  %d\n",i , j,  m[i][j]);
		}
		
	}
	
	printf(" S Matrix \n");
	for (int i = 1 ; i < sz; i++){
		for ( int j = i +1; j < sz ;j++) {
			printf("s[%d][%d] =  %d\n",i , j,  s[i][j]);
		}
		printf("\n");
	}
	
}


void print_chain(int s[sz][sz], int i , int j){
	if(i == j){
		printf("A%d",i);
	}else{
		printf("(");
		print_chain(s, i, s[i][j]);
		print_chain(s, s[i][j] + 1, j);
		printf(")");
	}
}

int main(){
	int arr[] = { 30, 35, 15, 5, 10, 20, 25 };
	chain(arr);
	print_chain(s,1,6);
	return 0;
	
}
