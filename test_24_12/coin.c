#include <stdio.h>
int arr[3][3] = {0};
int coin[3] = {0};
int result = 0;
void f_operate()
{
    int temp_re = 0;
    for(int i1 = 0; i1 < 3; i1++)
    {
        for(int j1 = 0; j1 < 3; j1++)
        {
            for(int i2 = 0; i2 < 3; i2++)
            {
                for(int j2 = 0; j2 < 3; j2++)
                {
                    for(int i3 = 0; i3 < 3; i3++)
                    {
                        for(int j3 = 0; j3 < 3; j3++)
                        {
                            if(((i2 - i1) * (j3 - j1) - (j2 - j1) * (i3 - i1)) != 0)
                            {
                                temp_re = coin[0] * arr[i1][j1] + coin[1] * arr[i2][j2] + coin[2] * arr[i3][j3];
                                if(temp_re > result)
                                {
                                    result = temp_re;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int main(void)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0; i < 3; i++)
    {
        scanf("%d", &coin[i]);
    }
    f_operate();
    printf("%d",result);
    return 0;
}