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
#include <math.h>
using namespace std;

int main() {
  int candidatoA = 0, candidatoB = 0, candidatoC = 0;
  int voto;
  float totale = 0;
  cin >> voto;

  while (voto != 0) {
    totale++;
    if (voto == 1) {
      candidatoA++;
    } else if (voto == 2) {
      candidatoB++;
    } else {
      candidatoC++;
    }
    cin >> voto;
  }

  float percentualeC1 = (candidatoA / totale) * 100;
  float percentualeC2 = (candidatoB / totale) * 100;
  float percentualeC3 = (candidatoC / totale) * 100;

  bool ballottaggio = false;
  if (percentualeC1 < 50 && percentualeC2 < 50 && percentualeC3 < 50) {
    ballottaggio = true;
  }

  cout << "Candidato A " << candidatoA << " " << percentualeC1 << "\%";

  if (percentualeC1 > 50) {
    cout << "\tEletto\n";
  }

  cout << endl;

  cout << "Candidato B " << candidatoB << " " << percentualeC2 << "\%";
  if (percentualeC2 > 50) {
    cout << "\tEletto\n";
  }
    cout << endl;
  cout << "Candidato C " << candidatoC << " " << percentualeC3 << "\%";
  if (percentualeC3 > 50) {
    cout << "\tEletto\n";
  }
    cout << endl;

  if (ballottaggio) {

    if (candidatoA > candidatoC && candidatoB > candidatoC) {
      cout << "Candidati A e B al ballottaggio";
    }

    if (candidatoB > candidatoA && candidatoC > candidatoA) {
      cout << "Candidato B e C al ballottaggio";
    }

    if (candidatoC > candidatoB && candidatoA > candidatoB) {
      cout << "Candidato A e C al ballottaggio";
    }

    if (candidatoA == candidatoB && candidatoA == candidatoC) {
      cout << "Tutti al ballottaggio!";
    }
  }

  cout << endl;
  return 0;
}
