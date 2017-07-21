#include <stdio.h>
#include <malloc.h>
#include <string.h>

int stringCompare(char *a,char *b)
{
	for(int i=0;((*(a+i)!='\0')||(*(b+i)!='\0'));i++)
		if(*(a+i)!=*(b+i))
			return 0;
	return 1;
}

char*** init(char ***a)
{
	strcpy(a[0][0],"luke");
	strcpy(a[0][1],"shaw");
	strcpy(a[1][0],"wayne");
	strcpy(a[1][1],"rooney");
	strcpy(a[2][0],"rooney");
	strcpy(a[2][1],"ronaldo");
	strcpy(a[3][0],"shaw");
	strcpy(a[3][1],"rooney");
	return a;
}

int findGC(char ***a,char *b)
{
	int ans=0;
	for(int i=0;i<4;i++)
	{
		if(stringCompare(a[i][1],b))
		{
			for(int j=0;j<4;j++)
				if(stringCompare(a[i][0],a[j][1]))
					ans++;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	char ***a,*b;
	int i,j;

	a=(char***)malloc(4*sizeof(char**));
	for(i=0;i<4;i++)
	{
		*(a+i)=(char**)malloc(2*sizeof(char*));
		for(j=0;j<2;j++)
			*(*(a+i)+j)=(char*)malloc(10*sizeof(char));
	}
	b=(char*)malloc(10*sizeof(char));

	a=init(a);

	printf("Enter the Name\n");
	scanf("%s",b);

	printf("No of Grandchildren of %s is %d\n",b,findGC(a,b));

	return 0;
}