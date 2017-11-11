/*
Esercizio 1 di 3
Scrivere un programma che letti da input 10 interi
conta e stampa quanti sono quelli pari.
 */

#include <iostream>
using namespace std;

int main() {
  int num, quantiPari = 0, i = 0;
  while (i < 10) {
    cin >> num;
    if (num % 2 == 0) {
      quantiPari++;
    }
    i++;
  }
  cout << quantiPari;
  return 0;
}
