/*

Esercizio 4.

Scrivere un programma C++ che implementi le seguenti funzionalità:
  - Estrazione di un numero casuale compreso tra 0 e 20, sia x;
  - Lettura da input di una sequenza di numeri interi terminata da -1;
  - Contare quante volte nella sequenza letta la somma di due numeri consecutivi è
uguale ad x; sia il risultato del conteggio z: stampare su standard output z.

Esempio: si supponga estratto x=5; si supponga che la sequenza in input sia: 3 2 1 4 1 3
2 3 -1; Si dovrà stampare in output z=5.

 */

#include <iostream>
using namespace std;

int main() {
  srand(time(0));

  int numeroRandom = rand() % 20;
  int contatore = 0;
  int a, b;

  cin >> a >> b;

  while (b != -1) {
    if ((a + b) == numeroRandom) {
      contatore++;
    }
    a = b;
    cin >> b;
  }

  cout << contatore << endl;
  return 0;
}
