/*

 */
#include <iostream>
using namespace std;

void leggo(int [], int&);
void cercoA(int[], int, int[], int&);
void cercoB(int[], int, int[], int&);
bool multipliAinB(int[], int[], int, int);
bool multipli(int[], int, int);


int main() {
   int seq[1000] = {0};
   int dim;
   leggo(seq, dim);
   int puntiA[1000] = {0};
   int puntiB[1000] = {0};
   int dimA, dimB;
   cercoA(seq, dim, puntiA, dimA);
   cercoB(seq, dim, puntiB, dimB);
   for (int i = 0; i < dimA; i++) {
      cout << "Punti A: " << puntiA[i] << endl;
   }
   cout << endl;
   for (int i = 0; i < dimB; i++) {
      cout << "Punti B: " << puntiB[i] << endl;
   }
   cout << (multipliAinB(puntiA, puntiB, dimA, dimB) ? "OK" : "NO");
   return 0;
}

void leggo(int seq[], int& dim) {
   dim = 0;
   int n;
   cin >> n;
   while (n != 0) {
      seq[dim++] = n;
      cin >> n;
   }
}
void cercoA(int seq[], int dim, int puntiA[], int& dimA) {
   dimA = 0;
   for (int i = 1; i < dim-1; i++) {
      if (seq[i - 1] % 2 == 0 && seq[i] % 2 != 0 && seq[i + 1] % 2 == 0) {
         puntiA[dimA++] = seq[i];
      }
   }
}
void cercoB(int seq[], int dim, int puntiB[], int& dimB) {
   dimB = 0;
   for (int i = 1; i < dim-1; i++) {
      if (seq[i - 1] % 2 != 0 && seq[i] % 2 == 0 && seq[i + 1] % 2 != 0) {
         puntiB[dimB++] = seq[i];
      }
   }
}
bool multipliAinB(int puntiA[], int puntiB[], int dimA, int dimB) {
   for(int i = 0; i < dimA; i++) {
      if(multipli(puntiB, dimB, puntiA[i])) {
         return true;
      }
   }
   return false;
}
bool multipli(int punti[], int dim, int n) {
   for (int i = 0; i < dim; i++) {
      if (punti[i] % n == 0) {
         return true;
      }
   }
   return false;
}
