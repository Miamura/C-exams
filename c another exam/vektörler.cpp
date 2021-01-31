#include <iostream>

#include <vector>//vekt�rleri kullanabilmek i�in sayfam�za k�y�phanesini �a��r�yoruz

#include <time.h>//randomun �al��mas� i�in time.h k�t�phanesini dahil ediyoruz

#include <windows.h>//randomun �al��mas� i�in windows.h k�t�phanesini dahil ediyoruz

#include <algorithm>//vekt�rleri s�ralama fonksiyonu i�in algorithm k�t�phanesini �a��r�yoruz

using namespace std;//isim uzay� tan�mlan�yor
 
int main()
{
    vector <int> V;//integer tipinde V ad�nda bir vekt�r tan�mlad�k
    
    srand(time(NULL));//randomun her seferinde farkl� gelmesi i�in
    
    for(int i=0;i<=20;i++){//vekt�r�m�ze eleman ekleme yapmak i�in d�ng� a�t�k
    
    V.push_back(rand()%100);//V vekt�r�m�ze rastegele(random) say�lar aktar�l�yor
    
    }//eleman ekleme d�ng�s� sonu
    
    for(int i=0;i<V.size();i++){//s�ralama yapmadan �nce verileri ekrana yazd�ral�m
    
    cout<<i<<" Eleman: "<<V.at(i)<<endl;//ekrana vekt�r�n elemanlar� yaz�d�r�l�yor
    
    }//veriler ekrana yazd�r�l�yor sonu
 
    cout<<"s�ralamaya geldik"<<endl;//ekrana mesaj yaz�l�yor
    
    sort(V.begin(),V.end());//V vekt�r�m�z� ba��ndan itibaren sonuna kadar s�rala
    
    //�imdi vekt�r�m�z�n son durumunu ekrana yazd�ral�m
    
   for(int i=0;i<V.size();i++){//s�ralama yapmadan �nce verileri ekrana yazd�ral�m
   
    cout<<i<<" Eleman: "<<V.at(i)<<endl;//ekrana vekt�r�n elemanlar� yaz�d�r�l�yor
    
    }//veriler ekrana yazd�r�l�yor sonu
    
    return 0;
}
