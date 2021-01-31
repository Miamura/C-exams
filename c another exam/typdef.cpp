#include <stdio.h>
#include <conio.h>

int main(){
    int sira, i, j, yildizSayisi=1, boslukSayisi;
    char karakter;
    printf("Sira Giriniz: ");
    scanf("%d", &sira);
    printf("Girilecek Karakter: ");
    scanf(" %c", &karakter);

    boslukSayisi = sira - 1;
    
    for(i=0; i<sira; i++){       
        for(j=0; j<boslukSayisi; j++)
            printf(" ");
        for(j=0; j<yildizSayisi; j++)
            printf("%c", karakter);    
        printf("\n");
        yildizSayisi+=2;
        boslukSayisi--;
    }
    
    getch();
    return 0;
}
