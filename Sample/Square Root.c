// square root of number without math.h
// using simple logic
#include <stdio.h>
int squareRoot(int number)
{
	int sum,count;
	sum=count=0;
	for(int i=1;sum<=number;i+=2)
	{
		sum+=i;
		count++;
	}
	return count-1;
}
int main(int argc, char const *argv[])
{
	int number;
	printf("Enter the number\n");
	scanf("%d",&number);
	printf("SquareRoot of %d is %d\n",number,squareRoot(number));
	return 0;
}