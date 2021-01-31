#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	
	int i,j,k,matris[3][3][3];//ilki satýr 2.si sütun
	
	for(i=0;i<3;i++)
	   for(j=0;j<3;j++)
	       for(k=0;k<3;k++)
	    matris[i][j][k]= rand() %20;
	    
    for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{ 
			for(k=0;k<3;k++)
			{
				printf("%d",matris[i][j][k]);
			}
			printf("\t");
		}
		printf("\n");
	}
	
	
	getch();
	return 0;
}
