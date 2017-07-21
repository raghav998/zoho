#include <stdio.h>
#include <malloc.h>


int stringLength(char *a)
{
	int i;
	for(i=0;*(a+i)!='\0';i++);
	return i;
}


void printMatrix(char **a,int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%c ", *(*(a+i)+j));
		printf("\n");
	}

}

int stringCompare(char **a,int i,int j,char *b)
{
	int ti,flagr,flagd;
	flagd=flagr=1;
	if(i>(5-stringLength(b)))
		flagd=0;
	if(j>(5-stringLength(b)))
		flagr=0;
	for(ti=0;b[ti]!='\0';ti++)
	{	if((a[i][j+ti]!=b[ti])&&(flagr))
			flagr=0;
		if((a[i+ti][j]!=b[ti])&&(flagd))
			flagd=0;
	}
	if(flagr)
		return 1;
	else if(flagd)
		return 2;
	else
		return 0;
}


int main(int argc, char const *argv[])
{
	char s[]="WELCOMETOZOHOCORPORATION",**a,*b;
	int i,j,k=0,len,tmp=0;
	a=(char**)malloc(5*sizeof(char*));
	for(i=0;i<5;i++)
		*(a+i)=(char*)malloc(5*sizeof(char));
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			*(*(a+i)+j)=s[k++];
	b=(char*)malloc(50*sizeof(char));
	printMatrix(a,5,5);
	printf("Enter the String\n");
	scanf("%s",b);
	for (i = 0; (i < 5)&&(tmp==0); ++i)
	{
		for (j = 0; (j < 5)&&(tmp==0); ++j)
		{
			switch(tmp=stringCompare(a,i,j,b))
			{
				case 1:
					printf("String Start Index<%d,%d> and End Index<%d,%d>\n",i,j,i,(j+stringLength(b)-1));
					break;
				case 2:
					printf("String Start Index<%d,%d> and End Index<%d,%d>\n",i,j,(i+stringLength(b)-1),j);
					break;
			}
		}
	}
	return 0;
}