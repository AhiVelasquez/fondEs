/*
Si implementi poi un main nel quale, preso da input
un array di telefonata, stampi la prima e l'ultima
telefonata della giornata e l'orario nel quale è
iniziata la telefonata più lunga.
*/

#include "Telefonata.hpp"
#include <vector>
using namespace std;
unsigned primaTel(vector<Telefonata>);
unsigned ultimaTel(vector<Telefonata>);
unsigned telLunga(vector<Telefonata>);

int main() {
   /*
   Orario i(1,23,00); // richiama il costruttore con 3 parametri
   Orario f(2,43,32);
   int num = 555123456; // Molto american-style XD!

   Telefonata tel1;
   Telefonata tel2(i,f,num);
   Telefonata tel3;


   // Get e set della telefonota inizializzata con il costruttore a 0 parametri;
   cout << tel1.getNum() << endl;
   cout << tel1.getInizio() << endl; // funziona perchè il tipo di ritorno, orario, ha << definito
   tel1.setFine(f);
   tel1.setInizio(i);
   cout << tel1.getInizio() << endl;
   cout << tel1.getFine() << endl;

   // Get e set della telefonata inizializzata con il costruttore a 0 parametri
   // e che usa i setter che richiamano l'overload degli operatori del tipo Orario
   tel3.setFine();
   tel3.setInizio();
   cout << tel3.getInizio() << endl;
   cout << tel3.getFine() << endl;

   // Get e set della telefonata inizializzata con il costruttore a 3 parametri
   cout << tel2.getInizio() << endl;
   cout << tel2.getFine() << endl;
   tel2.setInizio(Orario (1,2,3));
   tel2.setFine(Orario (4,5,6));
   cout << tel2.getInizio() << endl;
   cout << tel2.getFine() << endl;

   // Durate
   cout << tel1.durata() << "\n";
   cout << tel2.durata() << "\n";
   cout << tel3.durata() << "\n";

   cout << "t1 == t2 " << (tel1 == tel2 ? "SI" : "NO") << "\n";
   cout << "t2 == t3 " << (tel2 >= tel3 ? "SI" : "NO") << "\n";
   cout << "t3 >= t1 " << (tel3 >= tel1 ? "SI" : "NO") << "\n";
   */

   unsigned elementi;
   cin >> elementi;
   vector <Telefonata> lista;
   for(unsigned i = 0; i < elementi; i++) {
      Telefonata n;
      n.setFine();
      n.setInizio();
      n.setNum();
      lista.push_back(n);
   }

   /*
   for(unsigned i = 0; i < lista.size(); i++) {
      cout << "Telefonata " << i << " " << lista[i].durata() << endl;
   }
   */

   unsigned prima = primaTel(lista);
   cout << "Prima telefonata della giornata (" << prima << ")"
         << " iniziata alle ore " << lista[prima].getInizio()
         << " finita alle ore " << lista[prima].getFine()
         << " inoltrata al numero " << lista[prima].getNum()
         << " e durata " << lista[prima].durata()
         << " sec" << endl;

   unsigned ultima = ultimaTel(lista);
   cout << "Ultima telefonata della giornata (" << ultima << ")"
         << " iniziata alle ore " << lista[ultima].getInizio()
         << " finita alle ore " << lista[ultima].getFine()
         << " inoltrata al numero " << lista[ultima].getNum()
         << " e durata " << lista[ultima].durata()
         << " sec" << endl;

   unsigned tl = telLunga(lista);
   cout << "Telefonata più lunga (" << tl << ") iniziata alle ore " << lista[tl].getInizio() << endl;

   return 0;
}

unsigned primaTel(vector<Telefonata> lista) {
   unsigned min = 0;
   for (unsigned i = 1; i < lista.size(); i++) {
      // TODO ci va il < stretto, ma va implementato nella classe Orario
      if (lista[i].getInizio() <= lista[min].getInizio()) {
         min = i;
      }
   }
   return min;
}
unsigned ultimaTel(vector<Telefonata> lista) {
   unsigned max = 0;
   for (unsigned i = 1; i < lista.size(); i++) {
      // TODO ci va il < stretto, ma va implementato nella classe Orario
      if (lista[max].getInizio() <= lista[i].getInizio()) {
         max = i;
      }
   }
   return max;
}
unsigned telLunga(vector<Telefonata> lista) {
   unsigned max = 0;
   for (unsigned i = 1; i < lista.size(); i++) {
      if (lista[i].durata() > lista[max].durata()) {
         max = i;
      }
   }
   return max;
}
