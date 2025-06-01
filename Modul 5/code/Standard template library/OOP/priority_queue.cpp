#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

class PriorityQueueManager {
private:
    priority_queue<int> angka;
    priority_queue<int> genap;
    priority_queue<int> ganjil;

public:
    // Constructor
    PriorityQueueManager() {
        // Constructor kosong, akan diinisialisasi melalui method
    }

    // Method untuk menampilkan informasi priority queue
    void displayInfo(const priority_queue<int>& pq, const string& name) {
        if (!pq.empty()) {
            cout << "Elemen pertama priority queue \"" << name << "\": " << pq.top() << "\n";
            cout << "Jumlah elemen pada priority queue \"" << name << "\": " << pq.size() << "\n";
        } else {
            cout << "Priority queue \"" << name << "\" kosong.\n";
        }
    }

    // Method untuk demo push operations
    void demonstratePushOperations() {
        angka.push(2);
        angka.push(4);
        angka.push(1);
        angka.push(3);
        
        displayInfo(angka, "angka");
    }

    // Method untuk mengecek apakah priority queue kosong
    void checkEmpty() {
        if (angka.empty()) {
            cout << "Priority queue \"angka\" kosong.\n";
        } else {
            cout << "Priority queue \"angka\" tidak kosong.\n";
        }
    }

    // Method untuk demo pop operation
    void demonstratePopOperation() {
        if (!angka.empty()) {
            angka.pop();
            cout << "Elemen pertama priority queue \"angka\" setelah pop: " << angka.top() << "\n";
        } else {
            cout << "Tidak dapat melakukan pop, priority queue \"angka\" kosong.\n";
        }
    }

    // Method untuk mengisi priority queue genap dan ganjil
    void fillQueues() {
        // Mengisi genap
        genap.push(4);
        genap.push(8);
        genap.push(2);
        genap.push(6);

        // Mengisi ganjil
        ganjil.push(3);
        ganjil.push(7);
        ganjil.push(1);
        ganjil.push(5);
    }

    // Method untuk menampilkan top elements
    void displayTopElements() {
        if (!genap.empty()) {
            cout << "Elemen pertama priority queue \"genap\": " << genap.top() << "\n";
        }
        if (!ganjil.empty()) {
            cout << "Elemen pertama priority queue \"ganjil\": " << ganjil.top() << "\n";
        }
    }

    // Method untuk demo swap operation
    void demonstrateSwap() {
        genap.swap(ganjil);
        
        cout << "Setelah swap:\n";
        if (!genap.empty()) {
            cout << "Elemen pertama priority queue \"genap\" setelah swap: " << genap.top() << "\n";
        }
        if (!ganjil.empty()) {
            cout << "Elemen pertama priority queue \"ganjil\" setelah swap: " << ganjil.top() << "\n";
        }
    }

    // Method untuk menampilkan semua elemen (dengan cara destructive)
    void displayAllElements(priority_queue<int> pq, const string& name) {
        cout << "Semua elemen dalam priority queue \"" << name << "\" (urutan priority): ";
        while (!pq.empty()) {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << "\n";
    }

    // Method untuk demo semua elemen
    void demonstrateAllElements() {
        // Menampilkan semua elemen sebelum swap
        displayAllElements(genap, "genap setelah swap");
        displayAllElements(ganjil, "ganjil setelah swap");
    }

    // Method untuk menjalankan semua demo
    void runAllDemos() {
        demonstratePushOperations();
        checkEmpty();
        demonstratePopOperation();
        fillQueues();
        displayTopElements();
        demonstrateSwap();
        demonstrateAllElements();
    }
};

int main() {
    PriorityQueueManager manager;
    manager.runAllDemos();
    return 0;
}