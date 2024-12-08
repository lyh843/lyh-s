#include <stdio.h>
#include <stdbool.h>
#define N  1000010
int days_cat[N] = {0};
int range1 = -1, range2 = 0, amount = 0, re_2 = 0;
long long re_days = 0;
bool f_judge1(int mid)
{
    int count = 0;
    for(int i = 0; i < amount; i++)
    {
        if(days_cat[i] > mid && days_cat[i] < range2)
        {
            count++;
        }
    }
    if(count >= re_2)
    {
        return true;
    }
    return false;
}
bool f_judge2(int mid)
{
    long long sum_days = 0;
    for(int i = 0; i < amount; i++)
    {
        if(days_cat[i] > mid && days_cat[i] < range2)
        {
            sum_days += days_cat[i] - mid;
        }
    }
    if(sum_days >= re_days)
    {
        return true;
    }
    return false;
}
void f_find_range1()
{
    int start = 0; int end = range2 - 1;
    int mid = start + (end - start) / 2;
    while(start <= end)
    {
        if(f_judge1(mid) && f_judge2(mid))
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    range1 = start - 1;
}
int main(void)
{
    scanf("%d%d%d%lld", &amount, &range2, &re_2, &re_days);
    for(int i = 0; i < amount; i++)
    {
        scanf("%d", &days_cat[i]);
    }
    f_find_range1();
    printf("%d", range1);
    return 0;
}