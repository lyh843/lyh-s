#include<stdio.h>

int main(void)
{
    int arr[18] = {0, 0, 1, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 1, 1, 1, 0, 1};
    int num;
    int num_q;
    int answer1 = 0;
    int answer2 = 0;
    int answer3 = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &num_q);
        if(arr[num_q - 1] == 0)
        {
            answer1 &= 0; 
            answer2 |= 0; 
            answer3 ^= 0;
        }
        else
        {
            answer1 &= num_q;
            answer2 |= num_q;
            answer3 ^= num_q;
        }
    }
    printf("%d %d %d", answer1, answer2, answer3);
}