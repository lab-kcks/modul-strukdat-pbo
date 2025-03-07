# Data Encapsulation in C++
![encapsulation](https://logicmojo.com/assets/dist/new_pages/images/encap.png)
> Source: https://logicmojo.com/assets/dist/new_pages/images/encap.png

## Data Encapsulation 
Encapsulation dalam pemrograman berorientasi objek (OOP) adalah konsep untuk mengemas data bersama dengan metode yang beroperasi pada data tersebut dalam sebuah class. Ini berarti bahwa data (variabel) bersama dengan operasi (metode atau fungsi) yang bekerja pada data itu, dikemas bersama dalam satu unit yang disebut objek. 

![](https://scaler.com/topics/images/member-functions-in-encapsulation.webp)
> Source: https://scaler.com/topics/images/member-functions-in-encapsulation.webp

### Implementasi
```cpp
class Segitiga {
  public:
    int alas;
    int tinggi;

    int getLuas() {
      return 0.5 * alas * tinggi;
    }
};
```
Program di atas digunakan untuk menghitung luas segitiga. Untuk menghitung luasnya diperlukan variable alas dan tinggi, serta function getLuas(). Dikemasnya variable serta function pada satu class ini disebut encapsulation. 

Pada program di atas, variable alas dan tinggi dapat diakses dari class lain. Maka, program di atas bukanlah contoh dari data hiding, tetapi hanya encapsulation.

> NOTE: Encapsulation sering dikira sebagai data hiding. Namun, hal tersebut tidak sepenuhnya benar.
> Encapsulation merujuk pada mengemas fields dan methods terkait menjadi satu. Hal ini dapat dimanfaatkan untuk data hiding, tetapi encapsulation itu sendiri bukan berarti data hiding.


***


## Data Hiding 
Data hiding adalah cara membatasi akses anggota data dengan menyembunyikan detail implementasi.

### Implementasi
```cpp
class Segitiga {
  private:
    int alas;
    int tinggi;

  public:
    int getAlas() {
      return alas;
    }

    void setAlas(int a) {
      if (a > 0) {
        alas = a;
      }
    }

    int getTinggi() {
      return tinggi;
    }

    void setTinggi(int t) {
      if (t > 0) {
        tinggi = t;
      }
    }

    int getLuas() {
      return 0.5 * alas * tinggi;
    }
};
```
Pada program di atas, variable alas dan tinggi kini dibuat menjadi private. Variable tersebut hanya dapat diakses dan dimanipulasi hanya dengan menggunakan function get dan set yang ada pada dalam class Segitiga. Program di atas mengimplementasikan encapsulation karena mengemas variable dan function pada satu class, dan juga memanfaatkan data hiding dengan menggunakan access specifier private.

### Access Specifier
Di OOP, data dapat dijadikan public, private, dan protected dengan menggunakan access specifier. Access specifier dapat diubah sesuai kebutuhan.

Access Specifier | Dalam class yang sama | Dalam subclass | Dari class lain
-- | -- | -- | --
Private | YES | NO | NO
Protected | YES | YES | NO
Public | YES | YES | YES



