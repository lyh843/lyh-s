#include<stdio.h>

int main(void)
{
    int hour, minute;

    scanf("%d:%d", &hour, &minute);

    if((hour < 12 && hour > 0 ) || (hour == 0 && minute != 0))
    {
        printf("%.2d:%.2d a.m.", hour, minute);
    }
    else if(hour > 12)
    {
        hour = hour - 12;
        printf("%.2d:%.2d p.m.", hour, minute);
    }
    else if(hour == 12)
    {
        printf("12:%.2d p.m.", minute);
    }
    else if(hour == 0 && minute == 0)
    {
        printf("00:00 a.m.");
    }
    return 0;
}
