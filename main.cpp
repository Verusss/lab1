/*Weronika Borek, 226327
Funkcja wymaga podania dwóch argumentów wiersza poleceń - pierwszy z nich 
określa rozmiar tablicy, drugi stanowi ziarno (seed value) dla działania funkcji srand().
Program działa prawidłowo.
*/
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char **charSquare (int n);
void drawCharSquare (char **square, int n);

/*Program obsługuje błędy użytkownika, takie jak podanie nieprawidłowej ilości argmumentów wiersza poleceń, przetwarza je oraz przekazuje do dalszych funkcji.*/
int main (int argc, char *argv[])
{
  int n;
  n=atoi(argv[1]);
  srand (atoi(argv[2]));
  if(argc!=3)
    {
      printf ("Niepoprawna liczba argumentow.\n");
      return 0;
    }
  drawCharSquare(charSquare (n), n);
  return 0;
}

/*Funkcja generuje tablice liczb pseudolosowych na podstawie ziarna oraz rozmiaru podanego w argumentach wiersza poleceń.*/
char **charSquare (int n)
{
  char **square=(char**)malloc(n*(sizeof(char*)));
  for(int i=0; i<n; i++)
    square[i]=(char*)malloc(n*(sizeof(char)));
  for(int i=0; i<n*n; i++)
    square[i/n][i%n]=rand()%26+97;
  return square;
}

/*Funkcja wyświetla wygenerowaną wcześniej tablicę liczb.*/
void drawCharSquare (char **square, int n)
{
  for (int i=0; i<n*n; i++)
    {
      if (i%n==n-1 && i<n*n-1)
	printf ("%c\n", square[i/n][i%n]);
      else
	printf ("%c ", square[i/n][i%n]);
    }
  printf ("\n");
  for (int i=0; i<n; i++)
    free(square[i]);
  free(square);
}
