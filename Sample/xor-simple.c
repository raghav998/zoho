/*
i/p
2
2
3

o/p
1 2
3 2
*/
#include <stdio.h>
#include <malloc.h>
int power(int base,int poww)
{
    int ans=1;
    for(int i=0;i<poww;i++)
        ans*=base;
    return ans;
}
int main()
{
    int tn,t,n,i,j;
    scanf("%d",&tn);
    for(t=0;t<tn;t++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            if(power(2,i)>=n)
                break;
        }
        int max,count,t;
        max=power(2,i)-1;
        count=0;
        n-=power(2,i-1);
        count=n*2;
        printf("%d %d\n",max,count);
    }
    return 0;
}
