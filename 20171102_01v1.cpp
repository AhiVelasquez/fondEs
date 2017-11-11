/*
 * Esercizio 1.
Implementare in C++ un programma che simuli (in maniera molto semplice) un seggio
elettorale. In pratica si sa che ci sono 3 candidati (per semplicità siano 1, 2, 3). Si deve
leggere da input una sequenza, i cui possibili valori sono quattro: 1, 2, 3, 0, dove 0 è il
tappo (sta per “fine”), e si suppone che venga inserito dal presidente di seggio al termine
della giornata di voto. A seconda del numero letto in input, si dovrà incrementare il
contatore dei voti di ciascun candidato (1,2,3). Al termine della sequenza, si dovranno
stampare i voti ricevuti da ciascun candidato.
Variante 1: in aggiunta al totale dei voti per ciascun candidato, si dia in output anche la
percentuale di ciascuno sul totale (questa si ottiene dividendo il numero di voti per il totale
dei voti e moltiplicando per 100).
Variante 2: in aggiunta a quanto specificato nella variante 1, si stabilisca se almeno uno
dei tre candidati ha superato il 50% dei voti e quindi può essere dichiarato eletto, o se
invece è necessario un ballottaggio; in quest’ultimo caso, indicare quali sono i due
candidati che accederanno al ballottaggio stesso (ovvero i due candidati con il maggior
numero di voti).
 */

#include <iostream>
using namespace std;

int main() {
  int candidatoA = 0, candidatoB = 0, candidatoC = 0;
  int voto;
  cin >> voto;

  while (voto != 0) {
    if (voto == 1) {
      candidatoA++;
    } else if (voto == 2) {
      candidatoB++;
    } else {
      candidatoC++;
    }
    cin >> voto;
  }

  cout << "Candidato A " << candidatoA << endl;
  cout << "Candidato B " << candidatoB << endl;
  cout << "Candidato C " << candidatoC << endl;

  return 0;
}
