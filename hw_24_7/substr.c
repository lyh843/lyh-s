#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define N 100005
int main(void)
{
    char *string1 = (char *)malloc(N);
    char *string2 = (char *)malloc(N);
    memset(string1, 0, N);
    memset(string2, 0, N);
    scanf("%s", string1);
    scanf("%s", string2);
    int len1 = strlen(string1);
    int len2 = strlen(string2);
    bool judge = true;
    for(int i = 0; i < len1; i++)
    {
        if(*(string1 + i) == *(string2))
        {
            judge = true;
            for(int j = 1; j < len2; j++)
            {
                if(*(string1 + i + j) != *(string2 + j))
                {
                    judge = false;
                    break;
                }
            }
            if(judge)
            {
                printf("%d ", i);
            }
        }
    }
}