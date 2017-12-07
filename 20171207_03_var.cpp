/*
Si scriva un programma C++ con cui i clienti possano interagire nel seguente modo: su schermo si
legge la domanda: “Pasto per bambini o pasto per adulti? (B/A/Z per terminare)”.
Nel caso in cui si scelga il pasto per bambini (cioè viene letto il carattere ‘B’), viene posta una
nuova domanda: “Si desidera un gadget? (S/N)”; se la risposta a questa domanda è SI (cioè si
inserisce il carattere ‘S’) a video viene stampato il nome di un gadget a caso, e poi viene ristampata
la domanda sul tipo di pasto, pronta per il prossimo cliente; se la risposta è NO (cioè si inserisce il
carattere ‘N’), oppure era stato scelto il pasto per adulti al passo precedente, si torna direttamente
alla domanda sul tipo di pasto, pronta per il prossimo cliente; se invece si termina (cioè viene letto il
carattere ‘Z’), il programma termina, e stampa a video il riassunto della giornata: il numero di pasti
per adulti distribuiti, il numero di pasti per bambini distribuiti, e per ciascuno dei 5 gadget il numero
distribuito.
Esempio:
Pasti per adulti: 34
Pasti per bambini: 12
Nanà: 1
Hello Spank: 2
Bum Bum: 5
Gigi la Trottola: 0
George il Re della Giungla: 4
 */

 #include <iostream>
 #include <cstdlib>
 #include <ctime>
 #include <vector>
 using namespace std;

void stampa(int adulti, int bambini, int g1, int g2, int g3, int g4, int g5) {
   cout << "Pasti per adulti: " << adulti << endl;
   cout << "Pasti per bambini: " << bambini << endl;
   cout << "Nanà: " << g1 << endl;
   cout << "Hello Spank: " << g2 << endl;
   cout << "Bum Bum: " << g3 << endl;
   cout << "Gigi la Trottola: " << g4 << endl;
   cout << "George il Re della Giungla: " << g5 << endl;
}
void gadgets(int n, int &g1, int &g2, int &g3, int &g4, int &g5, int &gs) {
   /*
   Nanà: 1
   Hello Spank: 2
   Bum Bum: 5
   Gigi la Trottola: 0
   George il Re della Giungla: 4
   */
   switch(n){
      case 1:
         gs = 1;
         g1 = g1 + 1;
         cout << "Nana!";
         break;
      case 2:
         gs = 2;
         g2 = g2 + 1;
         cout << "Hello spank!";
         break;
      case 3:
         gs = 3;
         g3 = g3 + 1;
         cout << "Bum Bum!";
         break;
      case 4:
         gs = 4;
         g4 = g4 + 1;
         cout << "Giggi la trottola!";
         break;
      case 5:
         gs = 5;
         g5 = g5 + 1;
         cout << "George il re della giungla!";
         break;
   }
   cout << endl;
}

 int main() {
    srand(time(0));
    int adulti = 0, bambini = 0;
    int g1 = 0, g2 = 0, g3 = 0, g4 = 0, g5 = 0;
    int gs = 0;

    cout << "Pasto per bambini o pasto per adulti? (B/A/Z per terminare) ";
    char pasto;
    cin >> pasto;

    while (pasto != 'Z') {
      if (pasto == 'B') {
         cout << "Si desidera un gadget? (S/N) ";
         char sceltaGadget;
         cin >> sceltaGadget;
         if (sceltaGadget == 'S') {
            int r = rand()%5+1;
            while( r == gs) {
               r = rand()%5+1;
            }
            gadgets(r, g1, g2, g3, g4, g5, gs);
         }
         bambini++;
      } else {
         adulti++;
      }
      cout << "\nPasto per bambini o pasto per adulti? (B/A/Z per terminare) ";
      cin >> pasto;
   }

   stampa(adulti, bambini, g1, g2, g3, g4, g5);
   return 0;
 }
