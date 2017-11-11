/*
Esercizio 2 di 3
Scrivere un programma che letti da input n interi
(da input) calcola la somma dei numeri pari,
la somma dei numeri dispari e stampa il valore maggiore
tra i due.
 */

#include <iostream>
using namespace std;

int main() {
  int num, quantiPari = 0, i = 0, quantiDispari = 0, n = 0;
  cout << "Quanti n vuoi? ";
  cin >> n;
  while (i < n) {
    cin >> num;
    if (num % 2 == 0) {
      quantiPari += num;
    } else {
      quantiDispari += num;
    }
    i++;
  }
  if (quantiPari > quantiDispari) {
    cout << "Pari: " << quantiPari;
  } else {
    cout << "Dispari: " << quantiDispari;
  }

  return 0;
}
