/*
Esercizio 4.
Scrivere un programma in C++ per giocare a "SASSO, CARTA, FORBICI":
un gioco in cui due giocatori simultaneamente dichiarano "sasso" oppure "carta",
oppure "forbici".
Il vincitore è il giocatore la cui scelta domina quella dell'altro, in
base alle regole seguenti:
  la carta vince sul sasso
  il sasso rompe le forbici
  le forbici tagliano la carta
*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main() {
  srand(time(0));
  char sceltaPlayer;

  cout << "SASSO (s), CARTA (c), FORBICI (f): ";
  cin >> sceltaPlayer;

  int sceltaCpuRandom = rand() % 3;

  if (sceltaCpuRandom == 0) {
    cout << "CPU: sasso\n";
  } else if (sceltaCpuRandom == 1) {
    cout << "CPU: carta\n";
  } else {
    cout << "CPU: forbice\n";
  }

  if ((sceltaCpuRandom == 0 && sceltaPlayer == 'f') || (sceltaCpuRandom == 1 && sceltaPlayer == 's') || (sceltaCpuRandom == 2 && sceltaPlayer == 'c')) {
    cout << "Hai perso!\n";
  } else {
    cout << "Hai vinto!\n";
  }



  return 0;
}
