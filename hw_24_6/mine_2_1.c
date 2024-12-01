//扫雷检测最终版
#include<stdio.h>
#include<stdbool.h>
#define N 10
char map[N][N][N] = {0};
void f_input(int, int arr2[3]);
int f_judge(int arr2[3], int, bool *, int[100][3], int *, int );
int f_count(int, int, int);
void f_input(int size, int ques_arr[3])
{
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            for(int k = 1; k <= size; k++)
            {
                map[i][j][k] = getchar();
                if(map[i][j][k] == '?')
                {
                    map[i][j][k] = '*';//占个位
                    ques_arr[0] = i;
                    ques_arr[1] = j;
                    ques_arr[2] = k;
                }
            }
        }
    }
}
int f_judge(int ques_arr[3], int size, bool *judge, int arr[100][3], int *pt_num_wrong, int times)
{
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            for(int k = 1; k <= size; k++)
            {
                if(map[i][j][k] != '*')
                {
                    if(map[i][j][k] != f_count(i, j, k) + '0')
                    {
                        *judge = false;
                        if(times == 1)
                        {
                            return 0;
                        }
                        arr[*pt_num_wrong][0] = i;
                        arr[*pt_num_wrong][1] = j;
                        arr[*pt_num_wrong][2] = k;
                        (*pt_num_wrong)++;
                    }
                }
            }
        }
    }
}
int f_count(int loc_1, int loc_2, int loc_3)
{
    int vectors[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
    int count = 0;
    for(int i = 0; i < 6; i++)
    {
        int new_loc_1 = loc_1 + vectors[i][0];
        int new_loc_2 = loc_2 + vectors[i][1];
        int new_loc_3 = loc_3 + vectors[i][2];
        if(map[new_loc_1][new_loc_2][new_loc_3] == '*')
        {
            count++;
        }
    }
    return count;
}
int main(void)
{
    int size = 0;
    int ques_arr[3] = {0};//存储问号的位置
    int wrong_arr[100][3] = {0}, num_wrong = 0;
    char input = '0';
    int times = 1;
    bool judge1 = true;//第一遍，问号为数字
    bool judge2 = true;//问号为雷
    scanf("%d", &size);
    getchar();
    f_input(size, ques_arr);
    map[ques_arr[0]][ques_arr[1]][ques_arr[2]] = f_count(ques_arr[0], ques_arr[1], ques_arr[2]) + '0';
    f_judge(ques_arr, size, &judge1, wrong_arr, &num_wrong, times);
    if(!judge1)
    {
        map[ques_arr[0]][ques_arr[1]][ques_arr[2]] = '*';
        times = 2;
        f_judge(ques_arr, size, &judge2, wrong_arr, &num_wrong, times);
    }
    if(judge1)
    {
        printf("valid\n");
        printf("%d\n", f_count(ques_arr[0], ques_arr[1], ques_arr[2]));
    }
    else if(judge2)
    {
        printf("valid\n");
        printf("*\n");
    }
    else
    {
        printf("invalid\n");
        for(int i = 0; i < num_wrong; i++)
        {
            printf("%d %d %d\n", wrong_arr[i][0], wrong_arr[i][1], wrong_arr[i][2]);
        }
    }
}