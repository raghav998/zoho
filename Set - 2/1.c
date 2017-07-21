#include <stdio.h>
#include <malloc.h>

int min(int *a,int pos,int n)
{
	int min=pos;
	while(pos<n)
	{
		if(a[min]>a[pos])
			min=pos;
		pos++;
	}
	return min;
}


int max(int *a,int pos,int n)
{
	int max=pos;
	while(pos<n)
	{
		if(a[max]<a[pos])
			max=pos;
		pos++;
	}
	return max;
}

int* swap(int *a,int i,int j)
{
	int t=a[i];
	a[i]=a[j];
	a[j]=t;
	return a;
}

void printList(int *a,int n)
{
	printf("{");
	for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
		if(i!=n-1)
			printf(", ");
	}
	printf("}\n");
}

int main(int argc, char const *argv[])
{
	int *a,i,j,n;
	printf("Enter the N Value\n");
	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int));

	printf("Enter the Array Values\n");
	for(i=0;i<n;i++)
		scanf("%d",(a+i));

	for(i=0;i<n;i++)
	{
		if(i%2==0)
			a=swap(a,i,max(a,i,n));
		else
			a=swap(a,i,min(a,i,n));
	}

	printf("Output : \n");
	printList(a,n);

	return 0;
}