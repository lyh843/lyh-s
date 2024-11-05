#include<stdio.h>
#define N 12
#define M 12

int up(int arr[N][M], int row1, int col1, int row2, int col2)
{
    int judge = 0;
    for(int i = 1; row1 - i >= 0; i++)
    {
        judge += arr[row1 - i][col1];
    }
    for(int i = 1; row2 - i >= 0; i++)
    {
        judge += arr[row2 - i][col2];
    }
    if(judge == 0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
int down(int arr[N][M], int row1, int col1, int row2, int col2, int size_row)
{
    int judge = 0;
    for(int i = 1; row1 + i <= size_row; i++)
    {
        judge += arr[row1 + i][col1];
    }
    for(int i = 1; row2 + i <= size_row; i++)
    {
        judge += arr[row2 + i][col2];
    }
    if(judge == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int left(int arr[N][M], int row1, int col1, int row2, int col2)
{
    int judge = 0;
    for(int i = 1; col1 - i >= 0; i++)
    {
        judge += arr[row1][col1 - i];
    }
    for(int i = 1; col2 - i >= 0; i++)
    {
        judge += arr[row2][col2 - i];
    }
    if(judge == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int right(int arr[N][M], int row1, int col1, int row2, int col2, int size_col)
{
    int judge = 0;
    for(int i = 1; col1 + i <= size_col; i++)
    {
        judge += arr[row1][col1 + i];
    }
    for(int i = 1; col2 + i <= size_col; i++)
    {
        judge += arr[row2][col2 + i];
    }
    if(judge == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int arr[N][M] = {0};
    int arr2[N * M / 2 + 1][5] = {0};
    int size_row = 0, size_col = 0;
    int number = 0;
    scanf("%d%d", &size_row, &size_col);
    for(int i = 1; i <= size_row; i++)
    {
        for(int j = 1; j <= size_col; j++)
        {
            scanf("%d", &number);
            if(arr2[number][4] == 0)
            {
                arr2[number][0] = i;
                arr2[number][1] = j;
                arr2[number][4] = 1;
            }
            else if(arr2[number][4] == 1)
            {
                arr2[number][2] = i;
                arr2[number][3] = j;
            }
            arr[i][j] = number;
        }
    }
    int sum = size_row * size_col / 2;
    while(sum)
    {
        for(int i = 1; i <= size_col * size_row / 2; i++)
        {
            if(arr2[i][4] == 0)
            {
                continue;
            }
            else
            {
                int row1 = arr2[i][0];
                int col1 = arr2[i][1];
                int row2 = arr2[i][2];
                int col2 = arr2[i][3];
                if(up(arr, row1, col1, row2, col2) == 1)
                {
                    arr2[i][4] = 0;
                    arr[row1][col1] = 0;
                    arr[row2][col2] = 0;2
                    printf("%d ", i);
                    sum--;
                }
                else if(down(arr, row1, col1, row2, col2, size_row) == 1)
                {
                    arr2[i][4] = 0;
                    arr[row1][col1] = 0;
                    arr[row2][col2] = 0;
                    printf("%d ", i);
                    sum--;
                }
                else if(left(arr, row1, col1, row2, col2) ==1)
                {
                    arr2[i][4] = 0;
                    arr[row1][col1] = 0;
                    arr[row2][col2] = 0;
                    printf("%d ", i);
                    sum--;
                }
                else if(right(arr, row1, col1, row2, col2, size_col) == 1)
                {
                    arr2[i][4] = 0;
                    arr[row1][col1] = 0;
                    arr[row2][col2] = 0;
                    printf("%d ", i);
                    sum--;
                }
            }
        }
    }
}