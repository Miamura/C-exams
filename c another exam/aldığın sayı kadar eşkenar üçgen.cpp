#include <stdio.h>
#include <conio.h>
// * þekli ile baklava dilimi yapma
int main(){
    int i, j, boslukSayisi, yildizSayisi, boyut;
    printf("Boyut Giriniz (Satir Sayisi): ");
    scanf("%d", &boyut);
    if(boyut % 2 == 0)    
        boyut += 1;
    boslukSayisi = boyut / 2 ;//5,5 
    yildizSayisi = 1;//1
    for(i=0; i<boyut; i++)
	{
        for(j=0; j<boslukSayisi; j++)
            printf(" ");
        for(j=0; j<yildizSayisi; j++)
            printf("*");
            
        if(i < boyut / 2)
	{
            boslukSayisi--;
            yildizSayisi+=2;
    }
        else
		{
            boslukSayisi++;
            yildizSayisi-=2;
        }
        printf("\n"); 
    }

    getch();
    return 0;
}
