’/*
Esercizio 3
Scrivere un programma in C++ che individui il giocatore vincente in una mano del
gioco della briscola. Ovvero, si richiederanno come input il seme della briscola, la
carta tirata dal primo giocatore e la carta tirata dal secondo giocatore; mentre
come output si restituirà una stringa che dica se ha vinto il primo giocatore
oppure il secondo.
 */

#include <iostream>
using namespace std;

int main() {
  char semeBriscola;
  int cartaPrimo;
  char semePrimo;
  int cartaSecondo;
  char semeSecondo;
  bool cartaPrimoMaggiore = false;


  cout << "*****************************************************\n";
  cout << "Che seme è la briscola? (S/D/C/B): ";
  cin >> semeBriscola;
  cout << "Carta tirata dal primo giocatore:\n";
  cout << "seme (S/D/C/B): ";
  cin >> semePrimo;
  cout << "valore (1/2/3/4/5/6/7/8/9/10): ";
  cin >> cartaPrimo;
  cout << "Carta tirata dal secondo giocatore:\n";
  cout << "seme (S/D/C/B): ";
  cin >> semeSecondo;
  cout << "valore (1/2/3/4/5/6/7/8/9/10): ";
  cin >> cartaSecondo;


  if ((cartaPrimo == 1) || (cartaPrimo == 3 && cartaSecondo != 1)) {
    cartaPrimoMaggiore = true;
  }

  if ((semePrimo == semeSecondo && cartaPrimoMaggiore) || ( !(semePrimo == semeSecondo) && !(semeSecondo == semeBriscola) ) ) {
    cout << "Ha vinto il primo giocatore";
  } else {
    cout << "Ha vinto il secondo giocatore";
  }
  cout << "\n*****************************************************" << endl;
  return 0;
}
