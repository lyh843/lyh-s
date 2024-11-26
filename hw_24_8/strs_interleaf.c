#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define N 1010
#define M 2020
char string1[N] = {0}, string2[N] = {0}, string3[M] = {0};
int change_len1 = 0, change_len2 = 0;
int len1 = 0, len2 = 0, size_len3 = 0;
void f_input(char *origin)
{
    char *temp = strtok(origin, ";");
    strcpy(string1, temp);
    temp = strtok(NULL, ";");
    strcpy(string2, temp);
    temp = strtok(NULL, ";");
    change_len1 = atoi(temp);
    temp = strtok(NULL, ";");
    change_len2 = atoi(temp);
    temp = strtok(NULL, ";");
    size_len3 = atoi(temp);
}
void f_opearate()
{
    bool judge1 = false, judge2 = false;
    bool fin_judge1 = false, fin_judge2 = false, fin_judge3 = false;//放完没有？
    int loc_string1 = 0, loc_string2 = 0, loc_string3 = 0;
    for(loc_string3 = 0; !fin_judge3 && !(fin_judge1 && fin_judge2); )//只要3还能放下东西就不出来
    {
        judge1 = false;//有没有放1
        judge2 = false;//有没有放2
        if(len1 - loc_string1 > change_len1 && size_len3 - loc_string3 > change_len1 && !fin_judge3 && !fin_judge1)//1剩下的够不够完整放一次？够 3剩下的位置够不够1放下剩下的完整？够，而且还有空位
        {
            for(int j = 0; j < change_len1; j++)
            {
                string3[loc_string3++] = string1[loc_string1++];
            }
            judge1 = true;
        }
        else if(size_len3 - loc_string3 > len1 - loc_string1 && !fin_judge3 && !fin_judge1)//3能不能把1剩下的放完？能， 而且放完还有空位
        {
            fin_judge1 = true;
            judge1 = true;
            for(int j = 0; j < len1 - loc_string1; j++)
            {
                string3[loc_string3++] = string1[loc_string1 + j];
            }
            loc_string1 = len1;
        }
        else if(size_len3 - loc_string3 <= len1 - loc_string1 && !fin_judge3 && !fin_judge1)//3放不下了，或者刚好放下
        {
            fin_judge3 = true;
            for(int i = 0; i < size_len3 - loc_string3; i++)
            {
                string3[loc_string3 + i] = string1[loc_string1 + i];
            }
        }
        
        if(len2 - loc_string2 > change_len2 && size_len3 - loc_string3 > change_len2 && !fin_judge3 && !fin_judge2)//2剩下的够不够完整放一次？够 3剩下的位置够不够2放下剩下的完整？够，而且还有空位
        {
            for(int j = 0; j < change_len2; j++)
            {
                string3[loc_string3++] = string2[loc_string2++];
            }
            judge2 = true;
        }
        else if(size_len3 - loc_string3 > len2 - loc_string2 && !fin_judge3 && !fin_judge2)//3能不能把2剩下的放完？能， 而且放完还有空位
        {
            fin_judge2 = true;
            judge2 = true;
            for(int j = 0; j < len2 - loc_string2; j++)
            {
                string3[loc_string3++] = string2[loc_string2 + j];
            }
            loc_string2 = len2;
        }
        else if(size_len3 - loc_string3 <= len2 - loc_string2 && !fin_judge3 && !fin_judge2)//3放不下了，或者刚好放下
        {
            fin_judge3 = true;
            for(int i = 0; i < size_len3 - loc_string3; i++)
            {
                string3[loc_string3 + i] = string2[loc_string2 + i];
            }
        }
    }
    string3[size_len3 - 1] = '\0';
}
int main(void)
{
    int times = 0;
    char origin[M] = {0};
    scanf("%d", &times);
    getchar();
    while(times--)
    {
        memset(origin, 0, M);
        memset(string1, 0, N);
        memset(string2, 0, N);
        memset(string3, 0, M);
        scanf("%s", origin);
        f_input(origin);
        len1 = strlen(string1);
        len2 = strlen(string2);
        f_opearate();
        printf("%s\n", string3);
    }
    return 0;
}