#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define N 10
char map[N][N][N] = {0};
short int num_arr[200][3] = {0};
int num_num = 0; 
void f_input(int, int arr2[3]);
void f_judge(int arr2[3], bool *, int[100][3], int *);
int f_count(int, int, int);
int vectors[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
void f_input(int size, int ques_arr[3])
{
    char input = '0';
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            for(int k = 1; k <= size; k++)
            {
                scanf("%c", &input);
                if(input >= 48 && input <= 55)
                {
                    map[i][j][k] = input;
                    num_arr[num_num][0] = i;
                    num_arr[num_num][1] = j;
                    num_arr[num_num][2] = k;
                    num_num++;
                }
                else if(input == '*')
                {
                    map[i][j][k] = '*';
                }
                else if(input == '?')
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
void f_judge(int ques_arr[3], bool *pt_judge, int arr[100][3], int *pt_num_wrong)
{
    for(int i = 0; i < num_num; i++)
    {
        if(map[num_arr[i][0]][num_arr[i][1]][num_arr[i][2]] != f_count(num_arr[i][0], num_arr[i][1], num_arr[i][2]) + '0')
        {
            *pt_judge = false;
            (*pt_num_wrong)++;
            arr[*pt_num_wrong][0] = num_arr[i][0];
            arr[*pt_num_wrong][1] = num_arr[i][1];
            arr[*pt_num_wrong][2] = num_arr[i][2];
        }
    }
}
int f_count(int loc_1, int loc_2, int loc_3)
{
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
void f_judge_surround(int ques_arr[3], int wrong_arr[100][3], int num_wrong, bool *judge2, bool *judge3)
{
    for(int i = 1; i <= num_wrong; i++)
    {
        if((abs(wrong_arr[i][0] - ques_arr[0]) + abs(wrong_arr[i][1] - ques_arr[1]) + abs(wrong_arr[i][2] - ques_arr[2]) ) != 1)
        {
            *judge2 = false;
            break;
        }
    }
    if(judge2)
    {
        for(int i = 1; i <= num_wrong; i++)
        {
            if(map[wrong_arr[i][0]][wrong_arr[i][1]][wrong_arr[i][2]] != f_count(wrong_arr[i][0], wrong_arr[i][1], wrong_arr[i][2]) - 1 + '0')
            {
                *judge3 = false;
                break;
            }
        }
    }

}
int main(void)
{
    int size = 0;
    int ques_arr[3] = {0};//存储问号的位置
    int wrong_arr[100][3] = {0}, num_wrong = 0;
    char input = '0';
    bool judge1 = true;//第一遍，问号为雷，看看有没有错
    bool judge2 = true;//判断错的在不在问号旁边
    bool judge3 = true;//前提：错的都在问号旁边，问号改成数字后，对不对
    scanf("%d", &size);
    getchar();
    f_input(size, ques_arr);
    // f_judge(ques_arr, &judge1, wrong_arr, &num_wrong);//第一遍
    // if(!judge1 && num_wrong <= 6)
    // {
    //     f_judge_surround(ques_arr, wrong_arr, num_wrong, &judge2, &judge3);
    // }
    // if(judge1 || (!judge1 && judge3 && judge2))
    // {
    //     printf("valid\n");
    //     printf("%d\n", f_count(ques_arr[0], ques_arr[1], ques_arr[2]));
    // }
    // else
    // {
    //     printf("invalid\n");
    //     for(int i = 1; i <= num_wrong; i++)
    //     {
    //         printf("%d %d %d\n", wrong_arr[i][0], wrong_arr[i][1], wrong_arr[i][2]);
    //     }
    // }
}