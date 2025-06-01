#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class SetManager {
private:
    set<int> mySet;

public:
    // Constructor
    SetManager() {}
    
    // Method untuk mengisi set dengan data
    void populateSet() {
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                mySet.insert(i);
            }
        }
    }
    
    // Method untuk menampilkan informasi ukuran dan elemen
    void displaySetInfo() {
        cout << "ukuran set sekarang : " << mySet.size() << endl;
        cout << "elemen - elemen di dalam set : ";
        for (set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
    
    // Method untuk mengecek keberadaan elemen dalam range
    void checkElementsInRange(int start, int end) {
        for (int i = start; i <= end; i++) {
            if (mySet.count(i)) {
                cout << i << " ada di dalam set" << endl;
            } else {
                cout << i << " tidak ada di dalam set" << endl;
            }
        }
    }
    
    // Method untuk operasi erase dan bound
    void demonstrateBounds() {
        mySet.erase(5);
        set<int>::iterator lo = mySet.lower_bound(4);
        set<int>::iterator hi = mySet.upper_bound(4);
        
        cout << "Setelah menghapus elemen 5" << endl;
        cout << "Lower bound dari 4: " << *lo << endl;
        cout << "Upper bound dari 4: " << *hi << endl;
    }
    
    // Method untuk menampilkan kapasitas maksimum
    void showMaxSize() {
        cout << "Kapasitas maksimum set: " << mySet.max_size() << endl;
    }
    
    // Method untuk mengecek apakah set kosong
    void checkIfEmpty() {
        cout << "Set kosong? " << (mySet.empty() ? "Ya" : "Tidak") << endl;
    }
    
    // Method untuk mencari elemen
    void findElement(int value) {
        set<int>::iterator findResult = mySet.find(value);
        if (findResult != mySet.end()) {
            cout << "Elemen " << value << " ditemukan: " << *findResult << endl;
        } else {
            cout << "Elemen " << value << " tidak ditemukan" << endl;
        }
    }
    
    // Method untuk operasi swap
    void demonstrateSwap() {
        set<int> otherSet;
        otherSet.insert(100);
        otherSet.insert(200);
        
        cout << "Sebelum swap - mySet size: " << mySet.size() << endl;
        mySet.swap(otherSet);
        cout << "Setelah swap - mySet size: " << mySet.size() << endl;
    }
    
    // Method untuk membersihkan set
    void clearSet() {
        mySet.clear();
        cout << "Setelah clear - ukuran set: " << mySet.size() << endl;
        cout << "Set kosong setelah clear? " << (mySet.empty() ? "Ya" : "Tidak") << endl;
    }
    
    // Method untuk mendapatkan ukuran set
    int getSize() {
        return mySet.size();
    }
};

int main() {
    // Membuat objek SetManager
    SetManager setMgr;
    
    // Mengisi set dengan data
    setMgr.populateSet();
    
    // Menampilkan informasi set
    setMgr.displaySetInfo();
    
    // Mengecek elemen dalam range 7-12
    setMgr.checkElementsInRange(7, 12);
    
    // Demonstrasi bounds
    setMgr.demonstrateBounds();
    
    // Menampilkan kapasitas maksimum
    setMgr.showMaxSize();
    
    // Mengecek apakah kosong
    setMgr.checkIfEmpty();
    
    // Mencari elemen
    setMgr.findElement(8);
    
    // Demonstrasi swap
    setMgr.demonstrateSwap();
    
    // Membersihkan set
    setMgr.clearSet();

    return 0;
}