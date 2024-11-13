//栈-模板题
#include<stdio.h>
#include<string.h>
#define N 10001
void f_operat(char *pt_stack, char op[10], int int_op, int *pt_size_stack)
{
    if(int_op == 1)//push
    {
        (*pt_size_stack)++;
        pt_stack[(*pt_size_stack) - 1] = op[0];
    }
    else if(int_op == 2)//pop
    {
        if(*pt_size_stack == 0)
        {
            printf("Empty\n");
        }
        else
        {
            (*pt_size_stack)--;
        }
    }
    else if(int_op == 3)//top
    {
        if(*pt_size_stack == 0)
        {
            printf("Empty\n");
        }
        else
        {
            printf("%c\n", pt_stack[*pt_size_stack - 1]);
        }
    }
    else if(int_op == 4)//print
    {
        if(*pt_size_stack == 0)
        {
            printf("Empty\n");
        }
        else
        {
            for(int i = *pt_size_stack - 1; i >= 0; i--)
            {
                printf("| %c |\n", *(pt_stack + i));
            }
            printf("|===|\n");
        }
    }
}
int main(void)
{
    int times = 0, size_stack = 0, int_op = 0;//1_push, 2_pop, 3_top, 4_print
    char stack[N], op[10];
    memset(stack, 0, sizeof(stack));
    memset(op, 0, sizeof(op));
    scanf("%d", &times);
    for(int i = 0; i < times; i++)
    {
        scanf("%s", op);
        if(strcmp(op, "push") == 0)
        {
            int_op = 1;
            scanf("%s", op);
            f_operat(stack, op, int_op, &size_stack);
        }
        else if(strcmp(op, "pop") == 0)
        {
            int_op = 2;
            f_operat(stack, op, int_op, &size_stack);
        }
        else if(strcmp(op, "top") == 0)
        {
            int_op = 3;
            f_operat(stack, op, int_op, &size_stack);
        }
        else if(strcmp(op, "print") == 0)
        {
            int_op = 4;
            f_operat(stack, op, int_op, &size_stack);
        }
    }
}