/**
 * Implementasi ADT Dictionary (Key-Value Pair)
 *  
 * Dibuat dan ditulis oleh Steven Figo
 * -- tanggal 2 Maret 2025
 * Struktur Data 2025
 * Implementasi untuk bahasa C++
 * 
 */

#include<iostream>
#include<string>
using namespace std;

// Node dictionary
struct Dictionary {
    string key;
    string value;
};

// Operasi dictionary
void insert(Dictionary dict[], int &size, string key, string value) {
    dict[size++] = {key, value};
}

void update(Dictionary dict[], int size, string key, string newValue) {
    for (int i = 0; i < size; i++) {
        if (dict[i].key == key) {
            dict[i].value = newValue;
            return;
        }
    }
    cout << "Key tidak ditemukan" << endl;
}

void remove(Dictionary dict[], int &size, string key) {
    for (int i = 0; i < size; i++) {
        if (dict[i].key == key) {
            dict[i] = dict[size-1];
            size--;
            return;
        }
    }
    cout << "Key tidak ditemukan" << endl;
}

void search(Dictionary dict[], int size, string key) {
    for (int i = 0; i < size; i++) {
        if (dict[i].key == key) {
            cout << "Key: " << dict[i].key << ", Value: " << dict[i].value << endl;
            return;
        }
    }
    cout << "Key tidak ditemukan" << endl;
}

// Fungsi main
int main() {
    // Deklarasi
    Dictionary dict[100];
    int size = 0, choice;
    string key, value;

    // Menu
    while (true) {
        cout << "\nMenu:\n1. Insert\n2. Update\n3. Delete\n4. Search\n5. Exit\nPilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan Key: ";
                cin >> key;
                cout << "Masukkan Value: ";
                cin >> value;
                insert(dict, size, key, value);
                break;
            case 2:
                cout << "Masukkan Key: ";
                cin >> key;
                cout << "Masukkan Value Baru: ";
                cin >> value;
                update(dict, size, key, value);
                break;
            case 3:
                cout << "Masukkan Key: ";
                cin >> key;
                remove(dict, size, key);
                break;
            case 4:
                cout << "Masukkan Key: ";
                cin >> key;
                search(dict, size, key);
                break;
            case 5:
                return 0;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    }
}