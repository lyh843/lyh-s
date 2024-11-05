#include<stdio.h>

int main(void)
{
    //define variate
    char p_num[20];
    int arr[20];

    //input
    printf("Enter phone number:");
    scanf("%s", p_num);
    
    //calculate
    for(int i = 0; i <20; i++)
    {
        switch (p_num[i])
        {
        case 'A':case 'B':case 'C':
            arr[i] = 2;
            break;
        case 'D':case 'E':case 'F':
            arr[i] = 3;
            break;
        case 'G':case 'H':case 'I':
            arr[i] = 4;
            break;
        case 'J':case 'K':case 'L':
            arr[i] = 5;
            break;
        case 'M':case 'N':case 'O':
            arr[i] = 6;
            break;    
        case 'P':case 'Q':case 'R':case 'S':
            arr[i] = 7;
            break;
        case 'T':case 'U':case 'V':
            arr[i] = 8;
            break;
        case 'W':case 'X':case 'Y':case 'Z':
            arr[i] = 9;
            break;
        default:
            arr[i] = 0;
            break;
        }
    }
    
    //output
    for(int i = 0; i < 20; i++)
    {
        if(arr[i] == 0)
        {
            printf("%c", p_num[i]);
        }
        else
        {
            printf("%d", arr[i]);
        }
    }
}