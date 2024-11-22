#include<stdio.h>
#include<stdlib.h>
#define M 100
#define N 100
#define P 100

int main(void)
{
    printf("This code is used to caculate a  m*n matrix mutiply a n*p matrix.\n");
    printf("code's writer: lyh\n");
    int m, n, p;
    printf("please enter the \"m\":  ");
    scanf("%d", &m);
    printf("please enter the \"n\":  ");
    scanf("%d", &n);
    printf("please enter the \"p\":  ");
    scanf("%d", &p);
    int arr1[M][N] = {0};
    int arr2[N][P] = {0};
    int arr3[M][P] = {0};
    printf("please enter the first matrix, please use blank to seperate each number.\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("please enter the second matrix, please use blank to seperate each number.\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < p; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < p; j++)
        {
            for(int k = 0; k < n; k++)
            {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    printf("The result is:\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < p; j++)
        {
            printf("%d\t", arr3[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}