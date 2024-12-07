#include <stdio.h>

#define N (10000000 + 50)
#define inf 0x7fffffff

int n, m, t, a[N], b[N];

int min(int x, int y) 
{
    return x > y ? y : x;
}

int solve(int v) //v是b中的第i个元素
{
    int l = 0, r = n - 1, mid, ret = -1;//ret是返回值
    while (l <= r) //二分法经典闭区间写法， l是下界， r是上界
    {
        mid = (l + r) / 2;//取中间值
        if (v + a[mid] <= t && (ret == -1 || a[mid] >= a[ret])) //如果（b这个元素加上中间值要小于t） 且 （这次是第一次二分或者这次二分的结果要比返回值更大）
        //ret == -1 -> 第一次二分， 如果b + 这个中间值小于t， 可以往更大的中间值找
        //a[mid] >= a[ret] -> 不是第一次二分，但是这次新的二分的值比之前的更大，而且还满足b + 这个中间值小于t
        { 
            ret = mid;
            l = mid + 1;//把下限调高
        } 
        else 
        {
            r = mid - 1;//把上限调低
        }
    }
    return ret == -1 ? inf : t - v - a[ret];
}

int main() 
{
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) 
    {
        scanf("%d", &b[i]);
    }
    int ans = inf;
    for (int i = 0; i < m; i++) 
    {
        ans = min(ans, solve(b[i]));
    }
    printf("%d", (ans == inf) ? -1 : ans);
    return 0;
}