#include <stdio.h>

int main(){
	
	double sonuc,a,b;
	printf("coini aldiginiz rakami giriniz : ");
	scanf("%f",&a);
	
	printf("coini sattiginiz rakami giriniz : ");
	scanf("%f",&b);
	sonuc = 100 * b / a;
    
	printf("kariniz yuzde %f" , sonuc );
}
