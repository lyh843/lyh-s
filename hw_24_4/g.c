#include<stdio.h>
#include<math.h>
#define N 10
int main(void)
{
    int n = 0;
    int arr[N][N] = {0};
    int row, col;
    scanf("%d", &n);
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < n + 1; j++)
        {
            arr[i][j] = -1;
        }
    }

    row = 1;
    col = (n + 1) / 2;
    arr[row][col] = 1;
    for(int i = 2; i <= n * n; i++)
    {
        while(arr[row][col] + 1)
        {
            if(arr[row - 1][col + 1] == -1)
            {
                row--;
                col++;
            }
            else if(arr[row - 1][col + 1] != -1 && arr[row - 1][col + 1] != 0)
            {
                row++;
            }
            else
            {
                if(arr[row - 1][col + 1] == 0)
                {
                    if(row == 1 && col == n)
                    {
                        if(arr[n][1] == -1)
                        {
                            row = n;
                            col = 1;
                        }
                        else
                        {
                            row++;
                        }
                    }
                    else if(row == 1)
                    {
                        row = n;
                        col++;
                    }
                    else if(col = n)
                    {
                        col = 1;
                        row--;
                    }
                }
            }
        }
        arr[row][col] = i;
    }
    
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < n + 1; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}