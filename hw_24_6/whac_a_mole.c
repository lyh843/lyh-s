#include<stdio.h>
#include<string.h>
#define N 10//开成710的
#define M 2 //初始坐标
#define O 100000
int value_map[N][N] = {0};//从50开始存储
int size_row = 0, size_col = 0, size_ham = 0;
int loc_row = M, loc_col = M;
int end_row = 0, end_col = 0;
int result_arr[3][O] = {0}, num_result = 0;//第一层存最大值，二三层存x y值
void f_input();
void f_hit();
void f_next();
int f_count();
void f_print();
void f_input()
{
    scanf("%d%d%d", &size_row, &size_col, &size_ham);
    for(int i = M; i < M + size_row; i++)
    {
        for(int j = M; j < M + size_col; j++)
        {
            scanf("%d", &value_map[i][j]);
        }
    }
}
void f_hit()
{
    do
    {
        int max = f_count();
        if(max > result_arr[0][0])
        {
            memset(result_arr, 0, sizeof(result_arr));
            num_result = 1;
            result_arr[0][0] = max;
            result_arr[1][0] = loc_row - M + 1;
            result_arr[2][0] = loc_col - M + 1;
        }
        else if(max == result_arr[0][0])
        {
            num_result++;
            result_arr[1][num_result - 1] = loc_row - M + 1;
            result_arr[2][num_result - 1] = loc_col - M + 1;
        }
        f_next();
    }
    while(loc_row != end_row || loc_col != end_col);
    int max = f_count();
    if(max > result_arr[0][0])
    {
        memset(result_arr, 0, sizeof(result_arr));
        num_result = 1;
        result_arr[0][0] = max;
        result_arr[1][0] = loc_row - M + 1;
        result_arr[2][0] = loc_col - M + 1;
    }
    else if(max == result_arr[0][0])
    {
        num_result++;
        result_arr[1][num_result - 1] = loc_row - M + 1;
        result_arr[2][num_result - 1] = loc_col - M + 1;
    }

}
void f_next()
{
    if(loc_row % 2 == 0)//往右走
    {
        if(loc_col == M + size_col - 1)
        {
            loc_row++;
        }
        else
        {
            loc_col++;
        }
    }
    else//往左走
    {
        if(loc_col == M)
        {
            loc_row++;
        }
        else
        {
            loc_col--;
        }
    }
}
int f_count()
{
    int count = 0;
    for(int i = size_ham; i >= -size_ham; i--)
    {
        if(i > 0)
        {
            for(int j = size_ham - i; j >= i - size_ham; j--)
            {
                count = count + value_map[loc_row - i][loc_col + j];
            }
        }
        else
        {
            for(int j = size_ham + i; j >= - i -size_ham; j--)
            {
                count = count + value_map[loc_row - i][loc_col + j];
            }
        }
    }
    return count;
}
void f_print()
{
    printf("%d %d\n", result_arr[0][0], num_result);
    for(int i = 0; i < num_result; i++)
    {
        printf("%d %d\n", result_arr[1][i], result_arr[2][i]);
    }
}
int main(void)
{
    f_input();
    if(size_row % 2 == 0)
    {
        end_row = M + size_row - 1;
        end_col = M;        
    }
    else
    {
        end_row = M + size_row - 1;
        end_col = M + size_col - 1;
    }
    f_hit();
    f_print();
    return 0;
}