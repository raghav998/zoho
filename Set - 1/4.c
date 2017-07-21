#include <stdio.h>
#include <malloc.h>
#define ADD 45
#define MUL 362880

void printResult(int ans)
{
	switch(ans)
	{
		case 1:
			printf("Sudoku was correct\n");
			break;
		case 0:
			printf("Sudoku was not correct\n");
			break;
	}
}

void checkSudoku(int **a)
{
	int i,j,sumr,sumd,multir,multid,k,l;
	//check row and col
	for(i=0;i<9;i++)
	{
		sumr=sumd=0;
		multir=multid=1;
		for(j=0;j<9;j++)
		{
			sumr+=*(*(a+i)+j);
			multir*=*(*(a+i)+j);
			sumd+=*(*(a+j)+i);
			multid*=*(*(a+j)+i);
		}
		if((sumr!=ADD)||(multir!=MUL)||(multid!=MUL)||(sumd!=ADD))
		{
			printResult(0);
			return;
		}
	}

	//check each square
	for(i=0;i<9;i+=3)
	{
		for(j=0;j<9;j+=3)
		{
			sumr=0;
			multir=1;
			for(k=i;k<i+3;k++)
			{
				for(l=j;l<j+3;l++)
				{
					sumr+=*(*(a+k)+l);
					multir*=*(*(a+k)+l);
				}
			}
			if((sumr!=ADD)||(multir!=MUL))
			{
				printResult(0);
				return;
			}
		}
	}

	printResult(1);
}

int main(int argc, char const *argv[])
{
	int **a,i,j;
	a=(int**)malloc(9*sizeof(int*));
	for(i=0;i<9;i++)
		*(a+i)=(int*)calloc(9,sizeof(int));
	printf("Enter the Values\n");
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			scanf("%d",(*(a+i)+j));

	checkSudoku(a);
	return 0;
}