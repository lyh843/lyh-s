#include<stdio.h>
#include<math.h>

char op[10] = {0};
int main(void)
{
    int num_1 = 0, num_2 = 0;
    while (scanf("%d", &num_1) != EOF) 
    {
        char judge;
        scanf("%1s", &op[0]);
        scanf("%1s", &judge);
        if((int)judge <= 57 && (int)judge >= 48)
        {
            num_2  = (int)judge - 48;
            op[1] = 0;
        }
        else
        {
            op[1] = judge;
            scanf("%d", &num_2);
        }
        float result = 0;
        switch(op[0] + op[1])
        {
            case '+':
            {   
                printf("%d\n", num_1 + num_2);
                break;
            }
            case '-':
            {
                printf("%d\n", num_1 - num_2);
                break;
            }
            case '*':
            {
                printf("%d\n", num_1 * num_2);
                break;
            }
            case '/':
            {
                printf("%d\n", num_1 / num_2);
                break;
            }
            case 'Y':
            {
                printf("%.3f\n", (float)num_1 / (float)num_2);
                break;
            }
            case 'T':
            {
                printf("%d\n", (int)pow(num_1, num_2));
                break;
            }
            case '%':
            {
                printf("%d\n", num_1 % num_2);
                break;
            }
        }
    }
    return 0;
}