#include <stdio.h>
#include <conio.h>

main()
{
  int *ip1, *ip2, id1, id2;     /* 1 */
  ip1 = &id1;                   /* 2 */
  ip2 = &id2;                   /* 3 */
  id1 = 42;                     /* 4 */
  *ip2 = 67;  /* Dolaylı değer atama yöntemi */ /* 5 */
  printf("id1 degiskeninin degeri: %d\n", *ip1);
  printf("id2 degiskeninin degeri: %d\n", *ip2);
  printf("id1 degiskeninin bellek adresi: %p\n", ip1);
  printf("id2 degiskeninin bellek adresi: %p\n", ip2);
  
   *ip1++; /* İşaretçinin gösterdiği bellek adresini artırır. */ 
   (*ip1)++; /* İşaretçinin gösterdiği bellek adresindeki değişken değerini artırır. */

  printf("id1 degiskeninin degeri: %d\n", *ip1);
  printf("id2 degiskeninin degeri: %d\n", *ip2);
  printf("id1 degiskeninin bellek adresi: %p\n", ip1);
  printf("id2 degiskeninin bellek adresi: %p\n", ip2);


}

