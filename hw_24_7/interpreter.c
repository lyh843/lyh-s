#include<stdio.h>
int main(void)
{
    int number = 0;
    scanf("%x", &number);
    printf("%d\n", *(int*)&number);
    printf("%u\n", (__UINT32_TYPE__)number);
    printf("%f\n", *(float*)&number);
    printf("%.3e\n", *(float*)&number);
}