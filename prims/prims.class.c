/*
0 3 2 0 0 0
3 0 0 1 0 0
2 0 0 2 0 3
0 1 2 0 4 4
0 0 0 4 0 2
0 0 3 4 2 0
*/
#include<stdio.h>
#include<stdlib.h>
#define max 20
#define inf 999999
int g[max][max],span[max][max],n;
int prims();
int main(){
	printf("Enter number of vertices:- ");
	scanf("%d",&n);
	printf("Enter Adjacency matrix :- \n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&g[i][j]);
	int total_cost = prims();
	printf("\nTotal cost of spanning tree is :- %d",total_cost);
	return 0;
}
int prims(){
	int cost[max][max],distance[max],from[max],visited[max],min_cost = 0;
	int u,v,min_dist,no_of_edge = n-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(g[i][j] == 0)
				cost[i][j] = inf;
			else
				cost[i][j] = g[i][j];
			span[i][j] = 0;
		}
	}
	distance[0] = 0;
	visited[0] = 1;
	for(int i=1;i<n;i++){
		distance[i] = cost[0][i];
		from[i] = 0;
		visited[i] = 0;
	}
	while(no_of_edge > 0){
		min_dist = inf;
		for(int i=1;i<n;i++){
			if(visited[i]==0 && distance[i] < min_dist){
				min_dist = distance[i];
				v = i;
			}
		}
		u = from[v];
		span[u][v] = distance[v];
		printf("(%d, %d)\t",u+1,v+1);
		span[v][u] = distance[v];
		no_of_edge--;
		visited[v] = 1;
		for(int i=1;i<n;i++){
			if(visited[i]==0 && distance[i] > cost[i][v]){
				distance[i] = cost[i][v];
				from[i] = v;
			}
		}
		min_cost += cost[u][v];
	}
	return min_cost;
}