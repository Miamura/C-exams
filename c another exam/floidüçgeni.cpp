#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
   int i,j=0,x=0;
   for(i=0;i<13;i++) {
      printf("\n");
      x=x+j;
         for(j=0;j<=i;j++)
            printf("%-3d",x+j+1);
   }
   getch();
}
