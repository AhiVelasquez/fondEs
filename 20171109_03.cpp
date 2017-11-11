/*

Esercizio 3.
Scrivere un programma che riceva una sequenza di dati relativi ai tassi di inquinamento
registrati giorno per giorno in una certa località ed in un certo periodo di tempo e determini
e stampi il numero dei picchi massimi dell'inquinamento. La sequenza è terminata da un
numero negativo.
I tassi di inquinamento sono interi tra 0 e 100. Un picco massimo di inquinamento è un
massimo relativo nella sequenza, ossia un dato che è maggiore sia di quello ad esso
precedente sia di quello ad esso seguente.
Per ogni picco il programma deve visualizzare il valore del tasso di inquinamento ed il
giorno in cui si verifica (i giorni vanno contati a partire da 1). Il programma deve altresì
visualizzare il numero dei picchi rilevati ed il numero totale dei dati in input. Il primo e
l'ultimo dato non vanno gestiti.
Esempio: se l'input è:
50 100 20 3 40 60 10 20 5 40 20 60 70 50 -1
l'output sarà:
100 2
60 6
20 8
40 10
70 13
Numero di picchi massimi rilevati: 5
Numero totale dei dati: 14


15 min prima bozza 
 */

#include <iostream>
using namespace std;

int main() {
  int inAttuale, inPrecedente, inSuccessivo;

  int picchiMassimi = 0;
  int totaleDati = 2;
  int giorno = 2;

  cin >> inPrecedente >> inAttuale >> inSuccessivo;

  while (inSuccessivo > -1) {
    if (inAttuale > inSuccessivo && inAttuale > inPrecedente ) {
      cout << inAttuale << " " << giorno << endl;
      picchiMassimi++;
    }

    totaleDati++;
    giorno++;

    inPrecedente = inAttuale;
    inAttuale = inSuccessivo;

    cin >> inSuccessivo;
  }

  cout << "Numero di picchi massimi rilevati: " << picchiMassimi << endl;
  cout << "Numero totale dei dati: " << totaleDati << endl;

  return 0;
}
