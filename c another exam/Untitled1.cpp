// C ye ba�lama ve veri tiplerinin kaplad�klar� alanlar 
// // yorum sat�r�d�r 1 sat�rdan fazla yorum olmaz 
/*
    anne  
    baba     bu sat�rl� kod dur * * lar aras�nda istedi�iniz kadar sat�r yorum yapabilirsiniz
    nine
*/
//#include k�t�phane i�lemleridir. #define tan�m i�lemleridir 
#include <stdio.h>  //.h k�t�phane tan�mlamas�d�r
#include <conio.h> //getch i�in gerekli olan k�t�phanedir

int main() //program�n ba�lang�� noktas�d�r
{               //tan�mlamalar�(a�a��daki a b) da alt tire hari� �gelerden ve say�lardan yapamazs�n.alt tire de k�t�phanlerde old dan yapmasan iyi olur.
	int a;      //int de say� giri�i olur %d ile say� al�n�r. 
	char b[10]; // char da karakter giri�i olur.[] karakter uzunlu�unu belirtir.
	            //; o komutun(d�ng�n�n) bitti�ini g�sterir
	printf("bir sayi bir de karakter giriniz : \n"); // yaz� yazd�ran arac� d�r. yani bir nevi yazd�r der 
	scanf(" %d ",&a); // karakter ve say� giri�i alan ara�t�r
	
	
	getch(); // ekran�n an�nda kapanmamas� i�in gereklidir
	
	return 0;
}
	
	

