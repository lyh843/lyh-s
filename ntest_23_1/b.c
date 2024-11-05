#include<stdio.h>
#define N 12
int main (void)
{
    int number_game, number_win;
    scanf("%d", &number_game);
    scanf("%d", &number_win);
    int count[3] = {0};
    for(int i = 0; i < number_game; i++)
    {
        //输入棋盘
        int winner[3] = {0};
        int arr[N][N] = {0};
        int size = 0;
        scanf("%d", &size);
        for(int j = 1; j < size + 1; j++)
        {
            for(int k = 1; k < size + 1; k++)
            {
                scanf("%d", &arr[j][k]);
            }
        }
        //对行进行判断
        for(int j = 1; j < size + 1; j++)
        {
            //统计一行里面各个元素的个数
            count[0] = 0;
            count[1] = 0;
            count[2] = 0;
            for(int k = 1; k < size + 1; k++)
            {
                if(arr[j][k] == 1)
                {
                    count[0]++;
                }
                else if(arr[j][k] == 2)
                {
                    count[1]++;
                }
                else if(arr[j][k] == 4)
                {
                    count[2]++;
                }
            }
            //先判断谁的数量达标了
            for(int l = 0; l < 3; l++)
            {
                if(count[l] >= number_win)
                {   //判断是否连在一起
                    for(int k = 1; k < size + 3 - number_win; k++)
                    {
                        for(int m = 0; m < number_win - 1; m++)
                        {
                            if(arr[j][k + m] == arr[j][k + m + 1])
                            {
                                winner[l]++;
                            }
                            else
                            {
                                winner[l] = 0;
                            }
                            if(winner[l] == number_win - 1)
                            {
                                winner[l] = 10;
                                goto done1;
                            }
                        }
                    }
                    done1:
                }
            }
        }
        //对列进行判断
        for(int j = 1; j < size + 1; j++)
        {
            //统计一列里面各个元素的个数
            count[0] = 0;
            count[1] = 0;
            count[2] = 0;
            for(int k = 1; k < size + 1; k++)
            {
                if(arr[k][j] == 1)
                {
                    count[0]++;
                }
                else if(arr[k][j] == 2)
                {
                    count[1]++;
                }
                else if(arr[k][j] == 4)
                {
                    count[2]++;
                }
            }
            //先判断谁的数量达标了
            for(int l = 0; l < 3; l++)
            {
                if(count[l] >= number_win)
                {   //判断是否连在一起
                    for(int k = 1; k < size + 3 - number_win; k++)
                    {
                        for(int m = 0; m < number_win - 1; m++)
                        {
                            if(arr[k + m][j] == arr[k + m + 1][j])
                            {
                                winner[l]++;
                            }
                            else
                            {
                                winner[l] = 0;
                            }
                            if(winner[l] == number_win - 1)
                            {
                                winner[l] = 10;
                                goto done2;
                            }
                        }
                    }
                    done2:
                }
            }
        }

        //对主对角线进行判断
        
        //统计主对角线里面各个元素的个数
        count[0] = 0;
        count[1] = 0;
        count[2] = 0;
        //统计每个元素出现的个数
        for(int k = 1; k < size + 1; k++)
        {
            if(arr[k][k] == 1)
            {
                count[0]++;
            }
            else if(arr[k][k] == 2)
            {
                count[1]++;
            }
            else if(arr[k][k] == 4)
            {
                count[2]++;
            }
        }
        //先判断谁的数量达标了
        for(int l = 0; l < 3; l++)
        {
            if(count[l] >= number_win)
            {   //判断是否连在一起
                for(int k = 1; k < size + 3 - number_win; k++)
                {
                    for(int m = 0; m < number_win - 1; m++)
                    {
                        if(arr[k + m][k + m] == arr[k + m + 1][k + m + 1])
                        {
                            winner[l]++;
                        }
                        else
                        {
                            winner[l] = 0;
                        }
                        if(winner[l] == number_win - 1)
                        {
                            winner[l] = 10;
                            goto done3;
                        }
                    }
                }
                done3:
            }
        }

        //对副对角线进行判断
        //统计副对角线里面各个元素的个数
        count[0] = 0;
        count[1] = 0;
        count[2] = 0;
        //统计每个元素出现的个数
        for(int k = 1; k < size + 1; k++)
        {
            if(arr[k][size + 1 - k] == 1)
            {
                count[0]++;
            }
            else if(arr[k][size + 1 - k] == 2)
            {
                count[1]++;
            }
            else if(arr[k][size + 1 - k] == 4)
            {
                count[2]++;
            }
        }
        //先判断谁的数量达标了
        for(int l = 0; l < 3; l++)
        {
            if(count[l] >= number_win)
            {   //判断是否连在一起
                for(int k = 1; k < size + 3 - number_win; k++)
                {
                    for(int m = 0; m < number_win - 1; m++)
                    {
                        if(arr[k + m][size + 1 - k - m] == arr[k + m + 1][size + 1 - k - m - 1])
                        {
                            winner[l]++;
                        }
                        else
                        {
                            winner[l] = 0;
                        }
                        if(winner[l] == number_win - 1)
                        {
                            winner[l] = 10;
                            goto done4;
                        }
                    }
                }
                done4:
            }
        }
    
        //输出
        if(winner[0] == 10)
        {
            if(winner[1] == 10 || winner[2] == 10)
            {
                printf("draw\n");
            }
            else
            {
                printf("1\n");
            }
        }
        else
        {
            if(winner[1] == 10 && winner[2] == 10)
            {
                printf("draw\n");
            }
            else if(winner[1] == 10)
            {
                printf("2\n");
            }
            else if(winner[2] == 10)
            {
                printf("4\n");
            }
            else
            {
                printf("draw\n");
            }
        }
    }
}