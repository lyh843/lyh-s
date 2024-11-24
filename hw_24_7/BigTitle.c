#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 5000
int main(void)
{
    char *sentence = (char*)malloc(N);
    memset(sentence, 0, N);
    while(scanf("%s", sentence) != EOF)
    {
        int len = strlen(sentence);
        if(*sentence >= 'A'&& *sentence <= 'Z')
        {
            printf("%c", *sentence);
        }
        else
        {
            printf("%c", *sentence - 'a' + 'A');
        }
        for(int i = 1; i < len; i++)
        {
            if(*(sentence + i) >= 'a' && *(sentence + i) <= 'z')
            {
                printf("%c", *(sentence + i));
            }
            else
            {
                printf("%c", *(sentence + i) - 'A' + 'a');
            }
        }
        printf(" ");
    }
    free(sentence);
    return 0;
}