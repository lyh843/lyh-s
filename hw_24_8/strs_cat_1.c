#include<stdio.h>
#include<string.h>
#define N 1004
char *string1, *string2;
int f_mystrcat(char *string1, char *string2, int len1, int len2)
{
    int result = 0;
    char *target = (char*)malloc(N);
    memset(target , 0, N);
    for(int i = 1; i <= len2 && i <= len1; i++)
    {
        strcpy(target, string1 + len1 - i); 
        if(strstr(string2, target) == string2)
        {
            result = i;
            continue;
        }
    }
    return result;
}
int main(void)
{
    int times = 0;
    string1 = (char*)malloc(N);
    string2 = (char*)malloc(N);
    memset(string1, 0, N);
    memset(string2, 0, N);
    int begin2 = 0;
    int len1 = 0, len2 = 0;
    scanf("%d", &times);
    while(times--)
    {
        scanf("%s", string1);
        scanf("%s", string2);
        len1 = strlen(string1);
        len2 = strlen(string2);
        int loc = f_mystrcat(string1, string2, len1, len2);
        printf("%s", string1);
        printf("%s\n", string2 + loc);
    }
    return 0;
}