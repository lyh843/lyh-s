#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define N 100001
void f_judge(char *pt_string, bool *pt_judge)
{

}
int main(void)
{
    int times = 0;
    char string[N];
    bool judge = true;
    memset(string, 0, sizeof(string));
    scanf("%d", &times);
    for(int i = 0; i < times; i++)
    {
        scanf("%s", string);
        f_judge(string, &judge);
    }
}