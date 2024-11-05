#include<stdio.h>
#define N 102
//ASCII中 o→111   *→42
int count(int arr1[N][N], int i, int j)
{
    int sum = 0;
    sum += arr1[i - 1][j - 1] + arr1[i - 1][j] + arr1[i - 1][j + 1];
    sum += arr1[i][j - 1] + arr1[i][j] + arr1[i][j + 1];
    sum += arr1[i + 1][j - 1] + arr1[i + 1][j] + arr1[i + 1][j + 1];
    return ((999 -sum) / 69);
}



int main(void)
{
    int size;
    scanf("%d", &size);
    int arr1[N][N] = {0};
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            arr1[i][j] = 111;
        }
    }
    int arr2[N][N] = {0};
    for(int i = 1; i < size + 1; i++)
    {
        for(int j = 1; j < size + 1; j++)
        {
            scanf("%1s", &arr1[i][j]);
        }
    }
    for(int i = 1; i < size + 1; i++)
    {
        for(int j = 1; j < size + 1; j++)
        {
            if(arr1[i][j] == 111)
            {
                arr2[i][j] = count(arr1, i, j);    
            }
            else
            {
                arr2[i][j] = 42;
            }
        }
    }

    for(int i = 1; i < size + 1; i++)
    {
        for(int j = 1; j < size + 1; j++)
        {
            if(arr2[i][j] == 42)
            {
                printf("*");
            }
            else
            {
                printf("%d", arr2[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}