#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define N 970000
#define M 500001
int line_op = 0;
char op[410][M] = {0};
char temp_op[M] = {0};
char string[N] = {0};
char *string1_start, *string1_end, *string2_start, *string2_end;
char *op1, *op2;
void f_input()
{
    scanf("%d", &line_op);
    for(int i = 0; i < line_op; i++)
    {
        scanf("%s", op[i]);
    }
    scanf("%s", string);
}
bool f_judge_op()
{
    for(int i = 0; i < line_op; i++)
    {
        strcpy(temp_op, op[i]);
        op1 = temp_op;
        string1_start = strchr(temp_op, '[') + 1;
        string1_end = strchr((string1_start - 2), ']');
        *string1_end = '\0';
        if(op1[0] == '.' && strstr(string, string1_start) == NULL)
        {
            continue;
        }
        else if(op1[0] == '^' && strstr(string, string1_start) != string)
        {
            continue;
        }
        else if(op1[0] == '$' && strcmp(string + strlen(string) - strlen(string1_start), string1_start))
        {
            continue;
        }
        else
        {
            op2 = string1_end + 1;
            string2_start = string1_end + 3;
            string2_end = strchr((string2_start - 2), ']');
            *string2_end = '\0';
            return true;
        }
    }
    return false;
}
void f_operate()
{
    while(f_judge_op())//先找找有没有对应的修改字符
    {
        char temp_string[N] = {0};
        if(op1[0] == '.')
        {
            char *pos1 = strstr(string, string1_start);
            *pos1 = 0;
            if(op2[0] == '.')
            {
                strcpy(temp_string, string);
                strcat(temp_string, string2_start);
                strcat(temp_string, pos1 + strlen(string1_start));
                strcpy(string, temp_string);
            }
            else if(op2[0] == '^')
            {
                strcpy(temp_string, string2_start);
                strcat(temp_string, string);
                strcat(temp_string, pos1 + strlen(string1_start));
                strcpy(string, temp_string);
            }
            else if(op2[0] == '$')
            {
                strcpy(temp_string, string);
                strcat(temp_string, pos1 + strlen(string1_start));
                strcat(temp_string, string2_start);
                strcpy(string, temp_string);
            }
        }
        else if(op1[0] == '^')
        {
            char *pos1 = strstr(string, string1_start);
            if(op2[0] == '.' || op2[0] == '^')
            {
                strcpy(temp_string, string2_start);
                strcat(temp_string, pos1 + strlen(string1_start));
                strcpy(string, temp_string);
            }
            else
            {
                strcpy(temp_string, pos1 + strlen(string1_start));
                strcat(temp_string, string2_start);
                strcpy(string, temp_string);
            }
        }
        else if(op1[0] == '$')
        {
        
            char *pos1 = string + strlen(string) - strlen(string1_start);
            *pos1 = 0;
            if(op2[0] == '^')
            {
                strcpy(temp_string, string2_start);
                strcat(temp_string, string);
                strcpy(string, temp_string);
            }
            else if(op2[0] == '.' || op2[0] == '$')
            {
                strcpy(temp_string, string);
                strcat(temp_string, string2_start);
                strcpy(string, temp_string);
            }
        }
    }
    printf("%s\n", string);
}
int main(void)
{
    f_input();
    f_operate();
    return 0;
}