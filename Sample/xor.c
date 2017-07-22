#include <stdio.h>
#include <malloc.h>
int main()
{
    int tn,t,n,i,j;
    scanf("%d",&tn);
    for(t=0;t<tn;t++)
    {
        scanf("%d",&n);
        int **a;
        a=(int**)malloc(n*sizeof(int*));
        for(i=0;i<n;i++)
            *(a+i)=(int*)calloc(n,sizeof(int));
            
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                a[i][j]=i^j;
        int max=0,count=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(max<a[i][j])
                    max=a[i][j];
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(a[i][j]==max)
                    count++;
        printf("Matrix is \n");
        for ( i = 0; i < n; ++i)
        {
        	for(j=0;j<n;j++)
        	{
        		printf("%d ",a[i][j]);
        	}
        	printf("\n");
        }
        printf("max is %d count is %d\n",max,count);
    }
    return 0;
}
