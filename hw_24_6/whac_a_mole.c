#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>
#define N 10//开成710的
#define M 2 //初始坐标
#define O 100000
int value_map[N][N] = {0};//从50开始存储
int size_row = 0, size_col = 0, size_ham = 0;
int loc_row = M, loc_col = M;
int end_row = 0, end_col = 0;
int count = 0;
int result_arr[3][O] = {0}, num_result = 0;//第一层存最大值，二三层存x y值
bool left = false, right = false, down = false;
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
    count = f_count();//第一次先数范围内全部的
    do
    {
        if(count > result_arr[0][0])
        {
            memset(result_arr, 0, sizeof(result_arr));
            num_result = 1;
            result_arr[0][0] = count;
            result_arr[1][0] = loc_row - M + 1;
            result_arr[2][0] = loc_col - M + 1;
        }
        else if(count == result_arr[0][0])
        {
            num_result++;
            result_arr[1][num_result - 1] = loc_row - M + 1;
            result_arr[2][num_result - 1] = loc_col - M + 1;
        }
        f_next();//移动以及计数操作
    }
    while(loc_row != end_row || loc_col != end_col);
    int max = f_count();//最后一次
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
void f_next()//先走再数
{
    if(loc_row % 2 == 0)//往右走
    {
        if(loc_col == M + size_col - 1)
        {
            loc_row++;
            down = true;
            f_count();
            down = false;
        }
        else
        {
            loc_col++;
            right = true;
            f_count();
            right = false;
        }
    }
    else//往左走
    {
        if(loc_col == M)
        {
            loc_row++;
            down = true;
            f_count();
            down = false;
        }
        else
        {
            loc_col--;
            left = true;
            f_count();
            left = false;
        }
    }
}
int f_count()
{
    if(down)
    {
        for(int i = -size_ham; i <= size_ham; i++)
        {
            count += value_map[loc_row + size_ham - abs(i)][loc_col + i];
            count -= value_map[loc_row - size_ham + abs(i) - 1][loc_col + i];
        }
    }
    else if(right)
    {
        for(int i = -size_ham; i<= size_ham; i++)
        {
            count += value_map[loc_row + i][loc_col + size_ham - abs(i)];
            count -= value_map[loc_row + i][loc_col - size_ham + abs(i) - 1];
        }
    }
    else if(left)
    {
        for(int i = -size_ham; i<= size_ham; i++)
        {
            count += value_map[loc_row + i][loc_col - size_ham + abs(i)];
            count -= value_map[loc_row + i][loc_col + size_ham - abs(i) + 1];
        }
    }
    else
    {
        count = 0;
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
    result_arr[0][0] = INT_MIN;
    f_input();//录入数据
    if(size_row % 2 == 0)//判断结束位置
    {
        end_row = M + size_row - 1;
        end_col = M;        
    }
    else
    {
        end_row = M + size_row - 1;
        end_col = M + size_col - 1;
    }
    f_hit();//打地鼠！
    f_print();//输出
    return 0;
}