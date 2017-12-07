/*
Esercizio 1.
Si scriva in C++ una funzione che, letta da standard input una sequenza di numeri interi terminati da
un “tappo” pari a 17, restituisca “true” solo se tutti gli elementi sono divisibili per 17 oppure minori
di 17. Si scriva un main di prova.
ESEMPIO: se la sequenza fosse {2 -5 34 6 51 17} allora il metodo dovrebbe restituire “true”.
{2 -5 18 6 51 17} allora dovrebbe restituire “false”.
*/
#include <iostream>
using namespace std;

bool divisibile(int);
bool minore(int);
bool condizione(int);

int main() {
   int n;
   bool check = true;
   cin >> n;
   while (n != 17) {
      if (!condizione(n)) {
         check = false;
      }
      cin >> n;
   }
   cout << (check? "OK": "NO");
   return 0;
}

bool condizione(int n) {
   return (divisibile(n) || minore(n) ? true : false);
}

bool divisibile(int n) {
   return (n % 17 == 0 ? true : false);
}

bool minore(int n) {
   return (n < 17 ? true : false);
}
