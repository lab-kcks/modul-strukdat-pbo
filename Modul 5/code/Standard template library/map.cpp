#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    map<int,int> map_int_int; //key : integer, value integer;
    map<int,string> map_int_string; //key : integer, value string;
    map<string,int> map_string_int; //key : string, value integer;

    for (int i = 1 ; i <= 5 ; i++) {
        map_int_int[i] = i * 5; // (key,value) = (1,5) , (2,10) , (3,15) , (4,20) , (5,25)
    }

    map_int_string[1] = "satu";
    map_int_string[2] = "dua";
    map_int_string[3] = "tiga"; // (key,value) = (1,"satu") , (2,"dua") , (3,"tiga")

    for (map<int,string>::iterator it = map_int_string.begin() ; it != map_int_string.end() ; ++it) { // mengiterasi semua isi dari map_int_string
        pair<int,string> cur = *it;
        map_string_int[cur.second] = cur.first; //(key,value) = ("satu",1) , ("dua",2) , ("tiga",3)
    }    

    cout << "ukuran map_int_string : " << map_int_string.size() << endl;
    map_int_string.clear();
    cout << "ukuran map_int_string setelah diclear : " << map_int_string.size() << endl;

    for (int i = 1 ; i <= 7 ; i++) {
        if (map_int_int.count(i)) {
            cout << "elemen dengan key " << i << " ada di dalam map" << endl;
        } else {
            cout << "elemen dengan key " << i << " tidak ada di dalam map" << endl; 
        }
    }

    cout << "Apakah map_int_int kosong? " << (map_int_int.empty() ? "Ya" : "Tidak") << endl;

    cout << "max_size map_int_int: " << map_int_int.max_size() << endl;

    map_int_int.insert(make_pair(10, 100));
    map_int_int.insert({20, 200});
    cout << "Setelah insert, map_int_int[10] = " << map_int_int[10] << ", map_int_int[20] = " << map_int_int[20] << endl;

    map_int_int.erase(2);
    cout << "Setelah erase key 2, map_int_int.count(2) = " << map_int_int.count(2) << endl;

    if (!map_int_int.empty()) {
        auto it = map_int_int.begin();
        cout << "Menghapus elemen pertama: (" << it->first << "," << it->second << ")\n";
        map_int_int.erase(it);
    }

    if (map_int_int.size() > 2) {
        auto it1 = map_int_int.begin();
        auto it2 = it1;
        advance(it2, 2);
        map_int_int.erase(it1, it2);
        cout << "Setelah erase range, ukuran map_int_int: " << map_int_int.size() << endl;
    }

    map<int,int> map_lain;
    map_lain[100] = 1000;
    map_lain[200] = 2000;
    map_int_int.swap(map_lain);
    cout << "Setelah swap, isi map_int_int:\n";
    for (auto &p : map_int_int) {
        cout << p.first << " : " << p.second << endl;
    }

    auto it_find = map_int_int.find(100);
    if (it_find != map_int_int.end()) {
        cout << "Ditemukan key 100 dengan value " << it_find->second << endl;
    } else {
        cout << "Key 100 tidak ditemukan\n";
    }

    return 0;
}