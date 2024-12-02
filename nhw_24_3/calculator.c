#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
    int num1 = 0, num2 = 0;
    char op[5];
    while(scanf("%d", &num1) != EOF)
    {
        scanf("%s", op);
        scanf("%d", &num2);
        if(op[1] == '\0')//一位运算符
        {
            if(op[0] == '+')
            {
                printf("%d\n", num1 + num2);
            }
            else if(op[0] == '-')
            {
                printf("%d\n", num1 - num2);
            }
            else if(op[0] == '*')
            {
                printf("%d\n", num1 * num2);
            }
            else if(op[0] == '/')
            {
                printf("%d\n", num1 / num2);
            }
            else if(op[0] == '%')
            {
                printf("%d\n", num1 % num2);
            }
        }
        else if(op[0] == '/' && op[1] == '*')
        {
            printf("%.3f\n", 1.0 * num1 / num2);
        }
        else if(op[0] == '*' && op[1] == '*')
        {
            printf("%d\n", (int)pow(num1, num2));
        }
        memset(op, 0, sizeof(op));
    }
    return 0;
}