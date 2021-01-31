#include <stdio.h>

int Toplama(int x){
	
	int i,sayac,toplam;
	
    if(x==1)
    return 1;
 
	else{
	
	 for ( i=1; i<=x; i++ )
	 { 
        if( i % 2 == 0){
            toplam+=i;   
            sayac++;        
        }   
        }
    }
   return toplam;
}

        
int main (){
	
    int a;
      
	printf("2 den büyük bir deger giriniz;");
    scanf("%d",&a);
    
	if(a<2){
    printf("2 den büyük bir deger giriniz;");
    scanf("%d",&a);
    }
    
	printf("Sonuc=%d\n",Toplama(a));

return 0;
}
