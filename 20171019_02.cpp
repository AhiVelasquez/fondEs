/*
Esercizio 2.
Scrivere un programma in C++ che risolva le equazioni di 2° grado.
Un'equazione di 2° grado è della forma ax^2 + bx + c = 0
 */

#include <iostream>
#include <math.h>
using namespace std;

int main() {
  double coefficenteA, coefficenteB, coefficenteC;
  cin >> coefficenteA >> coefficenteB >> coefficenteC;

  double delta = pow(coefficenteB, 2) - 4 * coefficenteA * coefficenteC;

  if (delta < 0) {
    cout << "Non esistono soluzioni reali";
    return 1;
  }

  if (coefficenteA == 0 && coefficenteB != 0) {
    cout << - coefficenteC / coefficenteB;
  } else if (coefficenteA == 0) {
    cout << "Imp";
  } else {
    cout << - coefficenteB + delta / 2 * coefficenteA;
    cout << - coefficenteB - delta / 2 * coefficenteA;
  }

  return 0;
}
