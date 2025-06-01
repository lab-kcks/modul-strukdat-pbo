#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

class QueueManager {
private:
    queue<int> angka;
    queue<int> genap;
    queue<int> ganjil;

public:
    // Constructor
    QueueManager() {
        // Constructor kosong, akan diinisialisasi melalui method
    }

    // Method untuk menampilkan informasi queue
    void displayQueueInfo(const queue<int>& q, const string& name) {
        if (!q.empty()) {
            cout << "Elemen pertama queue \"" << name << "\": " << q.front() << "\n";
            cout << "Elemen terakhir queue \"" << name << "\": " << q.back() << "\n";
            cout << "Jumlah elemen pada queue \"" << name << "\": " << q.size() << "\n";
        } else {
            cout << "Queue \"" << name << "\" kosong.\n";
        }
    }

    // Method untuk demo inisialisasi queue angka
    void initializeAngkaQueue() {
        for (int i = 0; i < 4; i++) {
            angka.push(i + 1);
        }
        displayQueueInfo(angka, "angka");
    }

    // Method untuk mengecek apakah queue kosong
    void checkEmpty() {
        if (angka.empty()) {
            cout << "Queue \"angka\" kosong.\n";
        } else {
            cout << "Queue \"angka\" tidak kosong.\n";
        }
    }

    // Method untuk demo pop operation
    void demonstratePopOperation() {
        if (!angka.empty()) {
            angka.pop();
            cout << "Setelah pop:\n";
            displayQueueInfo(angka, "angka");
        } else {
            cout << "Tidak dapat melakukan pop, queue \"angka\" kosong.\n";
        }
    }

    // Method untuk mengisi queue genap dan ganjil
    void fillGenapGanjilQueues() {
        // Mengisi queue genap
        for (int i = 0; i < 4; i++) {
            genap.push((i + 1) * 2);
        }

        // Mengisi queue ganjil
        for (int i = 0; i < 4; i++) {
            ganjil.push((i + 1) * 2 - 1);
        }
    }

    // Method untuk menampilkan front dan back elements
    void displayFrontBackElements() {
        if (!genap.empty()) {
            cout << "Elemen pertama queue \"genap\": " << genap.front() << "\n";
            cout << "Elemen terakhir queue \"genap\": " << genap.back() << "\n";
        }

        if (!ganjil.empty()) {
            cout << "Elemen pertama queue \"ganjil\": " << ganjil.front() << "\n";
            cout << "Elemen terakhir queue \"ganjil\": " << ganjil.back() << "\n";
        }
    }

    // Method untuk demo swap operation
    void demonstrateSwap() {
        genap.swap(ganjil);
        
        cout << "Setelah swap:\n";
        if (!genap.empty()) {
            cout << "Elemen pertama queue \"genap\" setelah swap: " << genap.front() << "\n";
            cout << "Elemen terakhir queue \"genap\" setelah swap: " << genap.back() << "\n";
        }

        if (!ganjil.empty()) {
            cout << "Elemen pertama queue \"ganjil\" setelah swap: " << ganjil.front() << "\n";
            cout << "Elemen terakhir queue \"ganjil\" setelah swap: " << ganjil.back() << "\n";
        }
    }

    // Method untuk menampilkan semua elemen (dengan cara destructive)
    void displayAllElements(queue<int> q, const string& name) {
        cout << "Semua elemen dalam queue \"" << name << "\" (FIFO order): ";
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << "\n";
    }

    // Method untuk demo menampilkan semua elemen
    void demonstrateAllElements() {
        displayAllElements(genap, "genap setelah swap");
        displayAllElements(ganjil, "ganjil setelah swap");
    }

    // Method untuk menjalankan semua demo
    void runAllDemos() {
        initializeAngkaQueue();
        checkEmpty();
        demonstratePopOperation();
        fillGenapGanjilQueues();
        displayFrontBackElements();
        demonstrateSwap();
        demonstrateAllElements();
    }
};

int main() {
    QueueManager manager;
    manager.runAllDemos();
    return 0;
}