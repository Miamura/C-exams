#include <stdio.h>
#include <conio.h>
// * þekli üçgen yapma
int main(){
    int i, j, yildizSayisi=1, boslukSayisi=9;
    for(i=0; i<10; i++){
        for(j=0; j<boslukSayisi; j++)
            printf(" ");
        for(j=0; j<yildizSayisi; j++)
            printf("*"); 
        printf("\n");
        yildizSayisi+=2;
        boslukSayisi--;  
    }
    getch();
    return 0;
}
