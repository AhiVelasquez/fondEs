/*

Esercizio 2 – Simulate il gioco con i dadi "CRAPS".
Il gioco con i dadi CRAPS viene giocato con due dadi. Ogni volta che il paio di dadi viene
lanciato ne vengono sommati i due numeri ottenuti; la somma sarà quindi un intero
compreso tra 2 e 12.

Il giocatore VINCE immediatamente se ottiene un punteggio di 7 o 11; PERDE
immediatamente se ottiene 2, 3 oppure 12. Se il giocatore ottiene 4, 5, 6, 8, 9, oppure 10,
mantiene questo suo punteggio e ripete il lancio dei dadi, vince ottenendo ancora questo
suo punteggio, oppure perde ottenendo un 7.

RICORDA CHE per generare un numero casuale occorre innanzitutto includere il pacchetto
cstdlib con l'istruzione #include<cstdlib>; poi si utilizza la funzione rand() che genera un
numero pseudo-casuale, ma prima di utilizzarla occorre aggiungere una sola volta all'inizio
del main l'istruzione srand(time(0)).

 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  int dado1, dado2;
  srand(time(0));
  dado1 = rand() % 6 + 1;
  dado2 = rand() % 6 + 1;
  int sommaDadi = dado1 + dado2;

  cout << "Risultato lancio: " << endl;
  cout << sommaDadi << endl;

  if (sommaDadi == 7 || sommaDadi == 11) {
    cout << "HAI VINTO!!!!" << endl;
  } else if (sommaDadi == 2 || sommaDadi == 3 || sommaDadi == 12) {
    cout << "HAI PERSO!!!!" << endl;
  } else {
    int sommaDadiPrecedente = sommaDadi;

    cout << "Rilancia...\n";
    bool rilancia = true;
    dado1 = rand() % 6 + 1;
    dado2 = rand() % 6 + 1;
    sommaDadi = dado1 + dado2;

    while (rilancia) {
      cout << "Nuovo lancio... " << sommaDadi << endl;
      if (sommaDadi == sommaDadiPrecedente) {
        cout << "HAI VINTO!\n";
        rilancia = false;
      } else if (sommaDadi == 7) {
        cout << "HAI PERSO!\n";
        rilancia = false;
      }

      dado1 = rand() % 6 + 1;
      dado2 = rand() % 6 + 1;
      sommaDadi = dado1 + dado2;
    }

  }

  return 0;
}
