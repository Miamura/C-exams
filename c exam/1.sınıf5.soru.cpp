//18 yaş ve büyüklere giriş hakkı 1 olacak şekilde verilmiştir buradaki yanlışı veya mantıksal hatayı bulunuz
yasıal(int yas)
{
int giris_hakki;
if(yas<18)
giris_hakki=0;
else if(yas>18)
giris_hakki=1;
return giris_hakki;
}
