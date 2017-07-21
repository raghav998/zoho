#include <stdio.h>
int main(int argc, char const *argv[])
{
	char a[]="PROGRAM";
	int i,j;
	for(i=0;i<7;i++)
	{
		for(j=0;j<7;j++)
		{
			if((i==j)||(i+j==6))
				printf("%c",a[j]);
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}