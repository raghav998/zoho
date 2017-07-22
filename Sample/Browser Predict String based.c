#include <stdio.h>
#include <malloc.h>

int stringLength(char *a)
{
    int i;
    for(i=0;a[i]!='\0';i++);
    return i;
}

int isVowel(char a)
{
    switch(a)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 0;
            break;
    }
    return 1;
}

int noOfLetter(char *a,int len)
{
    int i,ans=0;
    for(i=4;i<(len-4);i++)
    {
        if(isVowel(a[i]))
            ans++;
    }
    return ans+4;
}

int main()
{
    int tn,t,ans;
    char *a;
    a=(char*)malloc(100*sizeof(char));
    scanf("%d",&tn);
    for(t=0;t<tn;t++)
    {
        scanf("%s",a);
        ans=stringLength(a);
        printf("%d/%d\n",noOfLetter(a,ans),ans);
    }
    return 0;
}
