# Constructor in C++
Constructor adalah metode khusus dalam sebuah kelas yang dipanggil secara otomatis ketika sebuah objek dari kelas tersebut dibuat. Constructor digunakan untuk menginisialisasi data anggota dari sebuah kelas. Constructor memiliki nama yang sama dengan nama kelas dan tidak memiliki tipe pengembalian, termasuk void.

## Jenis - Jenis Constructor
1. Default Constructor
2. Parameterized Constructor
3. Copy Constructor

## Default Constructor
Constructor ini tidak memerlukan parameter dan biasanya digunakan untuk memberikan nilai awal pada anggota data.

Contoh:
```cpp
#include <iostream>
using namespace std;

class Mahasiswa {
private:
    string nama;
    int umur;
public:
    // Default Constructor
    Mahasiswa() {
        nama = "Prakikan Strukdat";
        umur = 19;
    }

    void tampilkanData() {
        cout << "Nama: " << nama << ", Umur: " << umur << endl;
    }
};

int main() {
    Mahasiswa mhs;
    mhs.tampilkanData();
    return 0;
}
```

## Parameterized Constructor
Constructor ini digunakan ketika kita ingin menginisialisasi data anggota dengan nilai tertentu pada saat pembuatan objek.

Contoh:
```cpp
#include <iostream>
using namespace std;

class Mahasiswa {
private:
    string nama;
    long long int nrp;
public:
    // Parameterized Constructor
    Mahasiswa(string n, long long int m) {
        nama = n;
        nrp = m;
    }

    void tampilkanData() {
        cout << "Nama: " << nama << ", NRP: " << nrp << endl;
    }
};

int main() {
    Mahasiswa mhs("Praktikan Strukdat", 5027231001);
    mhs.tampilkanData();
    return 0;
}
```
Parameterized constructor adalah constructor yang menerima parameter untuk menginisialisasi anggota data kelas. Dalam hal ini, constructor Mahasiswa menerima dua parameter:

- string n: Parameter untuk menginisialisasi anggota data nama.
- long long int m: Parameter untuk menginisialisasi anggota data nrp.

Ketika objek Mahasiswa dibuat menggunakan constructor ini, nilai-nilai yang diberikan sebagai parameter akan digunakan untuk menginisialisasi anggota data nama dan nrp.

## Copy Constructor
Constructor ini digunakan untuk membuat objek baru sebagai salinan dari objek yang sudah ada.
```cpp
#include <iostream>
using namespace std;

class Mahasiswa {
private:
    string nama;
    long long int nrp;
public:
    // Parameterized Constructor
    Mahasiswa(string n, long long int m) {
        nama = n;
        nrp = m;
    }

    // Copy Constructor
    Mahasiswa(const Mahasiswa &mhs) {
        nama = mhs.nama;
        nrp = mhs.nrp;
    }

    void tampilkanData() {
        cout << "Nama: " << nama << ", NRP: " << nrp << endl;
    }
};

int main() {
    Mahasiswa mhs1("Praktikan Strukdat", 5027231001);
    Mahasiswa mhs2 = mhs1; // Memanggil Copy Constructor
    mhs2.tampilkanData();
    return 0;
}
```
Disini kita membuat objek baru mhs2 sebagai salinan dari mhs1 menggunakan copy constructor. Ini berarti mhs2 akan memiliki nama dan nrp yang sama dengan mhs1.

>Source: https://www.programiz.com/cpp-programming/constructors