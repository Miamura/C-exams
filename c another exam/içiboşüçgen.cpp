#include <stdio.h>
#include <conio.h>

int main()
{
 int sayi,icBosluk,disBosluk;
 int i;
 int j;
 printf("sayý gir naruto:");
 scanf("%d",&sayi);
icBosluk=-1;
disBosluk=sayi-1;
 for(i=1;i<=sayi-1;i++)
 {
  if(i!=sayi)
  {
   for(j=1;j<=disBosluk;j++){
   	   printf(" ");
   }
   printf("*");
  }
   if(i!=1)
  {
   for(j=1;j<=icBosluk;j++)
   printf(" ");
   printf("*");
  }
 icBosluk+=2;
 disBosluk--;
   printf("\n");
 }
  icBosluk+=2;
 for(i=1;i<=icBosluk;i++)
 printf("*");
 printf("\n");
 getch();
return 0;
}
