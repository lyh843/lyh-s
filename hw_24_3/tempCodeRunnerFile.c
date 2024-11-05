#include<stdio.h>
#include<string.h>
#include<math.h>

int main (void)
{
    int amount = 0;
    char string[15] = {0};
    int each_arr[15] = {0};
    int number;
    scanf("%d", &amount);
    for(int i = 0; i < amount; i++)
    {
        scanf("%s", string);
        getchar();
        int mark = 1;
        int number = 0;
        int length_string = strlen(string);
        int judge = 0;
        //读取录入信息
        for(int j = 0; j < length_string; j++)
        {
            switch((int)string[j])
            {
                case 45://负号
                    each_arr[j] = 0;
                    mark = -1;
                    break;
                case 48:
                    each_arr[j] = 0;
                    break;
                case 49:
                    each_arr[j] = 1;
                    break;
                case 50:
                    each_arr[j] = 2;
                    break;
                case 51:
                    each_arr[j] = 3;
                    break;
                case 52:
                    each_arr[j] = 4;
                    break;
                case 53:
                    each_arr[j] = 5;
                    break;
                case 54:
                    each_arr[j] = 6;
                    break;
                case 55:
                    each_arr[j] = 7;
                    break;
                case 56:
                    each_arr[j] = 8;
                    break;
                case 57:
                    each_arr[j] = 9;
                    break;
                default:
                    each_arr[j] = 12;
                    break;
            }
        }
        //转换为10进制
        for(int j = 0; j < length_string; j++)
        {
            if(each_arr[j] == 12)
            {
                judge = 1;
                break;
            }
            else
            {
                number = number + each_arr[j] * pow(10, length_string - j -1);
            }
        }
        //转换为3进制
        int number3 = 0;
        int each_arr1[20] = {0};
        int length1 = 0;
        if(number < 3)
        {
            each_arr1[0] = number;
            length1 = 1;
        }
        else
        {
            for(int j = 8; j >= 0; j--)
            {
                if(number >= pow(3, j))
                {
                    each_arr1[j] = number / pow(3, j);
                    length1++;
                }
                number = number - each_arr1[j] * pow(3, j);
            }
        }
        //三进制转换为平衡三进制
        char result[20] = {0};
        for(int j = 0; j < length1; j++)
        {
            if(each_arr1[j] == 1 || each_arr1[j] == 0)
            {
            }
            else if(each_arr1[j] == 2)
            {
                each_arr[j] = -1;
                each_arr[j + 1] += 1;
                if(j + 1 > length1 - 1)
                {
                    length1++;
                }
            }
            else if(each_arr1[j] == 3)
            {
                each_arr1[j] = 0;
                length1++;
                each_arr1[j + 1] = 1;
                if(j + 1 > length1 - 1)
                {
                    length1++;
                }
            }
        }
        //输出
        if(judge == 1)
        {
            printf("Radix Error");
        }
        else
        {
            if(mark == 1)
            {
                for(int j = length1 - 1; j >= 0; j--)
                {
                    if(each_arr1[j] == 1 || each_arr1[j] == 0)
                    {
                        printf("%d", each_arr1[j]);
                    }
                    else
                    {
                        printf("Z");
                    }
                }
            }
            else
            {
                for(int j = length1 - 1; j >= 0; j--)
                {
                    if(each_arr1[j] == 1 || each_arr1[j] == 0)
                    {
                        printf("%d", each_arr1[j]);
                    }
                    else
                    {
                        printf("Z");
                    }
                }
            }
        }
        printf("\n");
    }
}