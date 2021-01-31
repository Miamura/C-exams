#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{ FILE *dosya_okuma;
  char ch;

  if((dosya_okuma=fopen("c:\\yaz.txt","r"))==NULL)
  { puts("Dosya Acilamiyor");
    getch();
    exit(0);
  }
  ch=fgetc(dosya_okuma);
  printf("dosyadan okunan karakter: %c",ch);
  fclose(dosya_okuma);
  getch();
}
