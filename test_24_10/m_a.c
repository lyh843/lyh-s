#include<stdio.h>
int a[1001];
int main()
{
    int m=0;
    int flag=0;//跟sum的功能重复了
    int sum=0;
    int b=0;
    scanf("%d",&m);
    for(int i=0;i<m;i++)//输入数组
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m-1;i++)//？对布尔类型还是不太会用啊
    {
        
        if(a[i]<=a[i + 1])
        {
            //flag=0;
            //sum+=flag;
        }
        else
        {
            sum++;
        }
        /*
        if(a[i-1]>a[i])
        {
            flag=1;
            sum+=flag;
        }
        */
    }
    if(sum != 0)
    {

    }
    else
    {
        for(int i = 1; i < m - 1; i++)
        {
            if(a[i-1]+a[i+1]>2*a[i])//一开始的"&&sum==0"是想直接跳过是吧，可以外面嵌套一个if判断
            {
                b++;
            }   
            else b=0;
            //你这样用bool类型会出现一个问题
            //比如我第一个是不满足的，那么b会赋值成0
            //但是只要后面的满足，或者说，只要最后一个满足，你的b就大于0
        }
    }
    

    if(sum==0 && b==0) printf("0");
    else if(sum==0 && b!=0) printf("1");
    else if(sum>0) printf("-1");
    return 0;
}