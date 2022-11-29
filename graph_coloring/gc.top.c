#include<stdbool.h>
#include <stdio.h>
int coloring[101],adj[100][100];
bool flag = false;
bool isPossible(int color,int node,int n)
{
    for(int i=0;i<n;i++)
    {
        if(adj[node][i]==1 && coloring[i] == color)
            return false;
    }
    return true;
}
void printColor(int n)
{
    printf("Colors\n ");
    for(int i=0;i<n;i++)
    {
        printf("Node: %d Color: %d\n",i,coloring[i]);
    }
}
void find(int node,int n,int m)
{
    if(node == n)
    {
        printColor(n);
        flag = true;
        return;
    }
    for(int color=1;color<=m;color++)
    {
        if(isPossible(color,node,n))
        {
            coloring[node]=color;
            find(node+1,n,m);
            coloring[node]=0;
        }
    }
    
}
int main()
{
    int n,m;
    printf("Enter the number of Nodes\n");
    scanf("%d",&n);
    printf("Enter the number of colors\n");
    scanf("%d",&m);
    printf("Enter the adj matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    find(0,n,m);
    if(!flag)
        printf("coloring is not possible\n");
    
    return 0;
}