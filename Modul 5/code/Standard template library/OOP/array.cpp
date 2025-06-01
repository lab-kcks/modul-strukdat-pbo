#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

class ArrayManager {
private:
    array<int, 4> angka;
    array<int, 4> ganjil;
    array<int, 4> genap;
    array<int, 4> kosong;

public:
    // Constructor
    ArrayManager() {
        angka = {1, 2, 3, 4};
        ganjil = {1, 3, 5, 7};
        genap = {2, 4, 6, 8};
        // kosong array akan otomatis diinisialisasi dengan 0
    }

    // Method untuk menampilkan array
    void displayArray(const array<int, 4>& arr, const string& name) {
        cout << "Isi array '" << name << "':";
        for (int i = 0; i < 4; i++) {
            cout << ' ' << arr[i];
        }
        cout << "\n";
    }

    // Method untuk demo akses elemen
    void demonstrateElementAccess() {
        displayArray(angka, "angka");
        
        cout << "Elemen ke-3 (operator[]): " << angka[2] << endl;
        cout << "Elemen ke-3 (at()): " << angka.at(2) << endl;
        cout << "Elemen pertama: " << angka.front() << endl;
        cout << "Elemen terakhir: " << angka.back() << endl;
    }

    // Method untuk memodifikasi elemen
    void modifyElements() {
        angka.front() = 50;
        angka.at(2) = 100;
        angka.back() = 150;

        cout << "Isi array 'angka' sekarang:";
        for (auto i = angka.begin(); i != angka.end(); ++i) {
            cout << ' ' << *i;
        }
        cout << "\n";
    }

    // Method untuk menampilkan informasi array
    void displayArrayInfo() {
        cout << "Jumlah elemen pada array 'angka': " << angka.size() << "\n";
        cout << "Jumlah maksimal elemen yang dapat ditampung oleh array 'angka': " << angka.max_size() << "\n";
    }

    // Method untuk mengecek apakah array kosong
    void checkEmpty() {
        if (angka.empty()) {
            cout << "Array 'angka' kosong.\n";
        } else {
            cout << "Array 'angka' tidak kosong.\n";
        }
        if (kosong.empty()) {
            cout << "Array 'kosong' kosong.\n";
        } else {
            cout << "Array 'kosong' tidak kosong.\n";
        }
    }

    // Method untuk demo swap
    void demonstrateSwap() {
        displayArray(ganjil, "ganjil");
        displayArray(genap, "genap");

        // Menukar nilai (swap)
        ganjil.swap(genap);

        cout << "Isi array 'ganjil' setelah swap:";
        for (int i = 0; i < 4; i++) {
            cout << ' ' << ganjil.at(i);
        }
        cout << '\n';

        cout << "Isi array 'genap' setelah swap:";
        for (int i = 0; i < 4; i++) {
            cout << ' ' << genap.at(i);
        }
        cout << '\n';
    }

    // Method untuk reverse iteration
    void demonstrateReverse() {
        cout << "Reverse isi 'angka':";
        for (auto it = angka.rbegin(); it != angka.rend(); ++it) {
            cout << ' ' << *it;
        }
        cout << "\n";
    }

    // Method untuk structured binding
    void demonstrateStructuredBinding() {
        auto [a, b, c, d] = angka;
        cout << "Structured binding: " << a << ',' << b << ',' << c << ',' << d << "\n";
    }

    // Method untuk comparison operators
    void demonstrateComparison() {
        if (ganjil == genap) 
            cout << "ganjil == genap\n";
        else if (ganjil < genap)
            cout << "ganjil < genap\n";
        else
            cout << "ganjil > genap\n";
    }

    // Method untuk fill operation
    void demonstrateFill() {
        angka.fill(200);
        kosong.fill(20);

        cout << "Isi array 'angka' setelah fill:";
        for (int i = 0; i < 4; i++) {
            cout << ' ' << angka.at(i);
        }
        cout << '\n';

        cout << "Isi array 'kosong' setelah fill:";
        for (auto i = kosong.begin(); i != kosong.end(); i++) {
            cout << ' ' << *i;
        }
        cout << '\n';
    }

    // Method untuk menjalankan semua demo
    void runAllDemos() {
        demonstrateElementAccess();
        modifyElements();
        displayArrayInfo();
        checkEmpty();
        demonstrateSwap();
        demonstrateReverse();
        demonstrateStructuredBinding();
        demonstrateComparison();
        demonstrateFill();
    }
};

int main() {
    ArrayManager manager;
    manager.runAllDemos();
    return 0;
}