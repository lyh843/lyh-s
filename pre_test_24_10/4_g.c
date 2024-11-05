#include<stdio.h>

int main(void)
{
    int size = 0;
    scanf("%d", &size);
    int arr[10][10] = {0};
    arr[0][(size - 1) / 2] = 1;
    int row = 0;
    int col = (size - 1) / 2;
    for(int i = 2; i <= size * size; i++)
    {
        if(row == 0 && col == size - 1)
        {   
            if(arr[size - 1][0] == 0)
            {
                row = size - 1;
                col = 0;
            }
            else
            {
                row = 1;
            }
        }
        else if(row == 0)
        {
            if(arr[size - 1][col + 1] == 0)
            {
                row = size - 1;
                col = col + 1;
            }
            else
            {
                row = 1;
            }
        }
        else if(col == size -1)
        {
            if(arr[row - 1][0] == 0)
            {
                row = row - 1;
                col = 0;
            }
            else
            {
                row++;
            }
        }
        else
        {
            if(arr[row - 1][col + 1] == 0)
            {
                row--;
                col++;
            }
            else
            {
                row++;
            }
        }
        arr[row][col] = i;
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}