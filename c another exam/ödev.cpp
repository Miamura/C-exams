#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	FÝLE *isciyaz;
	int i, iscikayit, ;
	
for(i=0;i<1;i)
{
    char gecici[255];
    
    int secim;
    
    system("cls");
    
    printf("patron girisi icin 1 e basiniz\n");
    
    printf("isci girisi icin 2 ye basiniz\n");
 
    fgets(gecici, sizeof(gecici), stdin); 
    
    secim = atoi(gecici);
    
    if( secim == 1 )
	{
        printf("isci kayit icin 1e basiniz\n");
        
        printf("isci takip icin 2ye basiniz\n");
        
		printf("mal takip icin 3e basiniz\n");
  
        fgets( gecici , sizeof(gecici) , stdin);
        
        secim = atoi(gecici);
        
        if( secim == 1 ) //isci kayýt
		{
            
            break;
        }
		
		else if( secim == 2 )// isci takip
		{
            
            break;
        }
		
		else if( secim == 3 )//mal takip
		{
            
            break;
        }
		
		else continue;

  }
	
	else if( secim == 2 )
	{
        printf("yoklama icin 1e basiniz\n");
  
        printf("mal kayit icin 2ye basiniz\n");
  
        fgets(gecici, sizeof(gecici), stdin);
        
		secim = atoi(gecici);
        
        if( secim == 1 )// yoklama
		{
            
            break;
        }
		
		else if( secim == 2 )// mal kayit
		{
           
            break;
        }
		
		else continue;
    }
    }
    
      getch();
      
  }
