//reverse string
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char inp[50],tmp;
	int vow[50],ptr=0;;
	printf("Enter the string\n");
	fgets(inp,50,stdin);
	for(int i=0;inp[i]!='\0';i++)
	{
		switch(inp[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				vow[ptr++]=i;
				break;
			case '\n':
				inp[i]=' ';
				break;
		}
	}
	for (int i = 0; i < ptr/2; ++i)
	{
		tmp=inp[vow[i]];
		inp[vow[i]]=inp[vow[ptr-i-1]];
		inp[vow[ptr-i-1]]=tmp;
	}
	printf("Vowels reversed string is %s\n", inp);
	return 0;
}