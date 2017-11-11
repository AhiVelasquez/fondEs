/*
Esercizio 1
Scrivere un programma in C++ che dati in input due numeri, a e b, restituisca in
output il massimo tra i due numeri.
Ad esempio, se a = 24 e b = 28, il programma restituirà 28; se a = -24 e b = -28,
il programma restituirà -24; se a = 15 e b = 15, il programma restituirà 15.
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int numeroA, numeroB;
  cin >> numeroA >> numeroB;

  if (numeroA >= numeroB) {
    cout << numeroA;
  } else {
    cout << numeroB;
  }
  return 0;
}
