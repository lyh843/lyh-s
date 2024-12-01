#include<stdio.h>
#include<string.h>
int main(void)
{
    //1、strcmp
    //用于比较两个字符串， 功能是逐个字符地比较两个字符串的大小关系
    //
    //int strcmp(const char *str1, const char *str2);
    //
    //str1, str2是指向要比较的两个字符串的指针
    //
    //返回值：第一位不相等的ASCII值的差值
    //      0：两个字符串相等
    //      正数：如果str1大于str2
    //      负数：如果str2大于str1

    //2、strcpy
    //
    
    //3、strtok

    //4、sprintf
    //将格式化的数据写入字符串中
    //
    //int sprintf(char *str, const char *format, ...);
    //
    //str :用于存储格式化输出的目标字符串。
    //format：格式字符串，指定输出的格式，支持 %d、%f、%s 等常见格式。
    // ...：可变参数，根据 format 的内容，提供相应数量和类型的参数。
    //   
    //例：
    //sprintf(word, ": invalid option -- '%c'", wrong[0]);
    // 
    //返回值：
    //成功时返回写入字符串的字符总数（不包括\0）
    //失败时返回负值


    //5、strchr  &&  strstr
}