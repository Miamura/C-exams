#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	
	int i,j,matris[3][3];//ilki satýr 2.si sütun
	
	for(i=0;i<3;i++)
	   for(j=0;j<3;j++)
	    matris[i][j] = rand() %20;
    for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",matris[i][j]);
		}
		printf("\n");
	}
	
	
	getch();
	return 0;
}
