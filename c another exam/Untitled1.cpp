// C ye baþlama ve veri tiplerinin kapladýklarý alanlar 
// // yorum satýrýdýr 1 satýrdan fazla yorum olmaz 
/*
    anne  
    baba     bu satýrlý kod dur * * lar arasýnda istediðiniz kadar satýr yorum yapabilirsiniz
    nine
*/
//#include kütüphane iþlemleridir. #define taným iþlemleridir 
#include <stdio.h>  //.h kütüphane tanýmlamasýdýr
#include <conio.h> //getch için gerekli olan kütüphanedir

int main() //programýn baþlangýç noktasýdýr
{               //tanýmlamalarý(aþaðýdaki a b) da alt tire hariç ögelerden ve sayýlardan yapamazsýn.alt tire de kütüphanlerde old dan yapmasan iyi olur.
	int a;      //int de sayý giriþi olur %d ile sayý alýnýr. 
	char b[10]; // char da karakter giriþi olur.[] karakter uzunluðunu belirtir.
	            //; o komutun(döngünün) bittiðini gösterir
	printf("bir sayi bir de karakter giriniz : \n"); // yazý yazdýran aracý dýr. yani bir nevi yazdýr der 
	scanf(" %d ",&a); // karakter ve sayý giriþi alan araçtýr
	
	
	getch(); // ekranýn anýnda kapanmamasý için gereklidir
	
	return 0;
}
	
	

