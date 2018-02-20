#include <iostream>
using namespace std;
void mescola (int [], int);
void stampa (int [], int);

int main() {
   int a[] = {11,22,33,44,55,66,77,88};
   int dim = 8;
   stampa(a, dim);
   mescola(a, dim);
   stampa(a, dim);
   return 0;
}

void mescola (int a[], int dim) {
   int temp[100] = {0};
   int pari = 0;
   int dispari = 1;
   for (int i = 1; i < dim-1; i++) {
      if (i < dim/2) {
         temp[dispari] = a[i];
         dispari += 2;
      } else {
         temp[pari] = a[i];
         pari += 2;
      }
   }

   for (int i = 1; i < dim-1; i++) {
      a[i] = temp[i-1];
   }
}

void stampa(int a[], int dim) {
   for (int i = 0; i < dim; i++) {
      cout << a[i] << " ";
   }
   cout << endl;
}
