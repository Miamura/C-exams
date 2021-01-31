#include <stdio.h>
#include <stdlib.h>

int main() {
    int dizi[6];
    int min_sayi,i;
    printf("Dizinin elemanlarini giriniz\n");
    for(i=0;i<6;i++){
        printf("Dizinin %d. elemaninini giriniz :\n",i);
        scanf("%d",&dizi[i]);
    }
    min_sayi=dizi[0];
    for(i=1;i<6;i++){
        if(min_sayi>dizi[i]){
            min_sayi=dizi[i];
        }
    }    
    printf("Dizideki minimun eleman %d dir!!",min_sayi);    
    
}

