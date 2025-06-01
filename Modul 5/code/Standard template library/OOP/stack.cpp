#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

class StackManager {
private:
    stack<int> angka;
    stack<int> genap;
    stack<int> ganjil;

public:
    // Constructor
    StackManager() {
        // Constructor kosong, akan diinisialisasi melalui method
    }

    // Method untuk menampilkan informasi stack
    void displayStackInfo(const stack<int>& s, const string& name) {
        if (!s.empty()) {
            cout << "Elemen pertama stack \"" << name << "\": " << s.top() << "\n";
            cout << "Jumlah elemen pada stack \"" << name << "\": " << s.size() << "\n";
        } else {
            cout << "Stack \"" << name << "\" kosong.\n";
        }
    }

    // Method untuk demo inisialisasi stack angka
    void initializeAngkaStack() {
        for (int i = 0; i < 4; i++) {
            angka.push(i + 1);
        }
        
        cout << "Elemen pertama stack \"angka\": " << angka.top() << "\n";
        cout << "Jumlah elemen pada stack \"angka\": " << angka.size() << "\n";
    }

    // Method untuk mengecek apakah stack kosong
    void checkEmpty() {
        if (angka.empty()) {
            cout << "Stack \"angka\" kosong.\n";
        } else {
            cout << "Stack \"angka\" tidak kosong.\n";
        }
    }

    // Method untuk demo pop operation
    void demonstratePopOperation() {
        if (!angka.empty()) {
            angka.pop();
            cout << "Elemen pertama stack \"angka\" setelah pop: " << angka.top() << "\n";
        } else {
            cout << "Tidak dapat melakukan pop, stack \"angka\" kosong.\n";
        }
    }

    // Method untuk mengisi stack genap dan ganjil
    void fillGenapGanjilStacks() {
        // Mengisi stack genap
        for (int i = 0; i < 4; i++) {
            genap.push((i + 1) * 2);
        }

        // Mengisi stack ganjil
        for (int i = 0; i < 4; i++) {
            ganjil.push((i + 1) * 2 - 1);
        }
    }

    // Method untuk menampilkan top elements
    void displayTopElements() {
        if (!genap.empty()) {
            cout << "Elemen pertama stack \"genap\": " << genap.top() << "\n";
        }
        if (!ganjil.empty()) {
            cout << "Elemen pertama stack \"ganjil\": " << ganjil.top() << "\n";
        }
    }

    // Method untuk demo swap operation
    void demonstrateSwap() {
        genap.swap(ganjil);
        
        if (!genap.empty()) {
            cout << "Elemen pertama stack \"genap\" setelah swap: " << genap.top() << "\n";
        }
        if (!ganjil.empty()) {
            cout << "Elemen pertama stack \"ganjil\" setelah swap: " << ganjil.top() << "\n";
        }
    }

    // Method untuk menampilkan semua elemen (dengan cara destructive)
    void displayAllElements(stack<int> s, const string& name) {
        cout << "Semua elemen dalam stack \"" << name << "\" (LIFO order): ";
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
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
        initializeAngkaStack();
        checkEmpty();
        demonstratePopOperation();
        fillGenapGanjilStacks();
        displayTopElements();
        demonstrateSwap();
        demonstrateAllElements();
    }
};

int main() {
    StackManager manager;
    manager.runAllDemos();
    return 0;
}