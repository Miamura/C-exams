#include "stdio.h"
main()
{
   FILE *fp1;
   
   char birkelime[100];
   
   char *c;
   
   fp1 = fopen("onsatir.txt","r");
   
   do {
   
            c = fgets(birkelime,100,fp1); /* bir satir okuyalim */
   
            if (c != NULL)
   
            printf("%s",birkelime);    /* ekrana yazalim   */
   
   } while (c != NULL);          /* ta ki NULL olana kadar.. */
   
   fclose(fp1);
}
