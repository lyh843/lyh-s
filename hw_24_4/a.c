#include <stdio.h>
int getBit(int a, int b) 
{ 
    return (a >> b) & 1; 
}
int popcount(int x) 
{
    int cnt = 0;
    while (x) 
    {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",a&b);
    printf("%d\n",a|b);
    printf("%d\n",a ^ b);
    printf("%d\n",~a);
    printf("%d\n",a << b);
    printf("%d\n",a>>b);
    printf("%d\n",getBit(a,b));
    printf("%d",popcount(a));
}