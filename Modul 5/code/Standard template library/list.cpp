#include <iostream>
#include <list>
#include <iterator>
using namespace std;

class ListDemo {
private:
    list<int> myList;

public:
    // Constructor dengan nilai awal
    ListDemo() {
        myList.push_back(10);
        myList.push_back(20);
    }

    // Menampilkan isi list
    void display() {
        cout << "Isi list: ";
        for(auto elem : myList) {
            cout << elem << " ";
        }
        cout << endl << endl;
    }

    // Menambahkan elemen di depan
    void tambahDepan(int nilai) {
        myList.push_front(nilai);
        cout << "Menambahkan " << nilai << " di depan" << endl;
    }

    // Menambahkan elemen di belakang
    void tambahBelakang(int nilai) {
        myList.push_back(nilai);
        cout << "Menambahkan " << nilai << " di belakang" << endl;
    }

    // Menyisipkan elemen di posisi tertentu
    void sisipkan(int posisi, int nilai) {
        auto iterator = myList.begin();
        advance(iterator, posisi);
        myList.insert(iterator, nilai);
        cout << "Menyisipkan " << nilai << " di posisi " << posisi << endl;
    }

    // Menghapus elemen tertentu
    void hapus(int nilai) {
        myList.remove(nilai);
        cout << "Menghapus semua elemen " << nilai << endl;
    }

    // Mengurutkan list
    void urutkan() {
        myList.sort();
        cout << "Mengurutkan list" << endl;
    }

    // Membalikkan list
    void balikkan() {
        myList.reverse();
        cout << "Membalikkan list" << endl;
    }

    // Menggabungkan dua list
    void gabungkan(ListDemo &lain) {
        myList.merge(lain.myList);
        cout << "Menggabungkan dengan list lain" << endl;
    }

    // Menghapus duplikat
    void hapusDuplikat() {
        myList.unique();
        cout << "Menghapus duplikat berurutan" << endl;
    }
};

int main() {
    // Membuat objek pertama
    ListDemo demo;
    cout << "=== List Pertama ===" << endl;
    demo.display();

    // Operasi pada list pertama
    demo.tambahDepan(5);
    demo.tambahBelakang(30);
    demo.sisipkan(2, 15);
    demo.display();

    demo.hapus(20);
    demo.display();

    demo.urutkan();
    demo.display();

    demo.balikkan();
    demo.display();

    // Membuat list kedua
    ListDemo demo2;
    demo2.tambahBelakang(25);
    demo2.tambahBelakang(3);
    demo2.tambahBelakang(17);
    demo2.tambahBelakang(3);
    
    cout << "=== List Kedua ===" << endl;
    demo2.display();
    
    demo2.urutkan();
    cout << "Setelah diurutkan:" << endl;
    demo2.display();

    // Menggabungkan dua list
    demo.gabungkan(demo2);
    cout << "Hasil gabungan:" << endl;
    demo.display();

    // Menambahkan duplikat
    demo.tambahBelakang(30);
    demo.tambahBelakang(30);
    cout << "Setelah menambahkan duplikat:" << endl;
    demo.display();

    demo.hapusDuplikat();
    cout << "Setelah menghapus duplikat:" << endl;
    demo.display();

    return 0;
}