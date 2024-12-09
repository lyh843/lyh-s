#include<stdio.h>
#include<stdlib.h>
#define N 1000000
int arr[N] = {0};
int f_compare(const void *a, const void *b)
{
    int a1 = *(int *)a;
    int b1 = *(int *)b;
    if(a1 < b1)
    {
        return -1;
    }
    else if(a1 > b1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void f_bsearch(int len_arr)
{
    int number = 0, *result = arr;
    scanf("%d", &number);
    result = bsearch(&number, arr, len_arr, sizeof(int), f_compare);
    if(result)
    {
        printf("%d\n", result - arr);    
    }
    else
    {
        printf("-1\n");
    }
}
int main(void)
{
    int len_arr = 0, times = 0;
    scanf("%d%d", &len_arr, &times);
    for(int i = 0; i < len_arr; i++)
    {
        scanf("%d", &arr[i]);
    }
    while(times--)
    {
        f_bsearch(len_arr);
    }
    return 0;
}