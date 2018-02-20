/*
Esercizio 4.
Scrivere un programma opportunamente modularizzato in funzioni, che, letta una
sequenza di numeri interi da input (lunga al massimo 100 elementi) terminata da
un numero negativo, individui la sottosequenza crescente più lunga e la stampi
su standard output, indicando anche quanto è lunga.

Esempio:
data la sequenza
                        1 3 2 6 1 4 5 6 9 2 3 79 3 -1
i numeri in grassetto costituiscono la sottosequenza crescente di lunghezza
massima; il programma dovrebbe stampare su standard output i numeri 1 4 5 6 9 e
indicare che la lunghezza della sequenza è 5.
 */

#include <iostream>
using namespace std;

void leggo (int[], int&);
void seqCrescente (int[], int);

int main() {
   int seq[100];
   int dim;
   leggo(seq, dim);
   seqCrescente(seq, dim);
   return 0;
}

void leggo (int seq[], int& dim) {
   int n;
   cin >> n;
   while (n > -1) {
      seq[dim++] = n;
      cin >> n;
   }
}
void seqCrescente (int seq[], int dim) {
   int subSeq[100][2] = {{0}};
   int k = 0;
   subSeq[0][0] = 0; // indice
   subSeq[0][1] = 1; // lunghezza
   for (int i = 1; i < dim; i++) {
      if(seq[i] > seq[i-1]) {
         subSeq[k][1] += 1; // lunghezza
      } else {
         k++;
         subSeq[k][0] = i; // indice
         subSeq[k][1] = 1; // lunghezza
      }
   }

   // STAMPA di Debug
   // for (int i = 0; i < k; i++) {
   //   cout << "Subsequenza crescende " << i+1 << " inizia dall'indice " << subSeq[i][0] << " ed è lunga " << subSeq[i][1] << endl;
   // }
   //////////////////

   int max = 0;
   int iMax = 0;
   for (int i = 0; i < k; i++) {
      if(subSeq[i][1] > max) {
         max = subSeq[i][1];
         iMax = subSeq[i][0];
      }
   }

   cout << "La sequenza crescente più lunga (" << max << " elementi) è ";

   for (int i = iMax; i < iMax + max; i++ ) {
      cout << seq[i] << " ";
   }

   cout << endl;

}
