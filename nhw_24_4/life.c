#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1010
char map[N];
char map_temp[N];
int f_change(int, int, int);
void f_generate(int, int);
void f_generate(int times, int len)
{
    for(int i = 0; i < times; i++)
    {
        for(int j = 0; j < len; j++)
        {
            int type = 0;
            int change = 0;
            if(map[j] == 'A')
            {
                type = 1;
                change = f_change(type, i, j);
            }
            else if(map[j] == 'B')
            {
                type = 2;
                change = f_change(type, i, j);
            }
            else
            {
                type = 3;
                change = f_change(type, i, j);
            }
            if(change == 0)
            {
                map_temp[j] = '.';
            }
            else if(change == 1)
            {
                map_temp[j] = 'A';
            }
            else if(change == 2)
            {
                map_temp[j] = 'B';
            }
        }
        strcpy(map, map_temp);
    }
}
int f_change(int type, int times, int loc)
{
    int result = 0;//0-消亡，1-变成A，2-变成 B
    int count_a = 0;
    int count_b = 0;
    for(int i = -3; i <= 3; i++)
    {
        if(map[loc + i] == 'A')
        {
            count_a++;
        }
        else if(map[loc + i] == 'B')
        {
            count_b++;
        }
    }
    if(type == 1)
    {
        count_a--;
        if(count_a >= 5 || count_b != 0 || count_a <= 1)
        {
            result = 0;
        }
        else
        {
            result = 1;
        }
    }
    else if(type == 2)
    {
        count_b--;
        if(count_b >= 5 || count_a != 0 || count_b <= 1)
        {
            result = 0;
        }
        else
        {
            result = 2;
        }
    }
    else
    {
        if(count_a >=2 && count_a <=4 && count_b == 0)
        {
            result = 1;
        }
        else if(count_b >=2 && count_b <=4 && count_a == 0)
        {
            result = 2;
        }
    }
    return result;
}
int main(void)
{
    memset(map, 0, N);
    memset(map, 0, N);
    int times = 0;
    scanf("%d", &times);
    scanf("%s", &map);
    int len = strlen(map);
    f_generate(times, len);
    printf("%s", map);
}