#include<stdio.h>
#include<stdlib.h>

typedef struct st{
	int weight;
	int profit;
	int ratio;
	double index;
}Item;


void main(){
	Item item[10];
	int x;
	printf("Enter the no of items : ");
	scanf("%d",&x);
	
	printf("Enter the max weight : ");
	int max; scanf("%d",&max);

	for(int i = 0 ; i < x ; i++ ){
		printf("\n");
		item[i].index = 1;
		printf("Weight %d",i);
		scanf("%d",&item[i].weight);
		printf("Profit %d",i);
		scanf("%d",&item[i].profit);
		item[i].ratio = item[i].profit / item[i].weight;
	}

	// Sorting accordingly ration
	
	for(int i=0;i<x;i++)
	{
		for(int j=i+1;j<x;j++)
		{
			if(item[i].ratio<item[j].ratio)
			{
				item tempx=item[j];
				item[j]=item[i];
				item[i]=tempx;
			}
		}
	}

	for(int i = 0 ; i < x ; i++){
		printf("%d ",item[i].ratio);
		
	}

	

	

	

}
