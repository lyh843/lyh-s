#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#define N 100001
void f_query(int arr1[N], int arr2[N], int len)
{
    printf("%d\n", len);
    for(int i = len - 1; i >=0; i--)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
}
void f_ask(int *pt_arr1, int *pt_arr2, int *pt_len_arr, int id, int size_id)//数组是倒着的
{
    bool findout = false;
    for(int i = 0; i < 31; i++)
    {
        if(size_id > pow(2, i) && size_id <= pow(2, i + 1))//判断需要的空间大小
        {
            size_id = i + 1;
            break;
        }
        else if(size_id == 1)
        {
            size_id = 0;
            break;
        }   
    }
    //开始找
    while(!findout)
    {
        //看看有没有刚好的
        for(int i = *pt_len_arr - 1; i >= 0; i--)
        {
            if(size_id == *(pt_arr2 + i) && *(pt_arr1 + i) == 0)
            {
                *(pt_arr1 + i) = id;
                findout = true;
            }
        }
        //没有就得创了
        A:
        for(int i = 1; !findout; i++)//找大小最接近的，i是相差的大小
        {
            for(int j = *pt_len_arr - 1; j >= 0; j--)
            {
                if(*(pt_arr1 + j) == 0 && *(pt_arr2 + j) == size_id + i)//找到了第一个
                {
                    (*pt_len_arr)++;
                    for(int k = *pt_len_arr - 1; k > j + 1; k--)//后面的先退退
                    {  
                        *(pt_arr1 + k) = *(pt_arr1 + k - 1);
                        *(pt_arr2 + k) = *(pt_arr2 + k - 1);
                    }
                    (*(pt_arr2 + j))--;
                    *(pt_arr2 + j + 1) = *(pt_arr2 + j);
                    *(pt_arr1 + j + 1) = 0;
                    if(*(pt_arr2 + j + 1) == size_id)//虽然裂开了，但是不一定是对的，可能得裂多几次
                    {
                        findout = true;
                        *(pt_arr1 + j + 1) = id;
                    }
                    goto A;
                }
            }
        }
    }
}
int main(void)
{
    int arr1[N], arr2[N], len_arr = 1;//arr1_id， arr2_size_id
    memset(arr1, 0, sizeof(arr1));
    memset(arr2, 0, sizeof(arr2));
    int room = 0, times = 0;
    char op[2] = "0";
    scanf("%d%d", &room, &times);
    arr2[0] = room;//只取指数
    for(int i = 0; i < times; i++)
    {
        getchar();
        scanf("%c", &op[0]);
        if(op[0] == 'Q')
        {
            f_query(arr1, arr2, len_arr);
        }
        else if(op[0] == 'A')
        {
            int id = 0, size_id = 0;
            scanf("%d%d", &id, &size_id);
            f_ask(arr1, arr2, &len_arr, id, size_id);
        }
    }
    return 0;
}
