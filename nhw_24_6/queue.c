#include<stdio.h>
#include<string.h>
#define N 1000
int line[N];
int num_line = 0;
void f_in()
{
    scanf("%d", &line[num_line++]);
}
void f_cat()
{
    printf("%d [", num_line);
    for(int i  = 0; i < num_line; i++)
    {
        printf("%d", line[i]);
        if(i != num_line - 1)
        {
            printf(",");
        }
    }
    printf("]\n");
}
void f_out()
{
    printf("%d\n", line[0]);
    for(int i = 1; i < num_line; i++)
    {
        line[i - 1] = line[i];
    }
    num_line--;
}
int main(void)
{
    int times = 0;
    scanf("%d", &times);
    char op[4] = {0};
    while(times--)
    {
        scanf("%s", op);
        if(strcmp(op, "In") == 0)
        {
            f_in();
        }
        else if(strcmp(op, "Cat") == 0)
        {
            f_cat();
        }
        else if(strcmp(op, "Out") == 0)
        {
            f_out();
        }
    }
}
