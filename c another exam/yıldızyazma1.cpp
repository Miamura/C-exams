#include <stdio.h>
#include <conio.h>

int main()
{
    int i,j;
      for(i=1;i<10;i+=2)  //ka� sat�r olacak? 9 sat�r olarak verilmi�
       {
      for(j=0;j<9-i/2;j++) // bosluk say�s� 
       {  
             printf(" ");  }
      for(j = 0; j < i; j++) 
        {  
            printf("*");  } // y�ld�z say�s�
            printf("\n");
       }

    for(i=7;i>0; i -=2) {
                 
      for(j = 0; j < 9 - i / 2; j++)
      {
        printf(" ");
        }

      for(j = 0; j < i; j++)
      {
        printf("*");
        }
              printf("\n");
}
  getch();
  return 0;
}
