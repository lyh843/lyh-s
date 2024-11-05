#include<stdio.h>
#define N 10
#define M 10

int up(int arr[N][M], int row1, int col1, int row2, int col2)
{
    int judge = 0;
    for(int j = 1; row1 - j > 0; j++)
    {
        judge += arr[row1 - j][col1];
    }
    for(int j = 1; row2 - j > 0; j++)
    {
        judge += arr[row2 - j][col2];
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
int down(int arr[N][M], int row1, int col1, int row2, int col2, int n)
{
    int judge = 0;
    for(int j = 1; row1 + j < n + 1; j++)
    {
        judge += arr[row1 + j][col1];
    }
    for(int j = 1; row2 + j < n + 1; j++)
    {
        judge += arr[row2 + j][col2];
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
    for(int j = 1; col1 - j > 0; j++)
    {
        judge += arr[row1][col1 - j];
    }
    for(int j = 1; row2 - j > 0; j++)
    {
        judge += arr[row2][col2 - j];
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
int right(int arr[N][M], int row1, int col1, int row2, int col2, int m)
{
    int judge = 0;
    for(int j = 1; col1 + j < m + 1; j++)
    {
        judge += arr[row1][col1 + j];
    }
    for(int j = 1; col2 + j < m + 1; j++)
    {
        judge += arr[row2][col2 + j];
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
    int n, m;
    int number;
    scanf("%d", &n);
    scanf("%d", &m);
    int arr1[N][M] = {0};
    int arr2[N * M / 2 + 1][5] = {0};//横坐标1，纵坐标1，横坐标2，纵坐标2，是否被消
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &number);
            arr1[i][j] = number;
            if(arr2[number][4] == 0)
            {
                arr2[number][0] = i;
                arr2[number][1] = j;
                arr2[number][4] = 1;
            }
            else
            {
                arr2[number][2] = i;
                arr2[number][3] = j;
            }
        }
    }
    
    for(int i = 1; i < n * m / 2 + 1; i++)
    {
        int row1 = arr2[i][0];
        int col1 = arr2[i][1];
        int row2 = arr2[i][2];
        int col2 = arr2[i][3];
        if(up(arr1, row1, col1, row2, col2) == 1)
        {
            arr2[i][4] = 0;
            arr1[row1][col1] = 0;
            arr1[row2][col2] = 0;
        }
        else if(down(arr1, row1, col1, row2, col2, n) == 1)
        {
            arr2[i][4] = 0;
            arr1[row1][col1] = 0;
            arr1[row2][col2] = 0;
        }
        else if(left(arr1, row1, col1, row2, col2) == 1)
        {
            arr2[i][4] = 0;
            arr1[row1][col1] = 0;
            arr1[row2][col2] = 0;
        }
        else if(right(arr1, row1, col1, row2, col2, m) == 1)
        {
            arr2[i][4] = 0;
            arr1[row1][col1] = 0;
            arr1[row2][col2] = 0;
        }
    }

    for(int i = 1; i < n * m / 2 + 1; i++)
    {
        if(arr2[i][4] == 0)
        {
            printf("%d ", i);
        }
    }
}