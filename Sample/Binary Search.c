#include <stdio.h>
#include <malloc.h>
int* sort(int* a,int n)
{
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j])
            {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
    return a;
}
int search(int *a,int start,int end,int ino)
{
    int mid=(start+end)/2;
    if(a[mid]==ino)
        return 1;
    if(start==end)
        return 0;
    if(a[mid]>ino)
        search(a,start,mid-1,ino);
    if(a[mid]<ino)
        search(a,mid+1,end,ino);
}
int main()
{
    int tn,t,n,i,q,tmp,j;
    scanf("%d",&tn);
    for(t=0;t<tn;t++)
    {
        int *a;
        scanf("%d",&n);
        a=(int*)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
            scanf("%d",a+i);
        a=sort(a,n);
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            scanf("%d",&tmp);
            if(search(a,0,n,tmp))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
