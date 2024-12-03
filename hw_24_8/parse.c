#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define N 150
#define M 20
char rule[N];
char order[N][M];//最后一位标2，说明要吃东西；最后一位标1，说明被吃了;
int num_order = 0;
char spe_order[N];//会吃东西的字母
int num_spe;
bool judge2 = true, judge3 = true;
char word[200], wrong[2];
void f_input()
{
    scanf("%s", rule);
    while(scanf("%s", order[num_order++]) != EOF);
    num_order--;
}
void f_record()
{
    for(int i = 0; rule[i] != '\0'; i++)
    {
        if(rule[i] == ':')
        {
            spe_order[num_spe] = rule[i - 1];
            num_spe++;
        }
    }
    for(int i = 1; i < num_order; i++)
    {
        if(order[i][0] == '-' && strchr(spe_order, order[i][1]) != NULL && order[i][M - 1] != 1)
        {
            order[i][M - 1] = 2;
            order[i + 1][M - 1] = 1;
        }
    }
}
void f_judge()
{
    for(int i = 1; i < num_order - 1 && judge2 && judge3; i++)//把除最后一个命令，其他都检测一遍
    {
        if(order[i][0] == '-')
        {
            if(strchr(rule, order[i][1]) == NULL && order[i][M - 1] != 1)
            {
                wrong[0] = order[i][1];
                judge3 = false;
            }
        }
    }
    if(order[num_order - 1][0] == '-' && order[num_order - 1][M - 1] != 1 && judge3)
    {
        if(strchr(rule, order[num_order - 1][1]) == NULL)
        {
            wrong[0] = order[num_order - 1][1];
            judge3 = false;
        }
        else if(strchr(spe_order, order[num_order - 1][1]) != NULL)
        {
            wrong[0] = order[num_order - 1][1];
            judge2 = false;
        }
    }
}
int main(void)
{
    f_input();
    f_record();
    f_judge();
    if(!judge2)
    {
        sprintf(word, ": option requires an argument -- '%c'", wrong[0]);
        printf("%s", order[0]);
        printf("%s", word);
    }
    else if(!judge3)
    {
        sprintf(word, ": invalid option -- '%c'", wrong[0]);
        printf("%s", order[0]);
        printf("%s", word);
    }
    else
    {
        printf("%s\n", order[0]);
        for(int i = 1; i < num_order; i++)
        {
            if(order[i][0] == '-')
            {
                if(order[i][M - 1] == 2)
                {
                    printf("%c=%s\n", order[i][1], order[i + 1]);
                }
                else if(order[i][M - 1] == 0)
                {
                    printf("%c\n", order[i][1]);
                }
            }
        }
    }
}