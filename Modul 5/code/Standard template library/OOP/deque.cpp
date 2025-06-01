#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

class DequeManager {
private:
    deque<int> angka;
    deque<int> genap;
    deque<int> ganjil;

public:
    // Constructor
    DequeManager() {
        genap = {2, 4, 6, 8};
        ganjil = {1, 3, 5, 7};
    }

    // Method untuk menampilkan deque
    void displayDeque(const deque<int>& dq, const string& name) {
        cout << "Isi deque \"" << name << "\":";
        for (auto i = dq.begin(); i != dq.end(); ++i) {
            cout << ' ' << *i;
        }
        cout << '\n';
    }

    // Method untuk demo push operations
    void demonstratePushOperations() {
        angka.push_front(2);
        angka.push_back(3);
        angka.push_front(1);
        angka.push_back(4);
        displayDeque(angka, "angka");
    }

    // Method untuk demo akses elemen
    void demonstrateElementAccess() {
        cout << "front(): " << angka.front()
             << ", back(): "  << angka.back() << '\n';
        cout << "operator[] index 1: " << angka[1] << '\n';
        cout << "at()    index 2: " << angka.at(2) << '\n';
    }

    // Method untuk menampilkan informasi deque
    void displayDequeInfo() {
        cout << "Jumlah elemen pada deque \"angka\": " << angka.size() << "\n";
        cout << "Jumlah maksimal elemen yang dapat ditampung oleh deque \"angka\": " << angka.max_size() << "\n";
    }

    // Method untuk mengecek apakah deque kosong
    void checkEmpty() {
        if (angka.empty()) {
            cout << "Deque \"angka\" kosong.\n";
        } else {
            cout << "Deque \"angka\" tidak kosong.\n";
        }
    }

    // Method untuk demo pop operations
    void demonstratePopOperations() {
        angka.pop_front();
        angka.pop_back();
        
        cout << "Isi deque \"angka\" setelah pop (front dan back):";
        for (auto i = angka.begin(); i != angka.end(); ++i) {
            cout << ' ' << *i;
        }
        cout << '\n';
    }

    // Method untuk demo resize
    void demonstrateResize() {
        angka.resize(5, 100);
        displayDeque(angka, "angka setelah resize");
    }

    // Method untuk demo assign
    void demonstrateAssign() {
        angka.assign(8, 10);
        displayDeque(angka, "angka setelah assign");
    }

    // Method untuk demo insert
    void demonstrateInsert() {
        // memasukkan nilai 20 di posisi ke-2
        angka.insert(angka.begin() + 1, 20);

        // memasukkan nilai 30 di posisi ke-3 sebanyak 3
        angka.insert(angka.begin() + 2, 3, 30);

        displayDeque(angka, "angka setelah insert");
    }

    // Method untuk demo erase
    void demonstrateErase() {
        // menghapus elemen ke-2
        angka.erase(angka.begin() + 1);

        // menghapus elemen ke-2 hingga elemen ke-5
        angka.erase(angka.begin() + 1, angka.begin() + 4);

        displayDeque(angka, "angka setelah erase");
    }

    // Method untuk demo clear
    void demonstrateClear() {
        angka.clear();
        checkEmpty();
    }

    // Method untuk demo reverse iteration
    void demonstrateReverse() {
        displayDeque(genap, "genap");
        displayDeque(ganjil, "ganjil");
        
        // iterasi terbalik
        cout << "Reverse deque \"ganjil\":";
        for (auto it = ganjil.rbegin(); it != ganjil.rend(); ++it)
            cout << ' ' << *it;
        cout << '\n';
    }

    // Method untuk demo swap
    void demonstrateSwap() {
        genap.swap(ganjil);

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
    }

    // Method untuk menjalankan semua demo
    void runAllDemos() {
        demonstratePushOperations();
        demonstrateElementAccess();
        displayDequeInfo();
        checkEmpty();
        demonstratePopOperations();
        demonstrateResize();
        demonstrateAssign();
        demonstrateInsert();
        demonstrateErase();
        demonstrateClear();
        demonstrateReverse();
        demonstrateSwap();
    }
};

int main() {
    DequeManager manager;
    manager.runAllDemos();
    return 0;
}