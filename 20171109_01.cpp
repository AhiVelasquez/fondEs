/*
Esercizio 1.
Scrivere un programma che legga da standard input una sequenza di 10 numeri interi e
stampi su standard output i due numeri più grandi (cioè massimo e submassimo).
Esempio: se la sequenza in input fosse:
10 -13 4 6 -2 99 11 37 23 17
il programma dovrebbe stampare su standard output qualcosa di simile a:
numero massimo: 99
numero sub-massimo: 37

15min
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  int max, submax;
  cin >> n;
  max = n;

  for (int i = 0; i < 9; i++) {
    if (n > max) {
      max = n;
    } else if (n > submax) {
      submax = n;
    }
    cin >> n;
  }

  cout << "Numero massimo: " << max << endl;
  cout << "Numero submassimo: " << submax << endl;
  return 0;
}
