# Setter & Getter in C++
Dalam pemrograman berorientasi objek (OOP), setter dan getter adalah metode yang digunakan untuk mengakses dan memodifikasi data anggota (member data) dari sebuah kelas. Ini membantu dalam mengontrol akses ke data dan menjaga enkapsulasi.

- Setter: Metode yang digunakan untuk mengatur nilai anggota data.
- Getter: Metode yang digunakan untuk mendapatkan nilai anggota data.

**Keuntungan Menggunakan Setter & Getter**
- Mengontrol akses ke data anggota.
- Menjaga enkapsulasi.
- Memudahkan validasi data sebelum diatur.

**Contoh Implementasi Setter & Getter**
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

    // Setter untuk nama
    void setNama(string n) {
        nama = n;
    }

    // Getter untuk nama
    string getNama() const {
        return nama;
    }

    // Setter untuk nrp
    void setNRP(long long int m) {
        nrp = m;
    }

    // Getter untuk nrp
    long long int getNRP() const {
        return nrp;
    }

    void tampilkanData() const {
        cout << "Nama: " << nama << ", NRP: " << nrp << endl;
    }
};

int main() {
    Mahasiswa mhs("Praktikan Strukdat", 5027231001);
    mhs.tampilkanData();

    // Menggunakan setter
    mhs.setNama("Nicholas Marco");
    mhs.setNRP(5027221042);

    // Menggunakan getter
    cout << "Nama setelah diubah: " << mhs.getNama() << endl;
    cout << "NRP setelah diubah: " << mhs.getNRP() << endl;

    mhs.tampilkanData();
    return 0;
}
```
Pada program ini, kita:
- Membuat objek mhs dari kelas Mahasiswa menggunakan parameterized constructor.
- Menggunakan setter untuk mengubah nilai nama dan nrp.
- Menggunakan getter untuk mendapatkan nilai nama dan nrp yang telah diubah.
- Menampilkan data sebelum dan sesudah perubahan.