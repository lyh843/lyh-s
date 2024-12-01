#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define N 102
#define M 102
int f_find(char map[N][M], int row, int col)
{
    int result = 0;
    bool judge = true;
    for(int i = 1; i * 2 <= row && i * 2 <= col; i++)//i是目前要数的正方形的边长
    {
        for(int j = 1; j <= row - i; j++)//起始位置到终止位置
        {
            for(int k = i - 1; k <= col - i; k++)//起始位置到终止位置
            {
                if(map[j][k] == '/' && map[j][k + 1] == '\\')
                {
                    judge = true;
                    for(int l = 0; l < i; l++)
                    {
                        if(map[j + l][k - l] == '/' && map[j + l][k + 1 + l] == '\\')
                        {
                            
                        }
                        else
                        {
                            judge = false;
                        }
                        if(map[j + i + l][k - i + l + 1] == '\\' && map[j + i + l][k + i - l] == '/')
                        {
                        }
                        else
                        {
                            judge = false;
                        }
                    }
                    if(judge)
                    {
                        result++;
                    }
                }
            }
        }
    }
    return result;
}
int main(void)
{
    int row = 0, col = 0;
    char map[N][M];
    int result = 0;
    memset(map, 0, sizeof(map));
    scanf("%d%d", &row, &col);
    for(int i = 1; i < row + 1; i++)
    {
        scanf("%s", map[i]);
    }
    result = f_find(map, row, col);
    printf("%d", result);
}