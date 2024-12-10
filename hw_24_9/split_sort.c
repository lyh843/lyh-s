#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 101
#define M 100
#define O 1000000
char op[2] = {0};
char *string[N] = {0};
char input[O] = {0};
int num_group = 0;
int f_compare(const void *a, const void *b)
{
    char *a1 = *(char **)a;
    char *b1 = *(char **)b;
    int result = strcmp(a1, b1);
    return result;
}
void f_divid()
{
    string[0] = strtok(input, op);
    for(num_group = 1; ;num_group++)
    {
        string[num_group] = strtok(NULL, op);
        if(string[num_group] == NULL)
        {
            string[num_group] = strtok(NULL,"\n");
            break;
        }
    }
}
int main(void)
{
    scanf("%s", input);
    scanf("%s", op);
    f_divid();
    qsort(string, num_group, sizeof(char *), f_compare);
    for(int j = 0; j < num_group; j++)
    {
        printf("%s\n", string[j]);
    }
}