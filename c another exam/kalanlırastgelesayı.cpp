#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i,a[10];
    srand(time(NULL));//time.h yazmamýz gerkiyor bu kod rastgele sayýyý bir daha rastgele yapar.
	for(i=0;i<10;i++)
	{
		a[i]=rand()%6+1;
	}
	for(i=0;i<10;i++)
	{
		printf("%d. rastgele sayi : %d\n",i,a[i]);
	}
	getch();
	return 0;
}
