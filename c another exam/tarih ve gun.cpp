#include <time.h>
#include <stdio.h>
#include <conio.h>


int main()
{
	
time_t t = time(NULL);
struct tm tm = *localtime(&t);

printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	getch ();
}