/**
 * Implementasi ADT Dictionary (Key-Value Pair)
 *  
 * Dibuat dan ditulis oleh Steven Figo
 * -- tanggal 2 Maret 2025
 * Struktur Data & Pemorograman Berorientasi Objek 2025
 * Implementasi untuk bahasa C++
 * 
 */

#include<iostream>
#include<string>
using namespace std;

// Node dictionary
class Dictionary {
private:
    struct Node {
        string key;
        string value;
    };
    Node dict[100];
    int size;

public:
    Dictionary() {
        size = 0;
    }
    
    // Operasi dictionary
    void insert(string key, string value) {
            dict[size++] = {key, value};
            cout << "Data ditambahkan: " << key << " -> " << value << endl;
        }

    void update(string key, string newValue) {
        for (int i = 0; i < size; i++) {
            if (dict[i].key == key) {
                dict[i].value = newValue;
                cout << "Data diperbarui: " << key << " -> " << newValue << endl;
                return;
            }
        }
        cout << "Key tidak ditemukan" << endl;
    }

    void remove(string key) {
        for (int i = 0; i < size; i++) {
            if (dict[i].key == key) {
                dict[i] = dict[size - 1];
                size--;
                cout << "Data dengan key '" << key << "' berhasil dihapus." << endl;
                return;
            }
        }
        cout << "Key tidak ditemukan" << endl;
    }

    void search(string key) {
        for (int i = 0; i < size; i++) {
            if (dict[i].key == key) {
                cout << "Key: " << key << ", Value: " << dict[i].value << endl;
                return;
            }
        }
        cout << "Key tidak ditemukan" << endl;
    }
};


// Fungsi main
int main() {
    Dictionary dict;
    int choice;
    string key, value;

    while (true) {
        cout << "\nMenu:\n1. Insert\n2. Update\n3. Delete\n4. Search\n5. Exit\nPilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan Key: ";
                cin >> key;
                cout << "Masukkan Value: ";
                cin >> value;
                dict.insert(key, value);
                break;
            case 2:
                cout << "Masukkan Key: ";
                cin >> key;
                cout << "Masukkan Value Baru: ";
                cin >> value;
                dict.update(key, value);
                break;
            case 3:
                cout << "Masukkan Key: ";
                cin >> key;
                dict.remove(key);
                break;
            case 4:
                cout << "Masukkan Key: ";
                cin >> key;
                dict.search(key);
                break;
            case 5:
                return 0;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    }
}