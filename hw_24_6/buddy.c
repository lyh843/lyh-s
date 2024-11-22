#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#define N 100
void f_query(int arr[2][N], int len)
{
    printf("%d", len);
    for(int i = len - 1; i >=0; i--)
    {
        printf("%d ", arr[0][i]);
    }
}
void f_ask(int *pt_arr[2][N], int * pt_len_arr, int id, int size_id)//数组是倒着的
{
    bool findout = false;
    for(int i = 0; i < 31; i++)
    {
        if(size_id >= pow(2, i) && size_id <= pow(2, i + 1))
        {
            size_id = i + 1;
            break;
        }
    }
    while(!findout)
    {
        //看看有没有刚好的
        for(int i = *pt_len_arr - 1; i >= 0; i--)
        {
            if(size_id == *pt_arr[1][i] && *pt_arr[0][i] == 0)
            {
                *pt_arr[0][i] = id;
                findout = true;
            }
        }
        //没有就得创了
        for(int i = 1; !findout; i++)//找最接近的
        {
            for(int j = *pt_len_arr - 1; j >= 0; j--)
            {
                if(*pt_arr[0][j] == 0 && *pt_arr[1][j] == size_id + i)
                {
                    (*pt_len_arr)++;
                    for(int k = *pt_len_arr - 1; k > j + 1; k++)//后面的先退退
                    {  
                        *pt_arr[0][k] = *pt_arr[0][k - 1];
                        *pt_arr[1][k] = *pt_arr[1][k - 1];
                    }
                    (*pt_arr[1][j])--;
                    *pt_arr[1][j + 1] = *pt_arr[1][j];
                    *pt_arr[0][j + 1] = 0;
                    if(*pt_arr[1][j] == size_id)
                    {
                        findout = true;
                        *pt_arr[0][j] = id;
                        *pt_arr[1][j] = size_id;
                        break;
                    }
                }
            }
        }
    }
}
int main(void)
{
    int arr[2][N], len_arr = 1;//第一层id， 第二层空间大小
    memset(arr, 0, sizeof(arr));
    int room = 0, times = 0;
    char op[2] = "0";
    scanf("%d%d", &room, &times);
    arr[2][0] = room;//只取指数
    for(int i = 0; i < times; i++)
    {
        getchar();
        scanf("%c", &op[0]);
        if(op[0] == 'Q')
        {
            f_query(arr, len_arr);
        }
        else if(op[0] == 'A')
        {
            int id = 0, size_id = 0;
            scanf("%d%d", &id, &size_id);
            f_ask(arr, &len_arr, id, size_id);
        }
    }
    return 0;
}
