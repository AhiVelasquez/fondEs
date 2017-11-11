/*
Esercizio 1bis
Scrivere un programma in C++ che dati in input un carattere, 'm' o 'M', e due
numeri, a e b, restituisca in output il massimo tra i due numeri, se il carattere
inserito è 'M', oppure il minimo tra i due numeri, se il carattere inserito è 'm'.
Ad esempio, se il carattere inserito è 'm', a = 17 e b = 35, il programma restituirà
17; se il carattere inserito è 'M', a = 17 e b = 35, il programma restituirà 35.
 */

#include <iostream>
using namespace std;

int main() {

  char maxMin;
  cin >> maxMin;
  int numA, numB;
  cin >> numA >> numB;

  if (maxMin != 'm' && maxMin != 'M') {
    cout << "Input non valido\n";
    return 1;
  }

  if ((maxMin == 'm' && numA <= numB) || (maxMin == 'M' && numA >= numB)) {
    cout << numA << endl;
  } else {
    cout << numB << endl;
  }

  return 0;
}
