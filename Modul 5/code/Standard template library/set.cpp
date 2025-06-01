#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
   set<int> mySet;
    for (int i = 1 ; i <= 10 ; i++) {
        for (int j = 1 ; j <= 10 ; j++) {
            mySet.insert(i);
        }
    }

    cout << "ukuran set sekarang : " << mySet.size() << endl;
    cout << "elemen - elemen di dalam set : ";
    for (set<int>::iterator it = mySet.begin() ; it != mySet.end() ; ++it) {
        cout << *it << " "; //coba tebak kenapa harus pakai asterisk?
    }
    cout << endl;

    for (int i = 7 ; i <= 12 ; i++) {
        if (mySet.count(i)) {
            cout << i << " ada di dalam set" << endl;
        } else {
            cout << i << " tidak ada di dalam set" << endl;
        }
    }

    set<int>::iterator lo,hi;
    mySet.erase(5);                 //1 2 3 4 6 7 8 9 10
    lo = mySet.lower_bound(4);      //      ^
    hi = mySet.upper_bound(4);      //        ^
    
    cout << "Kapasitas maksimum set: " << mySet.max_size() << endl;
    
    cout << "Set kosong? " << (mySet.empty() ? "Ya" : "Tidak") << endl;
    
    set<int>::iterator findResult = mySet.find(8);
    if (findResult != mySet.end()) {
        cout << "Elemen 8 ditemukan: " << *findResult << endl;
    }
    
    set<int> otherSet;
    otherSet.insert(100);
    otherSet.insert(200);
    cout << "Sebelum swap - mySet size: " << mySet.size() << endl;
    mySet.swap(otherSet);
    cout << "Setelah swap - mySet size: " << mySet.size() << endl;
    
    mySet.clear();
    cout << "Setelah clear - ukuran set: " << mySet.size() << endl;
    cout << "Set kosong setelah clear? " << (mySet.empty() ? "Ya" : "Tidak") << endl;

    return 0;
}