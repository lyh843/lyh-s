#include <stdio.h>
#define N 101
int main(void) 
{
    int op = 0;
    int size = 0;
    int arr1[N][N] = {0};
    int arr2[N][N] = {0};
    long arr3[N][N] = {0};
    scanf("%d", &op);
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    if(op == 4)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                arr3[i][j] = arr1[j][i];
            }
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                scanf("%d", &arr2[i][j]);
            }
        }
        if(op == 1)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    arr3[i][j] = arr1[i][j] + arr2[i][j];
                }
            }
        }
        else if(op == 2)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    arr3[i][j] = arr1[i][j] - arr2[i][j];
                }
            }
        }
        else if(op == 3)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    for (int k = 0; k < size; k++)
                    {
                        arr3[i][j] += arr1[i][k] * arr2[k][j];
                    }
                }
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%ld ", arr3[i][j]);
        }
        printf("\n");
    }
    return 0;
}