#include <stdio.h>
#include <stdlib.h>

int main ()
{
  FILE *fp;
  int idizi[5];
  int id1;

  for (id1=0; id1<5; id1++) {
       printf("int bir deger giriniz: ");
       scanf("%d", &idizi[id1]);
  }

  if ((fp=fopen ("deneme.txt", "wb")) == NULL) {
      printf("Dosya açýlamadý!\n");
      exit(1);
  }

  if (fwrite(idizi, sizeof idizi, 1, fp) != 1) {
      printf("Yazma hatasý!\n");
      exit(1);
  }       
  
  fclose(fp);
  
  if ((fp=fopen("deneme.txt", "rb")) == NULL) {
      printf("Dosya açýlamadý!\n");
      exit(1);
  }

  printf("\nDeðerleri silinmiþ dizi elemanlari:\n");
  for (id1=0; id1<5; id1++) {
       idizi[id1] = 0;
       printf("%d ", idizi[id1]);
  }
  printf("\n");

  if (fread(idizi, sizeof idizi, 1, fp) != 1) {
      printf("Okuma hatasý!\n");
      exit(1);
  }
  fclose(fp);
  
  printf("Dosyadan okunan dizi deðerleri:\n");
  for (id1=0; id1<5; id1++) printf("%d ", idizi[id1]);
}
