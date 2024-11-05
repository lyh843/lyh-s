#include<stdio.h>
#include<string.h>

int main(void)
{
    int arr[9][9] = {0};
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int row_count[9] = {0}, col_count[9] = {0}, gong_count[9] = {0};
    //检查行
    for(int i = 0; i < 9; i++)
    {
        memset(row_count, 0, sizeof(row_count));
        for(int k = 0; k < 9; k++)
        {
            row_count[arr[i][k] - 1]++;
        }
        for(int k = 0; k < 9; k++)
        {
            if(row_count[k] == 0)
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    //检查列
    for(int i = 0; i < 9; i++)
    {
        memset(col_count, 0, sizeof(col_count));
        for(int k = 0; k < 9; k++)
        {
            col_count[arr[k][i] - 1]++;
        }
        for(int k = 0; k < 9; k++)
        {
            if(col_count[k] == 0)
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    //检查宫
    for(int i = 0; i < 9; i += 3)
    {
        memset(gong_count, 0, sizeof(gong_count));
        for(int j = 0; j < 9; j += 3)
        {
            gong_count[arr[i][j] - 1]++; gong_count[arr[i][j + 1] - 1]++; gong_count[arr[i][j + 2] - 1]++;
            gong_count[arr[i + 1][j] - 1]++; gong_count[arr[i + 1][j + 1] - 1]++; gong_count[arr[i + 1][j + 2] - 1]++;
            gong_count[arr[i + 2][j] - 1]++; gong_count[arr[i + 2][j + 1] - 1]++; gong_count[arr[i + 2][j + 2] - 1]++;
            for(int j = 0; j < 9; j++)
            {
                if(gong_count[j] == 0)
                {
                    printf("NO\n");
                    return 0;
                }
            }
        }
        
    }

    printf("YES\n");
    return 0;
}