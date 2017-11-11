/*

Esercizio 3.
Scrivere in C++ un programma che aiuti un alunno della scuola elementare ad imparare le
4 operazioni (addizione, sottrazione, moltiplicazione e divisione). Il programma dovrebbe
porre all’alunno domande del tipo:
Quanto fa 6 * 7?
L’alunno digita la risposta. Il programma la controlla e, se è corretta visualizza una a caso
fra queste 4 frasi
  Bravo!
  Eccellente!
  Continua Così!
  Ottimo Lavoro!

e passa alla domanda successiva. Se la risposta è sbagliata, il programma visualizza una frase tra le seguenti

  No, riprova!
  Sbagliato. Prova ancora!
  Non ti arrendere, riprova!
  Niente da fare, Prova ancora!

e consente all’alunno di riprovare finché (si spera) non dà la risposta corretta.
Le domande da porre all’alunno devono essere completamente casuali, cioè sia gli
operandi che gli operatori devono essere scelti in modo random. Gli operandi devono
essere interi positivi di una cifra sola. Nel caso in cui l’operatore estratto sia la divisione,
l’alunno deve inserire come risultato solo la parte intera.

 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  srand(time(0));
  string frasiPositive[4];
  string frasiNegative[4];
  char operatori[4];

  frasiPositive[0] = "Bravo!";
  frasiPositive[1] = "Continua così!";
  frasiPositive[2] = "Eccellente!";
  frasiPositive[3] = "Ottimo lavoro!";

  frasiNegative[0] = "No, riprova!";
  frasiNegative[1] = "Sbagliato. Prova ancora!";
  frasiNegative[2] = "Non ti arrendere, riprova!";
  frasiNegative[3] = "Niente da fare, Prova ancora!";

  operatori[0] = '+';
  operatori[1] = '-';
  operatori[2] = '*';
  operatori[3] = '/';

  bool rispostaSbagliata = true;

  int num1 = rand() % 10 + 1;
  int num2 = rand() % 10 + 1;
  char op = operatori[rand() % 4];
  int rispostaCorretta;

  switch (op) {
    case '+':
    rispostaCorretta = num1 + num2;
    break;
    case '-':
    rispostaCorretta = num1 - num2;
    break;
    case '*':
    rispostaCorretta = num1 * num2;
    break;
    case '/':
    rispostaCorretta = num1 / num2;
    break;
  }

  cout << "Quanto fa " << num1 << " " << op << " " << num2 << "?" <<endl;
  int risposta;
  cin >> risposta;

  while (risposta != rispostaCorretta) {
    cout << frasiNegative[rand() % 4] << endl;
    cin >> risposta;
  }

  cout << frasiPositive[rand() % 4] << endl;
  return 0;
}
