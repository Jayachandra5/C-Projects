#include <stdio.h>
#include<stdlib.h>

#define SIZE 9


int matrix[9][9];

void readMatrix(int m[9][9])
{ 
    int i,j;
    
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
}
void print_sudoku()
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n\n");
    }
}


int number_unassigned(int *row, int *col)
{
    int num_unassign = 0;
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            
            if(matrix[i][j] == 0)
            {
                
                *row = i;
                *col = j;
                
                num_unassign = 1;
                return num_unassign;
            }
        }
    }
    return num_unassign;
}


int is_safe(int n, int r, int c)
{
    int i,j;
    
    for(i=0;i<SIZE;i++)
    {
        
        if(matrix[r][i] == n)
            return 0;
    }
   
    for(i=0;i<SIZE;i++)
    {
        
        if(matrix[i][c] == n)
            return 0;
    }
    
    int row_start = (r/3)*3;
    int col_start = (c/3)*3;
    for(i=row_start;i<row_start+3;i++)
    {
        for(j=col_start;j<col_start+3;j++)
        {
            if(matrix[i][j]==n)
                return 0;
        }
    }
    return 1;
}


int solve_sudoku()
{
    int row;
    int col;
    if(number_unassigned(&row, &col) == 0)
        return 1;
    int n,i;
    
    for(i=1;i<=SIZE;i++)
    {
        
        if(is_safe(i, row, col))
        {
            matrix[row][col] = i;
            
            if(solve_sudoku())
                return 1;
            
            matrix[row][col]=0;
        }
    }
    return 0;
}

int main()
{
  
    printf(" Welcome to sudoku slover!!\n\nThis will slove any sudoku puzzle !!\n");
    
    printf("\n\n Enter the sudoku puzzle by giveing spaces after ever digit and enter 0 for empty places.");
    printf("\npress enter for going to next line ");
    readMatrix(matrix);
    if (solve_sudoku())
        print_sudoku();
    else
        printf("The puzzle which you gave has no soluction. Try new puzzle with new input\n");
    return 0;
}