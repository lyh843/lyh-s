#include<stdio.h>
//零钱兑换
int main (void)
{
    int num, amount50, amount20, amount10, amount5, amount1;
    scanf("%d", &num);

    amount50 = (num - (num % 50)) / 50;
    num = num - amount50 * 50;
    amount20 = (num - (num % 20)) / 20;
    num = num - amount20 * 20;
    amount10 = (num - (num % 10)) / 10;
    num = num - amount10 * 10;
    amount5 = (num - (num % 5)) / 5;
    num = num - amount5 * 5;
    amount1 = num; 

    printf("%d\n%d\n%d\n%d\n%d\n", amount50, amount20, amount10, amount5, amount1);
}