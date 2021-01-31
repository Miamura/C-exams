#include <iostream>

#include <vector>//vektörleri kullanabilmek için sayfamýza küyüphanesini çaðýrýyoruz

#include <time.h>//randomun çalýþmasý için time.h kütüphanesini dahil ediyoruz

#include <windows.h>//randomun çalýþmasý için windows.h kütüphanesini dahil ediyoruz

#include <algorithm>//vektörleri sýralama fonksiyonu için algorithm kütüphanesini çaðýrýyoruz

using namespace std;//isim uzayý tanýmlanýyor
 
int main()
{
    vector <int> V;//integer tipinde V adýnda bir vektör tanýmladýk
    
    srand(time(NULL));//randomun her seferinde farklý gelmesi için
    
    for(int i=0;i<=20;i++){//vektörümüze eleman ekleme yapmak için döngü açtýk
    
    V.push_back(rand()%100);//V vektörümüze rastegele(random) sayýlar aktarýlýyor
    
    }//eleman ekleme döngüsü sonu
    
    for(int i=0;i<V.size();i++){//sýralama yapmadan önce verileri ekrana yazdýralým
    
    cout<<i<<" Eleman: "<<V.at(i)<<endl;//ekrana vektörün elemanlarý yazýdýrýlýyor
    
    }//veriler ekrana yazdýrýlýyor sonu
 
    cout<<"sýralamaya geldik"<<endl;//ekrana mesaj yazýlýyor
    
    sort(V.begin(),V.end());//V vektörümüzü baþýndan itibaren sonuna kadar sýrala
    
    //þimdi vektörümüzün son durumunu ekrana yazdýralým
    
   for(int i=0;i<V.size();i++){//sýralama yapmadan önce verileri ekrana yazdýralým
   
    cout<<i<<" Eleman: "<<V.at(i)<<endl;//ekrana vektörün elemanlarý yazýdýrýlýyor
    
    }//veriler ekrana yazdýrýlýyor sonu
    
    return 0;
}
