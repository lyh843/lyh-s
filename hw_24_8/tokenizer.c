#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
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
int op_arr[M] = {0};//统计结果的   1、保留字  2、整数  3、浮点数  4、运算符  5、变量  6、回车
int loc_op = 0;//记录当前录入的结果位置
bool judge_ = true;//最后有没有分号的judge
bool judge = true;//总的judge
int f_judge_reserverd(char *);//判断函数
int f_judge_operater(char *);
int f_judge_integer(char *);
int f_judge_float(char *);
int f_judge_variable(char *);
void f_process(char *);
void f_output();
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
        if(!isdigit(string[i]))
        {
            return 0;
        }
    }
    return 1;
}
int f_judge_float(char *string)
{
    int count = 0;//数有多少个小数点
    char *pt_str = string;
    char *pos1 = string;
    for(pos1 = strchr(string, '.'); pos1; pt_str = pos1 + 1, pos1 = strchr(pt_str, '.'))//找到小数点位置
    {
        count++;
    }
    if(count == 1 && strlen(string) != 1)//有且只有一个小数点，且不是只有小数点
    {
        *(pt_str - 1) = 0;//让小数点的位置为\0
        for(int i = 0; string[i] != 0; i++)
        {
            if(!isdigit(string[i]))
            {
                return 0;
            }
        }
        for(int i = 0; *(pt_str + i) != 0; i++)
        {
            if(!isdigit(*(pt_str + i)))
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
    if((*string >= 'a' && *string <= 'z' )||(*string >= 'A' && *string <= 'Z')||(*string == '_'))//开头一定要是字母或下划线
    {
        for(int i = 1; string[i] != 0; i++)
        {
            if(isalpha(string[i]) || (string[i] == '_') || isdigit(string[i]))
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
        judge = false;//啥也不是，错误
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
    char string[N] = {0};//存储当前的字符
    while (scanf("%s", string) != EOF && judge) 
    {
        if(strchr(string, ';'))//看看字符中有没有分号，有的话需要进行分割处理
        {
            if(*(string + strlen(string) - 1) == ';')
            {
                judge_ = true;//结尾有分号
            }
            else
            {
                judge_ = false;
            }
            char *pt_str = string;//一个指针指向头部
            if(*string == ';')//如果第一位就是指针（前面没有东西）
            {
                *string = 0;
                pt_str = string + 1;
                op_arr[loc_op++] = 6;//分号意味着输出回车
            }
            for(char *pos = strchr(pt_str, ';'); pos; pt_str = pos + 1, pos = strchr(pt_str, ';'))//初始化pos指向分号的位置； 如果有分号，运行；下一次，更新pos，指向下一个分号的位置
            {
                *pos = 0;
                if(*pt_str != 0)//只要这个地方有东西，就执行
                {
                    f_process(pt_str);
                }
                op_arr[loc_op++] = 6;
            }
            if(*pt_str != 0)//前面是执行到最后一个分号的前面部分，如果后面还有东西，就继续执行
            {
                f_process(pt_str);
            }
        }
        else//当前语句没有分号的情况
        {
            f_process(string);
            judge_ = false;//当前语句没分号
        }
        memset(string, 0, sizeof(string));
    }
    f_output();
}