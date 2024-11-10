#include<stdio.h>
int f_a(int *p)
{
    int b = 114514;
    printf("(f_a)p = %p\n", p);
    printf("(f_a)&p = %p\n", &p);
    p = &b;
    printf("(f_a)p = %p\t(f_a)&b = %p\n", p, &b);
    printf("(f_a)&p = %p\n", &p);
}
int main(void)
{
    int arr[3] = {1, 53, 35};
    f_a(arr);
    printf("(main)arr = %p\n", arr);
    printf("(main)&arr = %p\n", &arr);
    printf("(main)arr + 1 = %p\n", arr + 1);
    for(int i = 0; i < 3; i++)
    {
        printf("%d ", arr[i]);
    }
}