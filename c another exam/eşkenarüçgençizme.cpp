#include <stdio.h>
#include <conio.h>
// * þekli ile baklava dilimi yapma
int main(){
    int i, j, boslukSayisi, yildizSayisi, boyut;
    boyut = 11;
    boslukSayisi = boyut / 2 ;
    yildizSayisi = 1;
    for(i=0; i<boyut; i++){
        for(j=0; j<boslukSayisi; j++)
            printf(" ");
        for(j=0; j<yildizSayisi; j++)
            printf("*");
        if(i < boyut / 2)
		{
            boslukSayisi--;
            yildizSayisi+=2;
        }
        else{
            boslukSayisi++;
            yildizSayisi-=2;
            }
        printf("\n");
    }
    
    getch();
    return 0;
}
