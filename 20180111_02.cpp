#include <iostream>
using namespace std;
const int n = 4;

void sella(int matrix[][n]);
bool maxRiga(int matrix[][n], int riga, int n);
bool minCol(int matrix[][n], int col, int n);

int main() {

   int a[][n] = {{1,0,0,0},
                  {4,5,6,7},
                  {2,9,4,0},
                  {1,2,3,4}};
   int b[][n] = {{1,0,0,0},
                  {4,5,0,0},
                  {2,9,4,0},
                  {1,2,3,4}};
   sella(a);
   sella(b);
   return 0;
}

void sella(int matrix[][n]) {
   bool sella = false;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (maxRiga(matrix, i, matrix[i][j]) && minCol(matrix, j, matrix[i][j])) {
            sella = true;
            cout << "Punto di sella in posizione (" << i << ", " << j << ")" << endl;
         }
      }
   }
   if (!sella) {
      cout << "Non esistono punti di sella" << endl;
   }
}

bool maxRiga(int matrix[][n], int riga, int num) {
   for (int i = 0; i < n; i++) {
      if (matrix[riga][i] < n) {
         return false;
      }
   }
   return true;
}

bool minCol(int matrix[][n], int col, int num) {
   for (int i = 0; i < n; i++) {
      if (matrix[i][col] > n) {
         return false;
      }
   }
   return true;
}
