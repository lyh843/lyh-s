#include<stdio.h>
#define N 100
int main(void)
{
    char string[N] = {0};
    char *pt_str = string;
    int i = 0;
    while (scanf("%s", string) != EOF) 
    {
        i++;
        printf("%s", string);
    }
    printf("%d", i);
}