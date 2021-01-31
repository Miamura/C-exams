#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	int i,a[10];
	printf("%d",a);
	for(i=0;i<10;i++)
	{
		a[i]=rand();
	}
	for(i=0;i<10;i++)
	{
		printf("%d\n",a[i]);
		
	}
	getch();
	return 0;
}
