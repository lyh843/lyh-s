//有三个存活，则自己复活
/* any live cell with two or three live neighbours survives
* all other live cells die in the next generation
* 
* any dead cell with three live neighbours becomes a live cell
* all other 
*/
#include<stdio.h> 
#define N 6
#define M 6
int main(void)
{
    //original arr
    const int arr[N][M] = 
    {
        {0},
        {0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 0}
    };
    //create a arr1
    int arr1[N + 2][M + 2] = {0};
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            arr1[i][j] = arr[i -1][j - 1];
        }
    }
    for(int turn =0; turn < 10; turn++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= M; j++)
            {
                int lives =0;
                lives += arr1[i - 1][j - 1] + arr1[i - 1][j] + arr1[i - 1][j + 1];
                lives += arr1[i][j - 1] + arr1[i][j + 1];
                lives += arr1[i + 1][j - 1] + arr1[i + 1][j] + arr1[i + 1][j + 1];
                if(arr1[i][j] == 1)
                {
                    if(lives == 2 || lives == 3)
                    {
                        arr1[i][j] == 1;
                    }
                    else
                    {
                        arr1[i][j] == 0;
                    }
                }
            }
        }


        //输出
        for(int i = 1; i <=N; i++)
        {
            for(int j = 1; j <= M; j++)
            {
                if(arr1[i][j] > 0)
                {
                    printf("*");
                }
                else
                {
                    printf("#");
                }
            }
            printf("\n");
        }
        
    }
}