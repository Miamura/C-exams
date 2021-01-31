#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i,a[1000];
    srand(time(NULL));//time.h yazmamýz gerkiyor bu kod rastgele sayýyý bir daha rastgele yapar.
	for(i=0;i<1000;i++)
	{
		a[i]=rand()%101-50;//mod 0 ile 50 arasýnda
	}
	for(i=0;i<1000;i++)
	{
		printf("%d. rastgele sayi : %d\n",i,a[i]);
	}
	getch();
	return 0;
}
