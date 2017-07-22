/*
3
aeiou
hackerearth
correct

0 4 4 6 6
7 -7 2 8 -6 13 13 -4 -9 2 -12
2 12 3 0 13 -2 -9
*/
#include <stdio.h>
#include <malloc.h>
int stringLength(char *a)
{
    int i;
    for(i=0;a[i]!='\0';i++);
    return i;
}
int diff(int s,int e)
{
    int clk,anclk;
    clk=anclk=s;
    if(s==e)
        return 0;
    for(int i=0;i<26;i++)
    {
        if(clk==25)
            clk=0;
        else
            clk++;
        if(anclk==0)
            anclk=25;
        else
            anclk--;
        if(clk==e)
            return i+1;
        if(anclk==e)
            return -i-1;
    }
}
void p(int n)
{
    printf("%d ",n);
}
void func(int *a,int n)
{
    int clk,anclk;
    printf("\n");
    p(a[0]);
    for(int i=1;i<n;i++)
    {
        p(diff(a[i-1],a[i]));
    }
}
int main()
{
    int tn,t,i;
    char a[100];
    scanf("%d",&tn);
    for(t=0;t<tn;t++)
    {
        scanf("%s",a);
        int *ans=(int*)calloc(stringLength(a),sizeof(int));
        int ch;
        for(i=0;a[i]!='\0';i++)
        {
            ch=(int)a[i];
            ch-=97;
            ans[i]=ch;
        }
        func(ans,stringLength(a));
    }
    return 0;
}
