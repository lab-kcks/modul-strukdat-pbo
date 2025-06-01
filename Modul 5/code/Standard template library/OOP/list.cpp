#include <iostream>
#include <list>
using namespace std;

class ListManager {
private:
    list<int> angka;
    list<int> genap;
    list<int> ganjil;
    list<int>::iterator it, it1, it2;

    // Helper function untuk predicate
    static bool is_small_num(const int& value) { 
        return value < 50; 
    }

public:
    // Constructor
    ListManager() {
        genap = {2, 4, 6, 8};
        ganjil = {1, 3, 5, 7};
    }

    // Method untuk menampilkan list
    void displayList(const list<int>& lst, const string& name) {
        cout << "Isi list \"" << name << "\":";
        for (auto i = lst.begin(); i != lst.end(); ++i) {
            cout << ' ' << *i;
        }
        cout << '\n';
    }

    // Method untuk demo push operations
    void demonstratePushOperations() {
        angka.push_front(4);
        angka.push_back(1);
        angka.push_front(2);
        angka.push_back(3);
        displayList(angka, "angka");
    }

    // Method untuk menampilkan informasi list
    void displayListInfo() {
        cout << "Jumlah elemen pada list \"angka\": " << angka.size() << "\n";
        cout << "Jumlah maksimal elemen yang dapat ditampung oleh list \"angka\": " << angka.max_size() << "\n";
    }

    // Method untuk mengecek apakah list kosong
    void checkEmpty() {
        if (angka.empty()) {
            cout << "List \"angka\" kosong.\n";
        } else {
            cout << "List \"angka\" tidak kosong.\n";
            cout << "Elemen pertama (front): " << angka.front() << '\n';
            cout << "Elemen terakhir (back): " << angka.back() << '\n';
        }
    }

    // Method untuk demo reverse
    void demonstrateReverse() {
        angka.reverse();
        displayList(angka, "angka setelah reverse");
    }

    // Method untuk demo sort
    void demonstrateSort() {
        angka.sort();
        displayList(angka, "angka setelah sort");
    }

    // Method untuk demo pop operations
    void demonstratePopOperations() {
        angka.pop_front();
        angka.pop_back();
        displayList(angka, "angka setelah pop (front dan back)");
    }

    // Method untuk demo resize
    void demonstrateResize() {
        angka.resize(5, 100);
        displayList(angka, "angka setelah resize");
    }

    // Method untuk demo assign
    void demonstrateAssign() {
        angka.assign(8, 10);
        displayList(angka, "angka setelah assign");
    }

    // Method untuk demo insert
    void demonstrateInsert() {
        it = angka.begin();
        ++it;
        
        // memasukkan nilai 20 di posisi ke-2
        angka.insert(it, 20);
        
        // memasukkan nilai 30 di posisi ke-3 sebanyak 3
        angka.insert(it, 3, 30);
        
        displayList(angka, "angka setelah insert");
    }

    // Method untuk demo erase
    void demonstrateErase() {
        it1 = angka.begin();
        ++it1;
        
        // menghapus elemen ke-2
        it1 = angka.erase(it1);
        
        it2 = angka.begin();
        advance(it2, 4);
        
        // menghapus elemen ke-2 hingga elemen ke-5
        angka.erase(it1, it2);
        
        displayList(angka, "angka setelah erase");
    }

    // Method untuk demo clear
    void demonstrateClear() {
        angka.clear();
        checkEmpty();
    }

    // Method untuk demo swap
    void demonstrateSwap() {
        displayList(genap, "genap");
        displayList(ganjil, "ganjil");
        
        genap.swap(ganjil);
        
        displayList(genap, "genap setelah swap");
        displayList(ganjil, "ganjil setelah swap");
    }

    // Method untuk demo splice
    void demonstrateSplice() {
        it = genap.begin();
        advance(it, 2);
        
        // memindahkan semua elemen ke list lain
        genap.splice(it, ganjil);
        displayList(genap, "genap setelah splice");
        displayList(ganjil, "ganjil setelah splice");
        
        // memindahkan satu elemen ke list lain
        ganjil.splice(ganjil.begin(), genap, it);
        displayList(genap, "genap setelah splice");
        displayList(ganjil, "ganjil setelah splice");
        
        it = genap.begin();
        advance(it, 3);
        
        // memindahkan beberapa elemen pada range tertentu ke list lain
        ganjil.splice(ganjil.begin(), genap, it, genap.end());
        displayList(genap, "genap setelah splice");
        displayList(ganjil, "ganjil setelah splice");
    }

    // Method untuk demo merge
    void demonstrateMerge() {
        // syarat sebelum melakukan merge adalah kedua list terurut
        genap.sort();
        ganjil.sort();
        
        genap.merge(ganjil);
        
        displayList(genap, "genap setelah merge");
        displayList(ganjil, "ganjil setelah merge");
    }

    // Method untuk demo remove operations
    void demonstrateRemoveOperations() {
        // Mengisi list dengan data untuk demo remove
        for (int i = 0; i < 10; i++) {
            angka.push_front((i + 1) * 10);
        }
        
        for (int i = 0; i < 10; i++) {
            angka.push_back((i + 1) * 10);
        }
        
        angka.sort();
        displayList(angka, "angka");
        
        angka.remove(10);
        displayList(angka, "angka setelah remove");
        
        angka.remove_if(is_small_num);
        displayList(angka, "angka setelah remove if");
        
        angka.unique();
        displayList(angka, "angka setelah unique");
    }

    // Method untuk menjalankan semua demo
    void runAllDemos() {
        demonstratePushOperations();
        displayListInfo();
        checkEmpty();
        demonstrateReverse();
        demonstrateSort();
        demonstratePopOperations();
        demonstrateResize();
        demonstrateAssign();
        demonstrateInsert();
        demonstrateErase();
        demonstrateClear();
        demonstrateSwap();
        demonstrateSplice();
        demonstrateMerge();
        demonstrateRemoveOperations();
    }
};

int main() {
    ListManager manager;
    manager.runAllDemos();
    return 0;
}