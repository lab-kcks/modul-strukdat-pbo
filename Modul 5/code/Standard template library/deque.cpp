#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    deque<int> angka;
    deque<int> genap = {2, 4, 6, 8};
    deque<int> ganjil = {1, 3, 5, 7};

    angka.push_front(2);
    angka.push_back(3);
    angka.push_front(1);
    angka.push_back(4);

    cout << "Isi deque \"angka\":";
    for (auto i = angka.begin(); i != angka.end(); ++i) {
        cout << ' ' << *i;
    }
    cout << '\n';

    cout << "front(): " << angka.front()
         << ", back(): "  << angka.back() << '\n';
    cout << "operator[] index 1: " << angka[1] << '\n';   // undefined behavior jika di luar range
    cout << "at()    index 2: " << angka.at(2) << '\n';   // throws out_of_range jika di luar range

    cout << "Jumlah elemen pada deque \"angka\": " << angka.size() << "\n";
    cout << "Jumlah maksimal elemen yang dapat ditampung oleh deque \"angka\": " << angka.max_size() << "\n";

    if (angka.empty()) {
        cout << "Deque \"angka\" kosong.\n";
    } else {
        cout << "Deque \"angka\" tidak kosong.\n";
    }

    angka.pop_front();
    angka.pop_back();

    cout << "Isi list \"angka\" setelah pop (front dan back):";
    for (auto i = angka.begin(); i != angka.end(); ++i) {
        cout << ' ' << *i;
    }
    cout << '\n';

    angka.resize(5, 100);

    cout << "Isi deque \"angka\" setelah resize:";
    for (auto i = angka.begin(); i != angka.end(); ++i) {
        cout << ' ' << *i;
    }
    cout << '\n';

    angka.assign(8, 10);

    cout << "Isi deque \"angka\" setelah assign:";
    for (auto i = angka.begin(); i != angka.end(); ++i) {
        cout << ' ' << *i;
    }
    cout << '\n';

    // memasukkan nilai 20 di posisi ke-2
    angka.insert(angka.begin() + 1, 20);

    // memasukkan nilai 30 di posisi ke-3 sebanyak 3
    angka.insert(angka.begin() + 2, 3, 30);

    cout << "Isi deque \"angka\" setelah insert:";
    for (auto i = angka.begin(); i != angka.end(); ++i) {
        cout << ' ' << *i;
    }
    cout << '\n';

    // menghapus elemen ke-2
    angka.erase(angka.begin() + 1);

    // menghapus elemen ke-2 hingga elemen ke-5
    angka.erase(angka.begin() + 1, angka.begin() + 4);

    cout << "Isi deque \"angka\" setelah erase:";
    for (auto i = angka.begin(); i != angka.end(); ++i) {
        cout << ' ' << *i;
    }
    cout << '\n';

    angka.clear();

    if (angka.empty()) {
        cout << "Deque \"angka\" kosong.\n";
    } else {
        cout << "Deque \"angka\" tidak kosong.\n";
    }

    cout << "Isi deque \"genap\":";
    for (auto i = genap.begin(); i != genap.end(); ++i) {
        cout << ' ' << *i;
    }
    cout << '\n';

    cout << "Isi deque \"ganjil\":";
    for (auto i = ganjil.begin(); i != ganjil.end(); ++i) {
        cout << ' ' << *i;
    }
    cout << '\n';
    
    // iterasi terbalik
    cout << "Reverse deque \"ganjil\":";
    for (auto it = ganjil.rbegin(); it != ganjil.rend(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    genap.swap(ganjil);
    // atau
    // ganjil.swap(genap);

    cout << "Isi deque \"genap\" setelah swap:";
    for (int i = 0; i < 4; i++) {
        cout << ' ' << genap.at(i);
    }
    cout << '\n';

    cout << "Isi deque \"ganjil\" setelah swap:";
    for (int i = 0; i < 4; i++) {
        cout << ' ' << ganjil.at(i);
    }
    cout << '\n';


    return 0;
}