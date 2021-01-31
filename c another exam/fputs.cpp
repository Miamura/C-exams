#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   char dizi[30]={"Babalar Gunu"};
    char birkelime[100];
    char *c;
  FILE *dosya_yaz;

  dosya_yaz=fopen("baba.txt","a");
  if (dosya_yaz==NULL)
  { printf("Dosya olusturulamadi");
    getch();
    exit(0);
  }
  
  fputs("fputs\tKomutu\n",dosya_yaz);
  
  fputs("Bugun 18.Haziran.2017\n",dosya_yaz);
  fputs(dizi,dosya_yaz);
  
  fclose(dosya_yaz);
  
  dosya_yaz=fopen("baba.txt","r");
  do {
     c = fgets(birkelime,100,dosya_yaz); 
     if (c != NULL)
        printf("%s",birkelime);   
   } while (c != NULL);         

  
  
  
  getch();
}

