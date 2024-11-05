#include<stdio.h>

int count(char map[10][10], int size, int row, int col)
{
    int count1 = 0;
    for(int i = -1; i < 2; i++)
    {
        for(int j = -1; j < 2; j++)
        {
            if(i == 0 && j == 0)
            {

            }
            else
            {
                if(map[row + i][col + j] == '*')
                {
                    count1++;
                }
            }
        }
    }
    return count1;
}


int main(void)
{
    int size = 0;
    scanf("%d", &size);
    char map[10][10] = {0};
    char result[10][10] = {0};
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            scanf("%1s", &map[i][j]);
        }
    }

    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            switch(map[i][j])
            {
                case 'o':
                {
                    result[i][j] = count(map, size, i, j) + 48;
                    break;
                }
                case '*':
                {
                    result[i][j] = '*';
                    break;
                }
                default:
                    break;
            }
        }
    }

    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            if(result[i][j] >= 48 && result[i][j] <= 57)
            {
                printf("%d", (int)result[i][j] - 48);
            }
            else
            {
                printf("%c", result[i][j]);
            }
        }
        printf("\n");
    }
}