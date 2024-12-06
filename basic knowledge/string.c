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
    //用于将源字符串复制到目标字符串。
    // 
    // char *strcpy(char *dest, const char *src);
    // 
    // 地址：
    // dest：目标字符串的指针，必须有足够的空间来存放源字符串及其终止符 \0。
    // src：源字符串的指针。
    // 
    // 返回值   
    // 返回指向目标字符串 dest 的指针。

    //3、strtok
    // 用于分割字符串函数，将字符串分割成由特定分隔符分隔的若干部分
    // 
    // char *strtok(char *str, const char *delim);
    // 
    // str:
    // 第一次调用时，传入要分割的字符串
    // 后续调用时传入NULL，表示继续上次的分割
    // delim:
    // 标识分隔符的字符串，可以包含多个分隔字符
    // 
    // 返回值：
    // 返回第一个子字符串的地址
    // 或者NULL

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
    // 查找
}