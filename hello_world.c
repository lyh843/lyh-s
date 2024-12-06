#include<stdio.h>
#include<string.h>
#define N 1000
char line[N][N];
int end_line = 0, start_line = 0;
void f_in()
{
    scanf("%s", line[end_line++]);
}
void f_cat()
{
    printf("%d ", end_line - start_line);
    printf("[");
    for(int i = start_line; i < end_line - 1; i++)
    {
        printf("%s,", line[i]);
    }
    if(end_line - 1 >= 0)
    {
            printf("%s]\n", line[end_line - 1]);
    }
}
void f_out()
{
    printf("%s\n", line[start_line++]);
}
int main(void)
{
    int times = 0;
    scanf("%d", &times);
    for(int i = 0; i < times; i++)
    {
        char op[4];
        memset(op, 0, 4);
        scanf("%s", op);
        if(strcmp(op, "In") == 0)
        {
            f_in();
        }
        else if (strcmp(op, "Cat") == 0)
        {
            f_cat();
        }
        else if(strcmp(op, "Out") == 0)
        {
            f_out();
        }
    }
    return 0;
}