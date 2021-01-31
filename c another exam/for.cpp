#include <stdio.h>
#include <conio.h>

int main()
{
	int a, b;
	int sonuc=0;
	
	for(a=1;a<11;a++)
	{ for(b=1;b<11;b++)
	    {
	    	sonuc=a*b;
	    	printf("%d * %d = %d\n",a,b,sonuc);
		}
		printf("\n");
	}
	
	
	getch();
}
