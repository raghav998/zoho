#include <stdio.h>
#include <malloc.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

int isPerfectSquare(int n)
{
	int i;
	for ( i = 1; i*i <= n; ++i)
	{
		if(i*i==n)
			return 1;
	}
	return 0;
}

int findWeight(int ino)
{
	int w=0;
	if(isPerfectSquare(ino))
		w+=5;
	if((ino%4==0)&&(ino%6==0))
		w+=4;
	if(ino%2==0)
		w+=3;
	return w;
}

int main(int argc, char const *argv[])
{
	int *a,n,i,j,*b;
	printf("Enter the N Value\n");
	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int));
	b=(int*)calloc(n,sizeof(int));
	printf("Enter the Array Values\n");
	for(i=0;i<n;i++)
		scanf("%d",(a+i));

	for(i=0;i<n;i++)
	{
		*(b+i)=findWeight(*(a+i));
	}

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*(b+i)>*(b+j))
			{
				swap(&*(b+i),&*(b+j));
				swap(&*(a+i),&*(a+j));
			}
		}
	}
	printf("Result is\n");
	for(i=0;i<n;i++)
	{
		printf("<%d,%d>",*(a+i),*(b+i));
		if(i!=n-1)
			printf(",");
	}
	printf("\n");
	return 0;
}