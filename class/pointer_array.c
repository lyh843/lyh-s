#include<stdio.h>
#include<string.h>
#define len 10
void swap(char **p1, char **p2)
{
    char *temp;
    temp = *p2;
    *p2 = *p1;
    *p1 = temp;
}
// int arr[3][3] = 
// {
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 9}
// };
void fun(int arr[][3])//arr[][3] = int (*)[3];
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
            printf("%d\n", *(*(arr + i) + j));
            printf("%p %p %p\n", arr + i, *(arr + i), arr[i]);
            printf("%p %p\n", &arr[i][j], *(arr + i) + j);
        }
    }
}
int main (void)
{
    char *p1[len];
    // 存的是地址，地址指向的是字符串
    // 存的每一个都是char *
    // 要用char** 指向 char*
    memset(p1, 0, len);
    char (*p2)[len];
    memset(p1, 0, len);
    printf("p1 = %p\n", p1);
    // printf("++p1 = %p\n", ++p1);
    printf("p2 = %p\n", p2);
    printf("++p2 = %p\n", ++p2);
    // char *p[4] = 
    // {
    //     "first sentence", 
    //     "second sentence",
    //     "third sentence",
    //     "fourth sentence"
    // };
    // for(int i = 0; i < 4; i++)
    // {
    //     printf("%s\n", p[i]);
    //     printf("%p\n", p[i]);
    //     printf("%p\n", &p[i]);
    //     //printf("%p\n", p[i]);
    // }
    // swap(&p[2], &p[3]);//传入指向内容的指针
    // // printf("%s\n", "hello, world");
    // // char *pt = "hello, world";
    // // printf("%s\n", pt);
    // printf("\n");
    // for(int i = 0; i < 4; i++)
    // {
    //     printf("%s\n", p[i]);
    //     printf("%p\n", p[i]);
    //     printf("%p\n", &p[i]);
    //     //printf("%p\n", p[i]);
    // }
    // printf("\n");
    // int arr[3][3] = 
    // {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };
    // fun(arr);
}