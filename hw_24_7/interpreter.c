#include<stdio.h>
int main(void)
{
    int number = 0;
    float *pt_float = &number;
    scanf("%x", &number);
    printf("%d\n", *(int*)&number);
    printf("%u\n", (__UINT32_TYPE__)number);
    printf("%f\n", *pt_float);
    printf("%.3e\n", *pt_float);
}