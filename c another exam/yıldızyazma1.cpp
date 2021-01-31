#include <stdio.h>
#include <conio.h>

int main()
{
    int i,j;
      for(i=1;i<10;i+=2)  //kaç satýr olacak? 9 satýr olarak verilmiþ
       {
      for(j=0;j<9-i/2;j++) // bosluk sayýsý 
       {  
             printf(" ");  }
      for(j = 0; j < i; j++) 
        {  
            printf("*");  } // yýldýz sayýsý
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
