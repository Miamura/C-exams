#include <stdio.h> 
#include <stdlib.h>

int main()
{
int matris[3][4]={1,2,3,4,5,6,7,8,9,10,11,12},
	i=0,
	j=0,
	indis=0;  				 
int *pointer= &matris[0][0]; 

printf("   3x4 Matris\n");

printf(" ----------------\n");  


for(j=0;j<3;j++){    

	for(i=0;i<4;i++) 
	{
		 if(indis<10)printf(" %d  ",*(pointer+indis++));  //Þuna takýlmayýn sadece görsel olarak daha þýk görünmesi için if kullandým.
		 else printf("%d  ",*(pointer+indis++));  
	}
	printf("\n"); //Matris þeklini almasý için alt satýra geçtim.
}

printf(" ----------------\n");  


printf("Silmek istedidiniz elemanin indisini yazin[0-11] :");

scanf("%d",&j);

for(;;)//Sonsuz döngü ile eðer istenilenin dýþýnda bir sayý girerse uyaracak ve tekrar girmesini isteyecek.
{
	if(j>=0 && j<12)
	break; // Break kullandýðým için else kullanmama gerek yok
	printf("[0-11] araliginda bir sayi girin : ");
	scanf("%d",&j);
}
printf("%d. indisli %d elemani siliniyor...\n",j,*(pointer+j));

for(j;j<12;j++)  //Seçilen indisten baþlayarak son indise kadar döngü olþtur.
{
	(pointer+j) = (pointer+j+1) ; //Seçilen indisteki göstericinin içeriðine bir sonraki göstericinin içeriðini ata
}

          *(pointer+11)=0; //Son indiste rastgele bir sayý gelecek. Soruda gösterildiði gibi 0 olarak deðiþtir.

//Matrisin son halini görüntülemek için ayný kodu yazýyorum...

printf("Yeni 3x4 Matris\n"); 

printf(" ----------------\n");  

indis=0;

for(j=0;j<3;j++){    
					 
	for(i=0;i<4;i++) 
	{                           		
		 if(indis<10)printf(" %d  ",*(pointer+indis++));  
		 else printf("%d  ",*(pointer+indis++));  
	}
	printf("\n"); 
}

printf(" ----------------\n");  

return 0;
}
