#include<stdio.h>
int len = 0, width = 0, high = 0;
void f_print()
{
    for(int i = 1; i <= width; i++)
    {
        for(int j = 0; j < width - i + 1; j++)
        {
            printf("  ");
        }
        for(int j = 0; j < len; j++)
        {
            printf("+-");
        }
        printf("+");
        for(int j = 0; j < width - i + 1; j++)
        {
            printf(" ");
        }
        for(int j = 0; j < len; j++)
        {
            printf(" /");
        }
    }
}
int main(void)
{
    int times = 0;
    scanf("%d", &times);
    for(int i = 0; i < times; i++)
    {
        scanf("%d%d%d", &len, &width, &high);
        f_print();
    }
}