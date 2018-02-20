/*
--------------------------------------------------------------------------------
Si implementi in C++ una funzione che, ricevuta come parametro una matrice di
interi di dimensioni NxM contenente in tutte le celle il numero 0, legga da
input una sequenza di numeri interi terminata dal numero “-1” e utilizzi tali
numeri per popolare la matrice, seguendo un ordine “a serpentina”. Ciò implica
che la prima riga (indice 0) sarà popolata da sinistra verso destra, la seconda
riga (indice 1) da destra verso sinistra, la terza riga (indice 2) da sinistra
verso destra e così via... Se la sequenza viene terminata prima di completare la
matrice, allora le posizioni non utilizzate rimarranno impostate a 0. Se invece
si leggono in sequenza NxM numeri diversi da -1, allora si deve comunque
terminare la lettura producendo in output il messaggio: “Raggiunto il numero
massimo di elementi!”, senza proseguire oltre la lettura.
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
Supponendo che la matrice sia di dimensioni 4x3 e che la sequenza immessa sia:
                        1, 2, 3, 4, 5, 6, 7, -1
allora la matrice dovrebbe contenere i seguenti valori:
                        1  2  3
                        6  5  4
                        7  0  0
                        0  0  0
--------------------------------------------------------------------------------
Supponendo, invece, che la sequenza immessa sia:
                        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
allora la sequenza dovrebbe comunque essere terminata e dovrebbe essere prodotto
in output il messaggio specificato precedentemente. Inoltre la matrice dovrebbe
contenere i seguenti valori:
                        1  2  3
                        6  5  4
                        7  8  9
                        12 11 10
--------------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;
const int M = 3;

void leggi(int [], int&, int);
void riempi(int [][M], int, int[], int);
void stampa(int [][M], int);

int main() {
   const int N = 4;
   int matrix[N][M] = {{0}};
   int seq[100];
   int dimSeq;
   leggi(seq, dimSeq, N);
   riempi(matrix, N, seq, dimSeq);
   stampa(matrix, N);
   return 0;
}

void leggi(int seq[], int& dim, int N) {
   dim = 0;
   int n;
   cin >> n;
   while (n != -1) {
      if (dim >= N*M) {
         cout << "  Raggiunto numero massimo di elementi!" << endl;
         break;
      }
      seq[dim++] = n;
      cin >> n;
   }
}

void riempi(int matrix[][M], int dim, int seq[], int dimSeq){
	int k = 0;
	for (int i = 0; i < dim; i ++) {
		if (i % 2 == 0 && k < dimSeq) {
			for (int j = 0; j < M; j++)
				matrix[i][j] = seq[k++];
		} else if (i % 2 != 0 && k < dimSeq) {
			for (int j = M-1; j >= 0; j--)
				matrix[i][j] = seq[k++];
		}
	}
}

void stampa(int matrix[][M], int N) {
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         cout << matrix[i][j] << "\t";
      }
      cout << endl;
   }
}
