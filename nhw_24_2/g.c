#include<stdio.h>

int main(void)
{
    //输入部分
    int length;
    scanf("%d", &length);
    char arr[length];
    char rubbish;//垃圾桶
    scanf("%c", &rubbish);//把换行符丢垃圾桶
    for(int i = 0; i < length; i++)
    {
        scanf("%c", &arr[i]);//再读取字符串
    }
    int mid;
    scanf("%d", &mid);
    //处理部分
    for(int i = 0; i < mid / 2; i++)//前半部分翻转
    {
        char temp;
        temp = arr[i];
        arr[i] = arr[(mid -1 - i)];
        arr[(mid -1 - i)] = temp;
    }
    for(int i = 0; i < (length - mid) / 2; i++)//后半部分翻转
    {
        char temp;
        temp = arr[i + mid];
        arr[i + mid] = arr[(length - i - 1)];
        arr[(length - i - 1)] = temp;
    }
    //输出部分
    for(int i = 0; i < length; i++)
    {
        printf("%c", arr[i]);
    }
}