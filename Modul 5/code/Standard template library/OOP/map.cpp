#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

class MapManager {
private:
    map<int, int> map_int_int;
    map<int, string> map_int_string;
    map<string, int> map_string_int;

public:
    // Constructor
    MapManager() {
        initializeMaps();
    }

    // Method untuk menginisialisasi maps
    void initializeMaps() {
        // Inisialisasi map_int_int
        for (int i = 1; i <= 5; i++) {
            map_int_int[i] = i * 5; // (key,value) = (1,5), (2,10), (3,15), (4,20), (5,25)
        }

        // Inisialisasi map_int_string
        map_int_string[1] = "satu";
        map_int_string[2] = "dua";
        map_int_string[3] = "tiga"; // (key,value) = (1,"satu"), (2,"dua"), (3,"tiga")

        // Inisialisasi map_string_int berdasarkan map_int_string
        for (map<int, string>::iterator it = map_int_string.begin(); it != map_int_string.end(); ++it) {
            pair<int, string> cur = *it;
            map_string_int[cur.second] = cur.first; //(key,value) = ("satu",1), ("dua",2), ("tiga",3)
        }
    }

    // Method untuk demo size dan clear
    void demonstrateSizeAndClear() {
        cout << "ukuran map_int_string : " << map_int_string.size() << endl;
        map_int_string.clear();
        cout << "ukuran map_int_string setelah diclear : " << map_int_string.size() << endl;
    }

    // Method untuk demo count
    void demonstrateCount() {
        for (int i = 1; i <= 7; i++) {
            if (map_int_int.count(i)) {
                cout << "elemen dengan key " << i << " ada di dalam map" << endl;
            } else {
                cout << "elemen dengan key " << i << " tidak ada di dalam map" << endl;
            }
        }
    }

    // Method untuk demo empty dan max_size
    void demonstrateEmptyAndMaxSize() {
        cout << "Apakah map_int_int kosong? " << (map_int_int.empty() ? "Ya" : "Tidak") << endl;
        cout << "max_size map_int_int: " << map_int_int.max_size() << endl;
    }

    // Method untuk demo insert
    void demonstrateInsert() {
        map_int_int.insert(make_pair(10, 100));
        map_int_int.insert({20, 200});
        cout << "Setelah insert, map_int_int[10] = " << map_int_int[10] 
             << ", map_int_int[20] = " << map_int_int[20] << endl;
    }

    // Method untuk demo erase
    void demonstrateErase() {
        // Erase by key
        map_int_int.erase(2);
        cout << "Setelah erase key 2, map_int_int.count(2) = " << map_int_int.count(2) << endl;

        // Erase by iterator
        if (!map_int_int.empty()) {
            auto it = map_int_int.begin();
            cout << "Menghapus elemen pertama: (" << it->first << "," << it->second << ")\n";
            map_int_int.erase(it);
        }

        // Erase by range
        if (map_int_int.size() > 2) {
            auto it1 = map_int_int.begin();
            auto it2 = it1;
            advance(it2, 2);
            map_int_int.erase(it1, it2);
            cout << "Setelah erase range, ukuran map_int_int: " << map_int_int.size() << endl;
        }
    }

    // Method untuk demo swap
    void demonstrateSwap() {
        map<int, int> map_lain;
        map_lain[100] = 1000;
        map_lain[200] = 2000;
        map_int_int.swap(map_lain);
        cout << "Setelah swap, isi map_int_int:\n";
        for (auto &p : map_int_int) {
            cout << p.first << " : " << p.second << endl;
        }
    }

    // Method untuk demo find
    void demonstrateFind() {
        auto it_find = map_int_int.find(100);
        if (it_find != map_int_int.end()) {
            cout << "Ditemukan key 100 dengan value " << it_find->second << endl;
        } else {
            cout << "Key 100 tidak ditemukan\n";
        }
    }

    // Method untuk menampilkan isi map
    void displayMap(const map<int, int>& m, const string& name) {
        cout << "Isi " << name << ":\n";
        for (const auto& pair : m) {
            cout << pair.first << " : " << pair.second << endl;
        }
    }

    void displayMap(const map<int, string>& m, const string& name) {
        cout << "Isi " << name << ":\n";
        for (const auto& pair : m) {
            cout << pair.first << " : " << pair.second << endl;
        }
    }

    void displayMap(const map<string, int>& m, const string& name) {
        cout << "Isi " << name << ":\n";
        for (const auto& pair : m) {
            cout << pair.first << " : " << pair.second << endl;
        }
    }

    // Method untuk menjalankan semua demo
    void runAllDemos() {
        demonstrateSizeAndClear();
        demonstrateCount();
        demonstrateEmptyAndMaxSize();
        demonstrateInsert();
        demonstrateErase();
        demonstrateSwap();
        demonstrateFind();
    }
};

int main() {
    MapManager manager;
    manager.runAllDemos();
    return 0;
}