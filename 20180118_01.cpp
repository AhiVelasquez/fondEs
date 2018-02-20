/*

Si implementi in C++ una funzione che, ricevuti come parametri un array di
caratteri V di lunghezza n ed un carattere c, restituisca true se nell’array V
non capita mai che ci siano più di tre caratteri consecutivi diversi dal
carattere c, false altrimenti.

Esempio:
Se l’array in input fosse V= {u, a, s, f, u, d, d, u, e, r, p} ed il carattere
fosse c=’u’, il metodo dovrebbe restituire true. Se, invece, l’array in input
fosse V= { x, u, y, a, s, f, u, d, d}, ed il carattere sempre c=’u’, il metodo
dovrebbe restituire false: infatti è facile notare come si trovi almeno una
sequenza composta da più di tre caratteri consecutivi diversi da u (in
particolare, la sequenza : y, a, s, f).

 */
#include <iostream>
using namespace std;

bool check(char[], int, char);

int main() {
   char a1[100] = {'u', 'a', 's', 'f', 'u', 'd', 'd', 'k', 'e', 'r', 'p'};
   char a2[100] = { 'x', 'u', 'y', 'a', 's', 'f', 'u', 'd', 'd'};
   char c = 'u';
   int n1 = 11;
   int n2 = 9;

   cout << (check(a1, n1, c)? "SI" : "NO") << endl;
   cout << (check(a2, n2, c)? "SI" : "NO") << endl;
   return 0;
}

bool check(char seq[], int dim, char c) {
	bool verifica = true;
	for (int i = 0; i < dim; i++) {
		if (seq[i] == c) {
         int l = 1;
			while (seq[i+l] != c && i+l < dim) {
            l++;
			}
         // cout << l << endl;
         if (l > 4) {
            verifica = false;
         }
		}
	}
	return verifica;
}
