#include <stdio.h>

int isPrime(int ino)
{
	int count=0;
	for (int i = 2; i < ino; ++i)
	{
		if(ino%i==0)
			count++;
	}
	if(count==0)
		return 1;
	else
		return 0;
}

int main(int argc, char const *argv[])
{
	int ino;
	printf("Enter the Number\n");
	scanf("%d",&ino);
	for (int i = 2; i < ino; ++i)
	{
		for (int j = 2; j < ino; ++j)
		{
			if((isPrime(i)&&(isPrime(j)))&&(i+j==ino))
			{
				printf("YES (%d+%d) \n",i,j);
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}