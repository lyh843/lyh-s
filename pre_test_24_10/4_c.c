#include<stdio.h>
#define N 10
#define M 10

int main(void)
{
    int arr1[N][M] = {0};
    int arr2[N][M] = {0};
    int arr3[N][M] = {0};
    int n = 0, m = 0, p = 0;
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 0; i  < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < p; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < p; j++)
        {
            for(int k = 0; k < m; k++)
            {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < p; j++)
        {
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }
}