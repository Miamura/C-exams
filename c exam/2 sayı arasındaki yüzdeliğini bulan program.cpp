#include <stdio.h>



int main(){
	double ilksayi,ikincisayi,sonuc;
	int x = 100;
	
	
	printf("ilk sayiyi giriniz");
	scanf("%lf",&ilksayi);
	
	printf("ikinci sayiyi giriniz");
	scanf("%lf",&ikincisayi);
	
	sonuc = ikincisayi*x/ilksayi;
	
	
	printf("1 gunluk en yuksek en dusuk satis farki yuzde %lf ", sonuc);
	
	
}
