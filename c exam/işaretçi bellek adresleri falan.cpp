#include <stdio.h>
#include <conio.h>

main()
{
  int *ip1, *ip2, id1, id2;     /* 1 */
  ip1 = &id1;                   /* 2 */
  ip2 = &id2;                   /* 3 */
  id1 = 42;                     /* 4 */
  *ip2 = 67;  /* Dolayl� de�er atama y�ntemi */ /* 5 */
  printf("id1 degiskeninin degeri: %d\n", *ip1);
  printf("id2 degiskeninin degeri: %d\n", *ip2);
  printf("id1 degiskeninin bellek adresi: %p\n", ip1);
  printf("id2 degiskeninin bellek adresi: %p\n", ip2);
  
   *ip1++; /* ��aret�inin g�sterdi�i bellek adresini art�r�r. */ 
   (*ip1)++; /* ��aret�inin g�sterdi�i bellek adresindeki de�i�ken de�erini art�r�r. */

  printf("id1 degiskeninin degeri: %d\n", *ip1);
  printf("id2 degiskeninin degeri: %d\n", *ip2);
  printf("id1 degiskeninin bellek adresi: %p\n", ip1);
  printf("id2 degiskeninin bellek adresi: %p\n", ip2);


}

