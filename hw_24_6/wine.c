#include<stdio.h>
#define N 10001
int main(void)
{
    int amount_beer = 0, vol_cup = 0;
    int beer[N][2] = {0};
    int price = 0;
    scanf("%d%d", &amount_beer, &vol_cup);
    for(int i = 0; i < amount_beer; i++)
    {
        scanf("%d", &beer[i][0]);
    }
    for(int i = 0; i < amount_beer; i++)
    {
        scanf("%d", &beer[i][1]);
    }
    //冒泡排序
    for(int i = 0; i < amount_beer - 1; i++)
    {
        for(int j = 0; j < amount_beer - i - 1; j++)
        {
            int temp = 0;
            if(beer[j][0] > beer[j + 1][0])
            {
                temp = beer[j][0];
                beer[j][0] = beer[j + 1][0];
                beer[j + 1][0] = temp;
                temp = beer[j][1];
                beer[j][1] = beer[j + 1][1];
                beer[j + 1][1] = temp;
            }
        }
    }
    for(int i = amount_beer - 1; i >= 0; i--)
    {
        if(vol_cup <= beer[i][1])
        {
            price += vol_cup * beer[i][0];
            break;
        }
        else
        {
            price += beer[i][0] * beer[i][1];
            vol_cup = vol_cup - beer[i][1];
        }
    }
    printf("%d", price);
}