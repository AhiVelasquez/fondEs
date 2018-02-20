/*
SUDOKU!!!
TODO: Backtrack;
 */
 #include <iostream>
 #include <cstdlib>
 #include <ctime>
 using namespace std;

 const int dim = 9;

 bool cRiga (int schema[][dim], int riga, int n);
 bool cCol (int schema[][dim], int col, int n);
 bool cQuad (int schema[][dim], int x, int y, int n);
 void riempi(int schema[][dim]);
 void stampa(int schema[][dim]);

 int main() {
 	srand(time(0));
 	int schema [dim][dim] = {{0}};
 	riempi(schema);
    cout << endl;
 	stampa(schema);

 }

 bool cRiga (int schema[dim][dim], int riga, int n) {
 	for(int i = 0; i < dim; i++) {
 		if(schema[riga][i] == n) {
 			return false;
 		}
 	}
 	return true;
 }

 bool cCol (int schema[dim][dim], int col, int n) {
 	for(int i = 0; i < dim; i++) {
 		if(schema[i][col] == n) {
 			return false;
 		}
 	}
 	return true;
 }

 bool cQuad (int schema[][dim], int x, int y, int n) {
    x = x - (x % 3);
    y = y - (y % 3);
 	for (int i = x; i < x + 3; i++) {
 		for (int j = y; j < y + 3; j++) {
 			if(schema[i][j] == n) {
 				return false;
 			}
 		}
 	}
 	return true;
 }

 void riempi(int schema[dim][dim]) {
 	int n, c = 0;
 	for(int i = 0; i < dim; i++) {
 		for(int j = 0; j < dim; j++) {
          while (true) {
             n = (rand() % 9) + 1;
 				c++;

             // if (cRiga(schema, i, n)) { // controllo ISOLATO sulla riga: OK!
             // if (cCol(schema, j, n)) { // controllo ISOLATO sulla colonna: OK!
             // if (cQuad(schema, i, j, n)) { // controllo ISOLATO sul quadrato: OK!

             // va in loop con un range inferiore a 1-11
             // if ((cRiga(schema, i, n) && cCol(schema, j, n))) {
 				if (c > 10000) {
 					break;
 				}
             // va in loop con un range inferiore a 1-15
             if (cRiga(schema, i, n) && cCol(schema, j, n) && cQuad(schema, i, j, n)) {
 					schema[i][j] = n;
                // cout << i << "," << j << endl;
                stampa(schema);
 					c = 0;
 					cout << endl << endl;
                break;
             }
             // cout << "  n " << n << endl;
 			}

 		}
 	}
 }

 void stampa(int schema[][dim]) {
 	for (int i = 0; i < dim; i++) {
 		for (int j = 0; j < dim; j++) {
 			cout << schema[i][j] << " ";
          if ((j+1) % 3 == 0 && j != 0) {
             cout << " ";
          }
 		}
       if ((i+1) % 3 == 0 && i != 0 && i != dim-1) {
          cout << endl;
       }
 		cout << endl;
 	}
 }
