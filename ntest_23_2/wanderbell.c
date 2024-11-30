#include<stdio.h>
#include<stdbool.h>
#define N 3010
int size_row = 0, size_col = 0;
char map[N][N] = {0};
bool judge = true;
int step = 0;
void f_input();
void f_search();
bool f_up(int, int);
bool f_down(int, int);
bool f_left(int, int);
bool f_right(int, int);
void f_input()
{
    scanf("%d%d", &size_row, &size_col);
    for(int i = 0; i < size_row; i++)
    {
        scanf("%s", map[i]);
    }
}
void f_search()
{
    bool up = false, down = false, left = false, right = false;
    for(int i = 0; i < size_row && judge; i++)
    {
        for(int j = 0; j < size_col && judge; j++)
        {
            if(map[i][j] != '.')
            {
                up = f_up(i, j);
                down = f_down(i, j);
                left = f_left(i, j);
                right = f_right(i, j);
                if(map[i][j] == 'U' && up == true || map[i][j] == 'D' && down == true || map[i][j] == 'R' && right == true || map[i][j] == 'L' && left == true)
                {
                }
                else if(!up && !down && !right && !left)
                {
                    judge = false;
                }
                else
                {
                    step++;
                }
            }
        }
    }
}
bool f_up(int loc_row, int loc_col)
{
    for(int i = 1; i < loc_row + 1; i++)
    {
        if(map[loc_row - i][loc_col] != '.')
        {
            return true;
        }
    }
    return false;
}
bool f_down(int loc_row, int loc_col)
{
    for(int i = 1; i < size_row - loc_row; i++)
    {
        if(map[loc_row + i][loc_col] != '.')
        {
            return true;
        }
    }
    return false;
}
bool f_left(int loc_row, int loc_col)
{
    for(int i = 1; i < loc_col + 1; i++)
    {
        if(map[loc_row][loc_col - i] != '.')
        {
            return true;
        }
    }
    return false;
}
bool f_right(int loc_row, int loc_col)
{
    for(int i = 1; i < size_col - loc_col; i++)
    {
        if(map[loc_row][loc_col + i] != '.')
        {
            return true;
        }
    }
    return false;
}
int main(void)
{
    f_input();
    f_search();
    if(judge)
    {
        printf("%d\n", step);
    }
    else
    {
        printf("-1\n");
    }
}