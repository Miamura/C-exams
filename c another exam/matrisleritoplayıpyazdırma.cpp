#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	
	int i,j,ilk[3][3],iki[3][3],sonuc;
	
	for(i=0;i<3;i++)
	   for(j=0;j<3;j++)
	    {
	    	ilk[i][j] = rand() %20;
	    	iki[i][j] = rand() %20;
		}
    	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			sonuc= ilk[i][j]+iki[i][j];
		}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",matris[i][j]);//program tam deðil
		}
		printf("\n");
	}
	
	
	getch();
	return 0;
}
