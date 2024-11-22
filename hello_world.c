#include <string.h>
#include <stdbool.h>
#include <stdio.h>
char stack[10005], s[10005];
int top =0;
int is_empty(void)
{
    return top==0;
}
void push(char ch)
{
    stack[top++] = ch;
}
void pop(void)
{
    top--;
}
int test_balanced_bracket_sequence(char x)
{
    if(is_empty())
    {
        return 0;
    }
    if(x==stack[top-1]-1||x==stack[top-1]-2)
    {
        pop();
        return 1;
    }
    return 0;
}
int main(void)
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        top=0;
        memset(s, 0, sizeof(s));
        scanf("%s",s);
        int len = strlen(s), err=0;
        while(len--)
        {
            if(s[len]==')'||s[len]==']'||s[len]=='}')
            {
                push(s[len]);
            }
            else if(s[len]=='('||s[len]=='['||s[len]=='{')
            {
                if(test_balanced_bracket_sequence(s[len])==0)
                {
                    err=1;
                    break;
                }
            }
        }
        if(err==1||top!=0)
        {
            printf("False\n");
            continue;
        }
        printf("True\n");
    }
}