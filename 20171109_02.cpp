/*
Scrivere un programma che data in input una sequenza di interi composta da
sottosequenze separate da uno zero, calcoli la somma di ciascuna sottosequenza. La
sequenza è terminata da una coppia di zeri.
Esempio: se la sequenza in input fosse:
2 4 -1 0 4 3 1 -5 0 1 1 2 0 3 6 0 0
le sottosequenze sarebbero
2 4 -1 4 3 1 -5 1 1 2 3 6
per cui il programma dovrebbe stampare su standard output i seguenti numeri:
5 (che è uguale a 2 + 4 – 1); 3 (che è uguale a 4 + 3 + 1 – 5); 4 (che è uguale a 1 + 1 + 2);
e infine 9 (che è uguale a 3 + 6).

20min

 */

#include <iostream>
using namespace std;

int main() {
  int n, nMenoUno;
  int somme[1000];
  somme[0] = 0;

  cin >> n >> nMenoUno;
  // manca il controllo per cui primo e secondo input sono doppio zero...
  int sequenza = 0;
  somme[sequenza] = n;
  somme[sequenza] = nMenoUno;

  while (n != 0 || nMenoUno != 0) {
    somme[sequenza] += n;
    nMenoUno = n;
    if (n == 0) {
      sequenza++;
      somme[sequenza] = 0;
    }
    cin >> n;
  }

  for (int i = 0; i < sequenza; i++) {
    cout << somme[i] << endl;
  }

  return 0;
}
