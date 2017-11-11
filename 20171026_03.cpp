/*
Esercizio 3 di 3
Scrivere un programma che lette da input
una sequenza di 10 char stampa la quantità
di lettere minuscole.
 */

#include <iostream>
using namespace std;

int main() {
  char c;
  int somma = 0, i = 0;

  while (i < 10) {
    cin >> c;
    if (c >= 'a' && c <= 'z') {
      somma++;
    }
    i++;
  }
  cout << somma;
  return 0;
}
