#include<stdio.h>
#include<string.h>
void f_print(int *pt_arr)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", *(pt_arr + i * 3 + j));
        }
        printf("\n");
    }
}
int main(void)
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    f_print(arr);
}