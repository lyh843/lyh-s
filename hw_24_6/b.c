#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define N 100001
void f_push(char , bool *, char *, int *);
void f_judge(char *, bool *);
void f_judge(char *pt_string, bool *pt_judge)
{
    int len = strlen(pt_string), len_stack = 0;
    char stack[N];
    memset(stack, 0, sizeof(stack));
    for(int i = 0; i < len; i++)
    {
        f_push(*(pt_string + i), pt_judge, stack, &len_stack);
    }
    if(len_stack == 0)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}
void f_push(char pt_push, bool *pt_judge, char *pt_stack, int *pt_len_stack)
{
    if(pt_push == '(' || pt_push == '{' || pt_push == '[')
    {
        (*pt_len_stack)++;
        *(pt_stack + *pt_len_stack - 1) = pt_push;
    }
    else
    {
        if(pt_push == ')' && *(pt_stack + *pt_len_stack - 1) == '(')
        {
            (*pt_len_stack)--;
        }
        else if(pt_push == '}' && *(pt_stack + *pt_len_stack - 1) == '{')
        {
            (*pt_len_stack)--;
        }
        else if(pt_push == ']' && *(pt_stack + *pt_len_stack - 1) == '[')
        {
            (*pt_len_stack)--;
        }
        else
        {
            (*pt_len_stack)++;
            *(pt_stack + *pt_len_stack - 1) = pt_push;
        }
    }
}
int main(void)
{
    int times = 0;
    char string[N];
    bool judge = true;
    memset(string, 0, sizeof(string));
    scanf("%d", &times);
    for(int i = 0; i < times; i++)
    {
        scanf("%s", string);
        f_judge(string, &judge);
    }
}