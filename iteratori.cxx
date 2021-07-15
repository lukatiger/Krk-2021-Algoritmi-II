#include <bits/stdc++.h>
using namespace std;

int main() {

    // STL = Standard Template Library
    // unutra se nalaze vector, set, list, queue, itd.


    //// vector 

    vector <int> v = {4, 2, 7, 1, 8};

    for(int i = 0; i < v.size(); i++) {
        cout << v[ i ] << " ";
    }
    cout << endl;

    for(int cur: v) { // for(auto cur: v)
        cout << cur << " ";
    }
    cout << endl;

    /* 
    4  2  7  1  8  X
    |              |
    v.begin()      v.end()
    */
    vector <int> :: iterator iter; //iter je ime varijable, vector<int>::iterator je tip podatka
    for(iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    /// set

    set <int> S = {4, 2, 5, 7, 9}; 
    /* 
    2  4  5  7  9  X
    |  
    S.begin()

    2  4  5  7  9  X
                   |  
                   S.end()

    2  4  5  7  9  X
       |  
       S.lower_bound(4) -> prvi element koji je veci ili jednak 4

    2  4  5  7  9  X
          |  
          S.upper_bound(4) -> prvi element koji je strogo veci od 4


    */

    set <int> :: iterator set_iter;
    for(set_iter = S.begin(); set_iter != S.end(); set_iter++) {
        cout << *set_iter << " ";
    }
    cout << endl;

    cout << *S.lower_bound(4) << " " << *S.upper_bound(4) << endl;
    if(S.upper_bound(9) == S.end()) {
        cout << "kraj seta" << endl;
    }
    else {
        cout << "nije kraj seta" << endl;
    }

    return 0;
}