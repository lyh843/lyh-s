#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define N 4200
#define M 10000
char *reserverd[16] = 
{
"const", "int", "float", "double", 
"long", "static", "void", "char", 
"extern", "return", "break", "enum", 
"struct", "typedef", "union", "goto"
};
char *operator[11] = 
{
    "+", "-", "*", "/", "=", "==",
    "!=", ">=", "<=", ">", "<"
};
char *output[5] = 
{
    "reserved", "integer", "float", "operator", "variable"
};
int op_arr[M] = {0};
int loc_op = 0;
bool judge_ = true;//最后有没有分号的judge
bool judge = true;//总的judge
int f_judge_reserverd(char *string)
{
    for(int i = 0; i < 16; i++)
    {
        if(strcmp(reserverd[i], string) == 0)
        {
            return 1;
        }
    }
    return 0;
}
int f_judge_operater(char *string)
{
    for(int i = 0; i < 11; i++)
    {
        if(strcmp(operator[i], string) == 0)
        {
            return 1;
        }
    }
    return 0;
}
int f_judge_integer(char *string)
{
    for(int i = 0; string[i] != 0; i++)
    {
        if(string[i] < '0' || string[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}
int f_judge_float(char *string)
{
    int count = 0;
    char *pt_str = string;
    char *pos1 = string;
    for(pos1 = strchr(string, '.'); pos1; pt_str = pos1 + 1, pos1 = strchr(pt_str, '.'))
    {
        count++;
    }
    if(count == 1 && strlen(string) != 1)
    {
        *(pt_str - 1) = 0;
        for(int i = 0; string[i] != 0; i++)
        {
            if(string[i] < '0' || string[i] > '9')
            {
                return 0;
            }
        }
        for(int i = 0; *(pt_str + i) != 0; i++)
        {
            if(*(pt_str + i) < '0' || *(pt_str + i) > '9')
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
int f_judge_variable(char *string)
{
    if((*string >= 'a' && *string <= 'z' )||(*string >= 'A' && *string <= 'Z')||(*string == '_'))
    {
        for(int i = 1; string[i] != 0; i++)
        {
            if((string[i] >= 'a' && string[i] <= 'z' )||(string[i] >= 'A' && string[i] <= 'Z')||(string[i] == '_')||(string[i] >= '0' && string[i] <= '9'))
            {
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
void f_process(char *string)
{
    if(f_judge_reserverd(string))//保留字 1
    {
        op_arr[loc_op++] = 1;
    }
    else if(f_judge_operater(string))//运算符 4
    {
        op_arr[loc_op++] = 4;
    }
    else if(f_judge_float(string))//浮点数 3
    {
        op_arr[loc_op++] = 3;
    }
    else if(f_judge_variable(string))//变量 5
    {
        op_arr[loc_op++] = 5;
    }
    else if(f_judge_integer(string))//整数 2
    {
        op_arr[loc_op++] = 2;
    }
    else
    {
        judge = false;
    }
}
void f_output()
{
    if(judge_ && judge)
    {
        for(int i = 0; i < loc_op; i++)
        {
            if(op_arr[i] == 6)
            {
                printf("\n");
            }
            else
            {
                printf("%s ", output[op_arr[i] - 1]);
            }
        }
    }
    else
    {
        printf("Compile Error");
    }
}
int main(void)
{
    char string[N] = {0};
    while (scanf("%s", string) != EOF && judge) 
    {
        if(strchr(string, ';'))
        {
            judge_ = true;
            char *pt_str = string;
            if(*string == ';')
            {
                *string = 0;
                pt_str = string + 1;
                op_arr[loc_op++] = 6;
            }
            for(char *pos = strchr(pt_str, ';'); pos; pt_str = pos + 1, pos = strchr(pt_str, ';'))
            {
                *pos = 0;
                if(*pt_str != 0)
                {
                    f_process(pt_str);
                }
                op_arr[loc_op++] = 6;
            }
            if(*pt_str != 0)
            {
                f_process(pt_str);
            }
        }
        else
        {
            f_process(string);
            judge_ = false;
        }
        memset(string, 0, sizeof(string));
    }
    f_output();
}