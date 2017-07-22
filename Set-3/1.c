/*
Eg 1: Input: a1b10
       Output: abbbbbbbbbb
Eg: 2: Input: b3c6d15
          Output: bbbccccccddddddddddddddd
The number varies from 1 to 99.
*/

#include <stdio.h>
void printString(char a,int n)
{
	for(int i=0;i<n;i++)
		printf("%c",a);
}
int main(int argc, char const *argv[])
{
	char a[50],c;
	int number=0,i,ch;
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++)
	{
		ch=a[i];
		if(((ch>=65)&&(ch<=91))||((ch>=97)&&(ch<=123)))
		{
			//character
			if(number)
			{
				printString(c,number);
				number=0;
			}
			c=a[i];
		}
		if((ch>=48)&&(ch<=57))
		{
			number=(number*10)+(ch-48);
		}
	}
	printString(c,number);
	printf("\n");
	return 0;
}