#include<stdio.h>

int main (void)
{
    int arr[9][9] = {0};
    int arr_r_add[9] = {0};
    int arr_c_add[9] = {0};
    int arr_r_mul[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    int arr_c_mul[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    int arr_s_add[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int arr_s_mul[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int judge = 1;
    //测试行
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            arr_r_add[i] += arr[i][j];
        }
    }
    for(int j = 0; j < 9; j++)
    {
        for(int i = 0; i < 9; i++)
        {
            arr_c_add[j] += arr[i][j]; 
        }
    }
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            arr_r_mul[i] *= arr[i][j];
        }
    }
    for(int j = 0; j < 9; j++)
    {
        for(int i = 0; i < 9; i++)
        {
            arr_c_mul[j] *= arr[i][j]; 
        }
    }
    for(int i = 0; i < 9; i++)
    {
        if(arr_r_add[i] != 45 || arr_c_add[i] !=45 || arr_c_mul[i] != arr_r_mul[i] || arr_c_mul[i] != 6 * 20 * 42 * 72)
        {
            judge = 0;
        }
    }
    arr_s_add[0] = arr[0][0] + arr[0][1] + arr[0][2] + arr[1][0] + arr[1][1] + arr[1][2] + arr[2][0] + arr[2][1] + arr[2][2];
    arr_s_add[1] = arr[0][3] + arr[0][4] + arr[0][5] + arr[1][3] + arr[1][4] + arr[1][5] + arr[2][3] + arr[2][4] + arr[2][5];
    arr_s_add[2] = arr[0][6] + arr[0][7] + arr[0][8] + arr[1][6] + arr[1][7] + arr[1][8] + arr[2][6] + arr[2][7] + arr[2][8];
    arr_s_add[3] = arr[3][0] + arr[3][1] + arr[3][2] + arr[4][0] + arr[4][1] + arr[4][2] + arr[5][0] + arr[5][1] + arr[5][2];
    arr_s_add[4] = arr[3][3] + arr[3][4] + arr[3][5] + arr[4][3] + arr[4][4] + arr[4][5] + arr[5][3] + arr[5][4] + arr[5][5];
    arr_s_add[5] = arr[3][6] + arr[3][7] + arr[3][8] + arr[4][6] + arr[4][7] + arr[4][8] + arr[5][6] + arr[5][7] + arr[5][8];
    arr_s_add[6] = arr[6][0] + arr[6][1] + arr[6][2] + arr[7][0] + arr[7][1] + arr[7][2] + arr[8][0] + arr[8][1] + arr[8][2];
    arr_s_add[7] = arr[6][3] + arr[6][4] + arr[6][5] + arr[7][3] + arr[7][4] + arr[7][5] + arr[8][3] + arr[8][4] + arr[8][5];
    arr_s_add[8] = arr[6][6] + arr[6][7] + arr[6][8] + arr[7][6] + arr[7][7] + arr[7][8] + arr[8][6] + arr[8][7] + arr[8][8];
    for(int i = 0; i < 9; i++)
    {
        if(arr_s_add[i] != 45)
        {
            judge = 0;
        }
    }
    arr_s_mul[0] = arr[0][0] * arr[0][1] * arr[0][2] * arr[1][0] * arr[1][1] * arr[1][2] * arr[2][0] * arr[2][1] * arr[2][2];
    arr_s_mul[1] = arr[0][3] * arr[0][4] * arr[0][5] * arr[1][3] * arr[1][4] * arr[1][5] * arr[2][3] * arr[2][4] * arr[2][5];
    arr_s_mul[2] = arr[0][6] * arr[0][7] * arr[0][8] * arr[1][6] * arr[1][7] * arr[1][8] * arr[2][6] * arr[2][7] * arr[2][8];
    arr_s_mul[3] = arr[3][0] * arr[3][1] * arr[3][2] * arr[4][0] * arr[4][1] * arr[4][2] * arr[5][0] * arr[5][1] * arr[5][2];
    arr_s_mul[4] = arr[3][3] * arr[3][4] * arr[3][5] * arr[4][3] * arr[4][4] * arr[4][5] * arr[5][3] * arr[5][4] * arr[5][5];
    arr_s_mul[5] = arr[3][6] * arr[3][7] * arr[3][8] * arr[4][6] * arr[4][7] * arr[4][8] * arr[5][6] * arr[5][7] * arr[5][8];
    arr_s_mul[6] = arr[6][0] * arr[6][1] * arr[6][2] * arr[7][0] * arr[7][1] * arr[7][2] * arr[8][0] * arr[8][1] * arr[8][2];
    arr_s_mul[7] = arr[6][3] * arr[6][4] * arr[6][5] * arr[7][3] * arr[7][4] * arr[7][5] * arr[8][3] * arr[8][4] * arr[8][5];
    arr_s_mul[8] = arr[6][6] * arr[6][7] * arr[6][8] * arr[7][6] * arr[7][7] * arr[7][8] * arr[8][6] * arr[8][7] * arr[8][8];
    for(int i = 0; i < 9; i++)
    {
        if(arr_s_mul[i] != 6 * 20 * 42 * 72)
        {
            judge = 0;
        }
    }
    for(int k = 0; k < 9; k++)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(i != j && arr[k][i] == arr[k][j])
                {
                    judge = 0;
                }
            }
        }
    }
    for(int k = 0; k < 9; k++)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(i != j && arr[i][k] == arr[j][k])
                {
                    judge = 0;
                }
            }
        }
    }
    if(judge == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}