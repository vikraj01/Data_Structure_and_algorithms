#include<stdio.h>
#define N 8

void printSolution(int board[][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf(" %d ",board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int board[][N],int row,int col){
    int i,j,k;
    for(int i=0;i<col;i++){
        if(board[row][i]) return 0;
    }
    //upper left corner
    for(i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]) return 0;
    }
    //lower left corner
    for(i=row,j=col;i<N && j>=0;i++,j--){
        if(board[i][j]) return 0;
    }
    return 1;
}

int check(int board[N][N],int col)
{
    if(col>=N){
        return 1;
    }

    for(int i=0;i<N;i++)
    {
        if(isSafe(board,i,col)){
            board[i][col]=1;
            if(check(board,col+1))return 1;
            board[i][col]=0;
        }
    }
    return 0;
}

void queenCheck(int board[N][N])
{
    if(check(board,0)==0)
    {
        printf("There is no solution");
    }
    else{
        printf("The solution is:\n");
    }
}

int main()
{
    int board[N][N]={0};
    queenCheck(board);
    printSolution(board);
    return 0;
}
