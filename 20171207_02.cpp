/*

Esercizio 2.
Scrivere un programma che simuli il gioco Monty Hall. Il gioco Monty Hall è così chiamato dal
nome del conduttore di un gioco televisivo in cui un concorrente può vincere un’auto indovinando
la porta dietro la quale si trova l’auto.
Il giocatore sceglie una porta, allora il conduttore ne apre un’altra dietro la quale non si trova l’auto.
A questo punto del gioco, il giocatore può scegliere se cambiare la sua scelta con la terza porta.
Suggerimento:
Rappresentiamo le porte con i numeri da 1 a 3. Per fare in modo che il gioco non sia sempre uguale,
utilizziamo la funzione rand() per scegliere in modo casuale la porta (e quindi il numero) dietro la
quale nascondere l’auto.
L’algoritmo dovrebbe eseguire le seguenti operazioni:
1. Determina la porta con dietro l’auto in base ad un numero casuale estratto.
2. Stampa la spiegazione del gioco (funzione).
3. Chiede al giocatore di scegliere una porta (funzione).
4. Determina la porta da aprire ed il cambio da proporre in base alla porta scelta ed a quella vincente
(funzione).
5. Propone il cambio al giocatore ed acquisisce la sua scelta (funzione).
6. Determina il risultato finale e lo comunica al giocatore (funzione).

 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int scegliPorta();
void stampaSpiegazione();
int aproPorta(int, int);
int cambioPorta(int, int);
int faseFinale(int, int);
int scegliPorta();

int main() {
   srand(time(0));
   int macchina = rand() % 3 + 1;
   // 1. Determina la porta con dietro l’auto in base ad un numero casuale estratto.
   stampaSpiegazione();
   int porta = scegliPorta();
   int portaAperta = aproPorta(macchina, porta);
   cout << "\nApro la porta... " << portaAperta << " ...niente!"<< endl;
   cout << "DEBUG: L'auto è in: " << macchina << endl;

   int cambio = cambioPorta(porta, portaAperta);

   faseFinale(macchina, cambio);

   return 0;
}


// 2. Stampa la spiegazione del gioco (funzione).
void stampaSpiegazione() {
   cout << "### Monty Hall Games ###" << endl;
   cout << "Dietro una di queste tre porte c'è un'auto." << endl;
   cout << "Indovina dov'è!" << endl;
}

// 3. Chiede al giocatore di scegliere una porta (funzione).
int scegliPorta() {
   int porta;
   do {
      cout << "Fa la tua scelta... ";
      cin >> porta;
   } while (porta < 1 || porta > 3);
   return porta;
}

// 4. Determina la porta da aprire ed il cambio da proporre in base alla porta scelta ed a quella vincente (funzione).
int aproPorta(int automobile, int porta) {
   if (automobile == 1 && porta == 1) {
      return 2;
   } else if (automobile == 2 && porta == 2) {
      return 1;
   } else if (automobile == 3 && porta == 3) {
      return 3;
   } else if (automobile == 2 && porta == 1) {
      return 3;
   } else if (automobile == 2 && porta == 3) {
      return 1;
   } else if (automobile == 3 && porta == 1) {
      return 2;
   } else if (automobile == 3 && porta == 2) {
      return 1;
   } else if (automobile == 1 && porta == 2) {
      return 3;
   } else if (automobile == 1 && porta == 3) {
      return 2;
   }
   return -1;
}

// 5. Propone il cambio al giocatore ed acquisisce la sua scelta (funzione).
int cambioPorta(int portaScelta, int portaAperta) {
   cout << "\nHai ancora la possibilità di cambiare porta...\n\tVuoi farlo? [0 accetti]" << endl;
   int scelta;
   cin >> scelta;
   if (scelta == 0) {
      if (portaScelta == 1 && portaAperta == 2) {
         return 3;
      } else if (portaScelta == 1 && portaAperta == 3) {
         return 2;
      } else if (portaScelta == 2 && portaAperta == 1) {
         return 3;
      } else if (portaScelta == 2 && portaAperta == 3) {
         return 1;
      } else if (portaScelta == 3 && portaAperta == 1) {
         return 2;
      } else if (portaScelta == 3 && portaAperta == 2) {
         return 1;
      }
   }

   return portaScelta;
}
// 6. Determina il risultato finale e lo comunica al giocatore (funzione).
int faseFinale(int automobile, int portaScelta) {
   if (automobile == portaScelta) {
      cout << "Hai vinto!" << endl;
   } else {
      cout << "Hai perso!" << endl;
   }
   return 0;
}
