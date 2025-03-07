Data abstraction adalah salah satu fitur yang paling esensial dan penting dari pemrograman berorientasi objek di C++. Abstraction berarti hanya menampilkan informasi yang penting dan menyembunyikan detailnya. Data abstraction mengacu pada hanya memberikan informasi penting tentang data ke dunia luar, menyembunyikan detail latar belakang atau implementasi.  

Dalam contoh nyata seperti dalam laptop/komputer pengguna tahu kalau menekan tombol pada keyboard akan memberikan input pada laptop/komputer. Tetapi pengguna tersebut tidak tahu bagaimana implementasi kalau menekan tombol keyboard akan memberikan input pada laptop/komputer. Itulah yang disebut dengan abstraction.

**Tipe Abstraction:**  
**- Data Abstraction:** Tipe abstraction ini hanya menampilkan informasi yang diperlukan tentang data dan menyembunyikan data yang tidak diperlukan.  
**- Control Abstraction:** Tipe abstraction ini hanya menampilkan informasi yang diperlukan tentang implementasi dan menyembunyikan informasi yang tidak diperlukan.  

Contoh kode data abstraction:
```cpp
class PersegiPanjang {
private:
    // Variabel anggota privat
    double panjang;
    double lebar;

public:
    // Konstruktor untuk menginisialisasi persegi panjang
    PersegiPanjang(double p, double l) {
        panjang = p;
        lebar = l;
    }

    // Fungsi anggota publik untuk menghitung luas
    double getLuas() const {
        return panjang * lebar;
    }

    // Fungsi anggota publik untuk menghitung keliling
    double getKeliling() const {
        return 2 * (panjang + lebar);
    }

    // Fungsi anggota publik untuk mengatur dimensi persegi panjang
    void setDimensi(double p, double l) {
        if (p > 0 && l > 0) {
            panjang = p;
            lebar = l;
        } else {
            cout << "Dimensi harus bernilai positif." << endl;
        }
    }

    // Fungsi anggota publik untuk mendapatkan panjang
    double getPanjang() const {
        return panjang;
    }

    // Fungsi anggota publik untuk mendapatkan lebar
    double getLebar() const {
        return lebar;
    }
};
```

Contoh kode control abstraction: 

```cpp
class PrimeGenerator {
private:
    // Metode privat untuk mengecek apakah sebuah bilangan adalah bilangan prima
    bool isPrime(int number) const {
        if (number <= 1) {
            return false;
        }
        for (int i = 2; i <= number / 2; ++i) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

    // Metode privat untuk mendapatkan bilangan prima dalam rentang tertentu
    vector<int> getPrimes(int start, int end) const {
        vector<int> primes;
        for (int i = start; i <= end; ++i) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
        }
        return primes;

public:
    // Metode publik untuk mencetak bilangan prima dalam rentang tertentu
    void printPrimes(int start, int end) const {
        vector<int> primes = getPrimes(start, end);
        cout << "Bilangan prima antara " << start << " dan " << end << " adalah: ";
        for (int prime : primes) {
            cout << prime << " ";
        }
        cout << endl;
    }
};
```

