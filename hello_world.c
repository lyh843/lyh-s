#include<stdio.h>
#include<string.h>
int main(void)
{
    char a = 'a';
    char *p = &a;
    printf("%c", *p);
}