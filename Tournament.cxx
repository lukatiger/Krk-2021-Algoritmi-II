#include <bits/stdc++.h>
using namespace std;

struct Tournament {

    vector <int> data;
    int offset;


    Tournament(int _size) {
        for(offset = 1; offset < _size; offset *= 2);

        data.resize(offset * 2, 0);
    }

    void update(int index, int value) {
        int old_value = data[ index + offset ];
        int delta = value - old_value;
        for(int i = index + offset; i > 0; i /= 2) {
            data[ i ] += delta;
        }
    }

    int sum(int node, int lo, int hi, int qlo, int qhi) {
        if(hi <= qlo || lo >= qhi) return 0;
        if(lo >= qlo && hi <= qhi) return data[ node ];
        return sum(node * 2, lo, (lo + hi) / 2, qlo, qhi)
               + sum(node * 2 + 1, (lo + hi) / 2, hi, qlo, qhi);
    }

    int sum(int qlo, int qhi) {
        return sum(1, 0, offset, qlo, qhi);
    }

    void ispis_stabla() {
        for(int i = 0; i < offset * 2; i++) {
            cout << setfill(' ') << setw(2) << i;
            cout << " ";
        }
        cout << endl;
        for(int i = 0; i < offset * 2; i++) {
            cout << setfill(' ') << setw(2) << data[ i ];
            cout << " ";
        }
        cout << endl;
    }

};

int main() {    
    int n;
    cin >> n;
    vector <int> niz(n);
    Tournament T(n);
    for(int i = 0; i < n; i++) {
        cin >> niz[ i ];
        T.update(i, niz[ i ]);
    }

    int Q; 
    cin >> Q;

    for(int i = 0; i < Q; i++) {
        // T.ispis_stabla();
        string s;
        cin >> s;
        if(s == "s") { //sum
            int qlo, qhi;
            cin >> qlo >> qhi;
            cout << T.sum(qlo, qhi) << endl;
        }
        else if(s == "u") { //update
            int index, value;
            cin >> index >> value;
            T.update(index, value);
        }
    }    

    return 0;
}  