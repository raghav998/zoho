#include <stdio.h>
#include <malloc.h>
int stringLength(char a[])
{
    int i;
    for(i=0;a[i]!='\0';i++);
    return i;
}
int check(int a[])
{
    for(int i=0;i<26;i++)
        if(!a[i])
            return 0;
    return 1;
}
int main()
{
    int tn,t,len,i,tmp;
    char a[100];
    scanf("%d",&tn);
    for(t=0;t<tn;t++)
    {
        scanf("%s",a);
        int *alph;
        alph=(int*)calloc(26,sizeof(int));
        len=stringLength(a);
        for(i=0;i<len;i++)
        {
            tmp=a[i]-97;
            alph[tmp]++;
        }
        if(check(alph))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
