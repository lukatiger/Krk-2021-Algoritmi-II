#include <bits/stdc++.h>
using namespace std;

typedef vector < vector <int> > matrix;

matrix multiply(matrix a, matrix b) {
    int width_a = a[ 0 ].size();
    int height_a = a.size();
    int width_b = b[ 0 ].size();
    int height_b = b.size();
    
    vector <int> tmp(width_b, 0);
    matrix result(height_a, tmp);

    assert(width_a == height_b); // assert provjerava nesto sto "mora vrijediti"

    for(int i = 0; i < height_a; i++) {
        for(int j = 0; j < width_b; j++) {
            for(int k = 0; k < width_a; k++) {
                result[ i ][ j ] += a[ i ][ k ] * b[ k ][ j ];
            }
        }
    }

    return result;
}

void ispis(matrix a) {
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[ i ].size(); j++) {
            cout << a[ i ][ j ] << " ";
        }
        cout << endl;
    }
}

vector <matrix> potencije; 

/*
potencije[ 0 ] == A^(2^0) == A^1 == A
potencije[ 1 ] == A^(2^1) == A^2 == A*A
potencije[ 2 ] == A^(2^2) == A*A*A*A
potencije[ 3 ] == A^(2^3)

Rekurzivna formula:
potencije[ n ] = multiply(potencije[ n-1 ], potencije[ n-1 ])
*/

int main() {
    matrix A = {{2, 3, 1}, {0, 1, 0}};
    matrix B = {{1, 0}, {1, -1}, {2, 1}};

    ispis(multiply(A, B));   

    // matrix C = {{2, 3}, {0, 1}};
    // matrix D = {{1, 0}, {1, -1}, {2, 1}};
    // multiply(C, D); ---> ovo javlja runtime error jer se assert trigera
    
    return 0;
}

/*
A = [[0, 1], [1, 1]]

B = {{1}, {1}}

A * B {., .}
A * A * B = {F3, F4}
A ^ 998 * B = {F999, F1000}

A ^ 1
A ^ 2
A ^ 4
A ^ 8
A ^ 16
...

A ^ 6 = A ^ 4 * A ^ 2
*/