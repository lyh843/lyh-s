#include<stdio.h>
#include<string.h>

int main(void)
{
    int *ptr_radius;
    double *q;
    char *r;
    int radius = 100;
    printf("ptr_radius = %p\n", ptr_radius);
    printf("&ptr_radius = %p\n", &ptr_radius);
    printf("radius = %d\n", radius);
    printf("&radius = %p\n", &radius);
    printf("sizeof(&radius) = %u\n", sizeof(&radius));
    ptr_radius = &radius;
    printf("ptr_radius = %p\n", ptr_radius);
    printf("&ptr_radius = %p\n", &ptr_radius);
    printf("sizeof(int *) = %d\n", sizeof(int *));
    printf("sizeof(double *) = %d\n", sizeof(double *));
    printf("*ptr_radius = %d\n", *ptr_radius);
    *ptr_radius = 200;
    printf("radius = %d\n", radius);
    printf("ptr_radius = %p\n", ptr_radius);
    printf("*ptr_radius = %d\n", *ptr_radius);
}