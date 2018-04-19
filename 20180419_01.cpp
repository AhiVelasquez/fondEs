/*

1) la lunghezza di C è uguale alla lunghezza di A più la lunghezza di B;

2) le lettere di cui C è composta provengono o dalla parola A o dalla parola B
secondo lo schema (in altre parole: se nella posizione x dello schema è presente
il carattere ‘a’ (risp. ‘b’) allora nella posizione x della parola C si deve
trovare una lettera proveniente dalla parola A (risp. B));

3) l’ordine in cui le lettere compaiono in A e B è rispettato in C.

---
A = MEDI
B = RIONE
C = MERIDIONE
formano un incastro di parole secondo lo schema
aabbaabbb
---
A=CARE
B=SOLA
C=CASOLARE
non formano un incastro secondo lo schema
bbaaaabb
(in questo caso l’incastro avrebbe richiesto che C fosse SOCARELA).
---
*/

#include <iostream>
using namespace std;

int main() {
   char a[100];
   char b[100];
   char c[100];
   cin>>a>>b>>c;

   char key[100];
   cin >> key;

   int ia = 0;
   int ib = 0;

   bool check = true;

   for(int i = 0; c[i] != '\0'; i++) {
      switch(key[i]) {
         case 'a':
            if(c[i] == a[ia]) ia++;
            else check = false;
            break;
         case 'b':
            if(c[i] == b[ib]) ib++;
            else check = false;
            break;
      }
   }

   cout << (check? "SI" : "NO");

   return 0;
}
