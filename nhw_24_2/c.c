#include<stdio.h>
//unsigned long long 对应是lu
int main (void)
{
    unsigned long long year[2] = {0};
    unsigned long long fri_year, last_year, num_year;
    scanf("%d", &fri_year);
    scanf("%d", &num_year);
    last_year = fri_year + num_year;
    year[0] = fri_year;
    year[1] = last_year;
    
    for(int i = 0; i < 2; i++)
    {
        if(year[i] % 4 != 0 )
        {
            printf("Normal year!\n");
        }
        else if(year[i] % 4 == 0 && year[i] % 100 != 0)
        {
            printf("Leap year!\n"); 
        }
        else if(year[i] % 100 == 0 && year[i] % 400 != 0)
        {
            printf("Normal year!\n");
        }
        else if(year[i] % 400 == 0)
        {
            printf("Leap year!\n");
        }
    }
}