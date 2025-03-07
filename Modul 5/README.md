# Modul 5 - Standard Template Library (STL) dan Graf

## Daftar Isi
- [Daftar Isi](#Daftar-Isi)
- [Standard Template Library](#Standard-Template-Library)
- [Graf](#Graf)

## Standard Template Library
Standard Template Library (STL) di C++ adalah sebuah library standar yang menyediakan sejumlah kelas template dan fungsi yang dirancang untuk mempermudah dan mempercepat proses pengembangan program. STL memberikan berbagai struktur data dan algoritma yang sering digunakan, yang diimplementasikan dengan efisien dan konsisten, sehingga programmer tidak perlu menulis ulang kode-kode yang umum digunakan. Tujuan utama dari STL adalah untuk men-standarisasi dan meningkatkan performa kode yang dituliskan dengan tepat.

Misalnya, daripada bingung apakah array biasa bisa menampung lebih dari 257 data, kita bisa menggunakan vector yang secara otomatis memperluas kapasitasnya. Vector sebenarnya mirip dengan array, tetapi lebih fleksibel karena bisa dengan mudah diperbesar atau diperkecil sesuai kebutuhan. Ini membuat kita tidak perlu lagi pusing soal ukuran. Selain itu, vector memungkinkan kita untuk memanfaatkan berbagai algoritma dari STL untuk manipulasi data, sehingga lebih praktis dan aman dibandingkan array biasa.

STL ini sendiri memiliki empat komponen, yaitu:

1. Algoritma
2. Containers
3. Function
4. Iterators

## Contoh penggunaan Standard Template Library 
![bobbl sort](https://github.com/lab-kcks/Modul-STRUKDAT/assets/121095246/aa0ea971-4409-414c-8fb4-7c7c073d55ff)

### Contoh sorting tanpa STL dalam C++:
```cpp
#include <iostream>
using namespace std;

//Fungsi Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        //Bagian ini bisa pake swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    cout << "Hasil: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

```
### Contoh sorting dengan STL dalam C++:
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Untuk std::sort
using namespace std;

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    sort(arr.begin(), arr.end());

    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

```
## [ 1 ] Standard Template Library Algorithm
Komponen algorithm di STL (Standard Template Library) adalah sekumpulan fungsi yang menyediakan berbagai algoritma umum untuk operasi pada data, seperti pengurutan, pencarian, manipulasi, dan lainnya. Berikut adalah beberapa jenis algoritma yang termasuk dalam komponen ini:
1. **Pengurutan (Sorting)**: Algoritma untuk mengurutkan elemen-elemen dalam kontainer.
* Contoh: sort, stable_sort, partial_sort

2. **Pencarian (Searching)**: Algoritma untuk mencari elemen dalam kontainer.
* Contoh: find, binary_search, find_if

3. **Pengurutan Parsial (Partial Sorting)**: Algoritma untuk mengurutkan sebagian dari kontainer.
* Contoh: partial_sort, nth_element

4. **Modifikasi (Modifying)**: Algoritma untuk memodifikasi elemen dalam kontainer.
* Contoh: copy, copy_if, fill, transform

5. **Penghapusan (Removing)**: Algoritma untuk menghapus elemen dari kontainer.
* Contoh: remove, remove_if, unique

6. **Permutasi (Permutation)**: Algoritma untuk menghasilkan permutasi elemen.
* Contoh: next_permutation, prev_permutation

7. **Akumulasi dan Perhitungan (Numeric)**: Algoritma untuk melakukan operasi numerik pada elemen kontainer.
* Contoh: accumulate, inner_product, partial_sum

8. **Pemeriksaan (Checking)**: Algoritma untuk memeriksa kondisi pada elemen kontainer.
* Contoh: all_of, any_of, none_of

9. **Penggabungan (Merging)**: Algoritma untuk menggabungkan elemen dari dua kontainer yang terurut.
* Contoh: merge, inplace_merge

10. **Rotasi dan Partisi (Rotation and Partitioning)**: Algoritma untuk mengatur ulang elemen dalam kontainer.
* Contoh: rotate, partition, stable_partition


## [ 2 ] Standard Template Library Container

Container adalah sebuah obyek yang digunakan untuk menyimpan sekumpulan obyek lain (disebut sebagai elemen pada container tersebut). Container ini dimplementasikan dengan template class sehingga sudah tersedia fungsi-fungsi yang nantinya bisa digunakan untuk mengakses elemen-elemennya.



### `std::array`
 
Masih ingat dengan Array?
 
`std::array` merupakan salah satu jenis struktur data yang dapat menyimpan data secara sekuensial dengan ukuran atau kapasitas yang tetap (fixed-size).
 
Berikut ini adalah operasi-operasi dari yang ada pada `std::array`:
* `operator[]` - Mengakses elemen pada posisi tertentu yang spesifik.
* `at()` - Mengakses elemen pada posisi tertentu yang spesifik sekaligus mengecek batas ukuran array. Perbedaan `at()` dengan `operator[]` ada ketika indeks elemen yang akan diakses melebihi batas ukuran array, pada `at()` program akan mengeluarkan error `out_of_range` sedangkan pada `operator[]` program akan mengeluarkan **undefined behaviour**.
* `front()` - Mengakses elemen yang ada di posisi pertama.
* `back()` - Mengakses elemen yang ada di posisi terakhir.
* `begin()` - Iterator yang menunjuk awal sekuens dari array.
* `end()` - Iterator yang menunjuk elemen setelah akhir sekuens array.
* `size()` - Mendapatkan jumlah elemen yang ada pada array.
* `max_size()` - Mendapatkan jumlah maksimal elemen yang dapat ditampung oleh array.
* `empty()` - Memeriksa apakah array sedang kosong atau tidak. Jika ukuran array adalah 0, maka program akan mengembalikan nilai `true`, tetapi sebaliknya program akan mengembalikan `false`.
* `swap()` - Menukar seluruh elemen pada sebuah array dengan seluruh elemen pada array lain yang memiliki tipe data dan ukuran yang sama.
* `fill()` - Mengisi seluruh elemen pada array dengan nilai tertentu.

Contoh implementasi STL Array dapat dilihat di link [berikut]

### `std::vector`
 
Masih ingat dengan Dynamic Array
 
`std::vector` adalah salah satu jenis struktur data yang merepresentasikan array dengan ukuran (kapasitas) yang dinamis sesuai dengan banyaknya data yang dimasukkan.
 
Operasi-operasi yang ada di `std::vector`:
* `operator[]` - Mengakses elemen di posisi tertentu yang spesifik.
* `at()` - Mengakses elemen di posisi tertentu yang spesifik sekaligus mengecek batas ukuran vector. Perbedaan `at()` dengan `operator[]` ada ketika indeks elemen yang akan diakses melebihi batas ukuran array, pada `at()` program akan mengeluarkan error `out_of_range` sedangkan pada `operator[]` program akan mengeluarkan **undefined behaviour**.
* `front()` - Mengakses elemen yang ada di posisi pertama.
* `back()` - Mengakses elemen yang ada di posisi terakhir.
* `begin()` - Iterator yang menunjuk awal sekuens dari vector.
* `end()` - Iterator yang menunjuk elemen setelah akhir sekuens vector.
* `size()` - Mendapatkan jumlah elemen yang ada pada vector.
* `max_size()` - Mendapatkan jumlah maksimal elemen yang dapat ditampung oleh vector.
* `resize()` - Mengubah ukuran vector menjadi jumlah elemen tertentu. `resize()` juga dapat disertai dengan menetapkan nilai tertentu, namun tidak akan mengubah elemen yang sudah ada nilainya sebelumnya (berbeda dengan `assign()`).
* `assign()` - Menetapkan ukuran vector menjadi jumlah elemen tertentu dengan nilai tertentu pada seluruh elemennya.
* `empty()` - Memeriksa apakah vector sedang kosong atau tidak. Jika ukuran vector adalah 0, maka program akan mengembalikan nilai `true`, tetapi sebaliknya program akan mengembalikan `false`.
* `push_back()` - Menambahkan elemen di posisi terakhir vector.
* `pop_back()` - Menghapus elemen yang ada di posisi terakhir.
* `insert()` - Memasukan nilai di posisi (atau range) tertentu.
* `erase()` - Menghapus nilai di posisi (atau range) tertentu.
* `clear()` - Menghapus seluruh elemen sehingga ukuran vector menjadi 0.
* `swap()` - Menukar seluruh elemen pada sebuah vector dengan seluruh elemen pada vector lain yang memiliki tipe data (ukuran dapat berbeda).
* `sort(first, last)` - Mengurutkan elemen pada vector secara *ascending* pada rentang [first, last].
* `lower_bound(first, last, val)` - Mengembalikan iterator yang menunjuk pada elemen terkecil yang tidak kurang dari *val* pada rentang [first, last]. Jika tidak ada, maka akan mengembalikan iterator last.
* `upper_bound(first, last, val)` - Mengembalikan iterator yang menunjuk pada elemen terkecil yang lebih dari *val* pada rentang [first, last]. Jika tidak ada, maka akan mengembalikan iterator last.

Contoh implementasi STL Vector dapat dilihat di link [berikut].
 
### `std::list`
 
Masih ingat dengan Linked List?
 
`std::list` adalah salah satu jenis struktur data yang menampung elemen secara sekuensial dan mampu melakukan operasi `insert()` dan `erase()` secara **constant time**.
 
Operasi-operasi yang ada di `std::list`:
* `front()` - Mengakses elemen yang ada di posisi pertama.
* `back()` - Mengakses elemen yang ada di posisi terakhir.
* `begin()` - Iterator yang menunjuk awal sekuens dari list.
* `end()` - Iterator yang menunjuk elemen setelah akhir sekuens list.
* `size()` - Mendapatkan jumlah elemen yang ada pada list.
* `max_size()` - Mendapatkan jumlah maksimal elemen yang dapat ditampung oleh list.
* `resize()` - Mengubah ukuran list menjadi jumlah elemen tertentu. `resize()` juga dapat disertai dengan menetapkan nilai tertentu, namun tidak akan mengubah elemen yang sudah ada nilainya sebelumnya (berbeda dengan `assign()`).
* `assign()` - Menetapkan ukuran list menjadi jumlah elemen tertentu dengan nilai tertentu pada seluruh elemennya.
* `empty()` - Memeriksa apakah list sedang kosong atau tidak. Jika ukuran list adalah 0, maka program akan mengembalikan nilai `true`, tetapi sebaliknya program akan mengembalikan `false`.
* `push_front()` - Menambahkan elemen di posisi pertama list.
* `pop_front()` - Menghapus elemen yang ada di posisi pertama list.
* `push_back()` - Menambahkan elemen di posisi terakhir list.
* `pop_back()` - Menghapus elemen yang ada di posisi terakhir list.
* `insert()` - Memasukan nilai di posisi (atau range) tertentu.
* `erase()` - Menghapus nilai di posisi (atau range) tertentu.
* `clear()` - Menghapus seluruh elemen sehingga ukuran list menjadi 0.
* `swap()` - Menukar seluruh elemen pada sebuah list dengan seluruh elemen pada vector lain yang memiliki tipe data (ukuran dapat berbeda).
* `sort()` - Mengurutkan elemen pada list secara *ascending*.
* `reverse()` - Membalikkan urutan posisi elemen.
* `merge()` - Memindahkan seluruh elemen pada sebuah list ke list lain dengan syarat kedua list sudah terurut sehingga seluruh elemen pada list tujuan pun terurut.
* `splice()` - Memindahkan seluruh elemen atau elemen tertentu pada sebuah posisi spesifik di list tersebut atau list lain.
* `unique()` - Menghapus elemen duplikat pada sebuah list dan menyisakan sebuah list yang berisikan elemen-elemen unik.
* `remove()` - Menghapus elemen dengan nilai tertentu. Berbeda dengan `erase()` yang menghapus berdasarkan posisi elemen, `remove()` menghapus elemen berdasarkan nilainya.
* `remove_if()` - Menghapus elemen dengan nilai tertentu yang memenuhi syarat tertentu.
 
Contoh implementasi STL List dapat dilihat di link [berikut]
 
### `std::stack`
 
Masih ingat dengan Stack?
 
`std::stack` adalah salah satu jenis struktur data dinamis yang mengikuti prinsip LIFO (Last In First Out).
 
Operasi-operasi yang ada di `std::stack`:
* `top()` - Mengakses elemen yang ada di posisi pertama.
* `size()` - Mendapatkan jumlah elemen pada stack.
* `empty()` - Memeriksa apakah stack kosong atau tidak. Jika ukuran stack adalah 0, mengembalikan nilai `true`  tetapi sebaliknya program akan mengembalikan `false`.
* `push()` - Menambahkan elemen di posisi pertama.
* `pop()` - Menghapus elemen di posisi pertama.
* `swap()` - Menukar seluruh elemen pada sebuah stack dengan seluruh elemen pada stack lain yang memiliki tipe data yang sama (ukuran dapat berbeda).

Contoh implementasi STL Stack dapat dilihat di link [berikut]

### `std::queue`
 
Masih ingat dengan Queue?
 
`std::queue` adalah salah satu jenis struktur data dinamis yang mengikuti prinsip FIFO (First In First Out).
 
Operasi-operasi yang ada di `std::queue`: 
* `front()` - Mengakses elemen yang ada di posisi pertama.
* `back()` - Mengakses elemen yang ada di posisi terakhir.
* `size()` - Mendapatkan jumlah elemen pada queue.
* `empty()` - Memeriksa apakah queue kosong atau tidak. Jika ukuran queue adalah 0, mengembalikan nilai `true`  tetapi sebaliknya program akan mengembalikan `false`.
* `push()` - Menambahkan elemen di posisi pertama.
* `pop()` - Menghapus elemen di posisi terakhir.
* `swap()` - Menukar seluruh elemen pada sebuah stack dengan seluruh elemen pada stack lain yang memiliki tipe data yang sama (ukuran dapat berbeda).

Contoh implementasi STL Queue dapat dilihat di link [berikut].
 
### `std::deque`
 
Masih ingat dengan Deque?
 
`std::deque` adalah salah satu jenis struktur data dinamis yang dapat menambahkan atau mengurangi data baik di posisi awal maupun di posisi akhir.
 
Operasi-operasi yang ada di `std::deque`:
* `operator[]` - Mengakses elemen pada posisi tertentu yang spesifik.
* `at()` - Mengakses elemen pada posisi tertentu yang spesifik sekaligus mengecek batas ukuran deque. Perbedaan `at()` dengan `operator[]` ada ketika indeks elemen yang akan diakses melebihi batas ukuran deque, pada `at()` program akan mengeluarkan error `out_of_range` sedangkan pada `operator[]` program akan mengeluarkan **undefined behaviour**.
* `front()` - Mengakses elemen yang ada di posisi pertama.
* `back()` - Mengakses elemen yang ada di posisi terakhir.
* `begin()` - Iterator yang menunjuk awal sekuens dari deque.
* `end()` - Iterator yang menunjuk elemen setelah akhir sekuens deque.
* `size()` - Mendapatkan jumlah elemen yang ada pada deque.
* `max_size()` - Mendapatkan jumlah maksimal elemen yang dapat ditampung oleh deque.
* `resize()` - Mengubah ukuran deque menjadi jumlah elemen tertentu. `resize()` juga dapat disertai dengan menetapkan nilai tertentu, namun tidak akan mengubah elemen yang sudah ada nilainya sebelumnya (berbeda dengan `assign()`).
* `assign()` - Menetapkan ukuran deque menjadi jumlah elemen tertentu dengan nilai tertentu pada seluruh elemennya.
* `empty()` - Memeriksa apakah deque sedang kosong atau tidak. Jika ukuran list adalah 0, maka program akan mengembalikan nilai `true`, tetapi sebaliknya program akan mengembalikan `false`.
* `push_front()` - Menambahkan elemen di posisi pertama deque.
* `pop_front()` - Menghapus elemen yang ada di posisi pertama deque.
* `push_back()` - Menambahkan elemen di posisi terakhir deque.
* `pop_back()` - Menghapus elemen yang ada di posisi terakhir deque.
* `insert()` - Memasukan nilai di posisi (atau range) tertentu.
* `erase()` - Menghapus nilai di posisi (atau range) tertentu.
* `clear()` - Menghapus seluruh elemen sehingga ukuran list menjadi 0.
* `swap()` - Menukar seluruh elemen pada sebuah list dengan seluruh elemen pada vector lain yang memiliki tipe data (ukuran dapat berbeda).

Contoh implementasi STL Deque dapat dilihat di link [berikut]
 
### `std::priority_queue`
 
Masih ingat dengan Priority Queue ?
 
`std::priority_queue` adalah salah satu jenis struktur data dinamis yang dapat dengan otomatis menampung elemen dengan susunan terurut secara **descending**.
 
Operasi-operasi yang ada di `std::priority_queue`:
* `top()` - Mengakses elemen yang ada di posisi pertama.
* `size()` - Mendapatkan jumlah elemen pada priority queue.
* `empty()` - Memeriksa apakah priority queue kosong atau tidak. Jika ukuran priority queue adalah 0, mengembalikan nilai `true`  tetapi sebaliknya program akan mengembalikan `false`.
* `push()` - Menambahkan elemen di posisi pertama.
* `pop()` - Menghapus elemen di posisi pertama.
* `swap()` - Menukar seluruh elemen pada sebuah priority queue dengan seluruh elemen pada priority queue lain yang memiliki tipe data yang sama (ukuran dapat berbeda).

Contoh implementasi STL Priority Queue dapat dilihat di link [berikut]
 
### `std::map`
 
`std::map` adalah sebuah **associative container** yang menampung elemen dalam bentuk **key-value**.
 
Operasi-operasi yang ada di `std::map`:
* `operator[]` - Mengakses value dari suatu key tertentu.
* `begin()` - Iterator yang menunjuk awal sekuens dari map.
* `end()` - Iterator yang menunjuk elemen setelah akhir sekuens map.
* `size()` - Mendapatkan jumlah elemen pada map.
* `max_size()` - Mendapakan jumlah maksimal elemen yang dapat ditampung oleh map.
* `empty()` - Memeriksa apakah map kosong atau tidak. Jika ukuran map adalah 0, mengembalikan nilai `true`  tetapi sebaliknya program akan mengembalikan `false`.
* `insert()` - Memasukkan nilai di posisi (atau range) tertentu.
* `erase()` - Menghapus nilai di posisi (atau range) tertentu.
* `clear()` - Menghapus seluruh elemen sehingga ukuran map menjadi 0.
* `swap()` - Menukar seluruh elemen pada sebuah map dengan seluruh elemen pada map lain yang memiliki tipe data yang sama (ukuran dapat berbeda).
* `find()` - Menemukan elemen berdasarkan key.
* `count()` - Mencari jumlah elemen dengan nilai yang sama.

Contoh implementasi STL Map dapat dilihat di link [berikut]
 
### `std::set`
 
`std::set` adalah sebuah **associative container** yang menampung elemen dalam bentuk **key-value** dimana **value**-nya merupakan **key**-nya sehingga setiap elemen merupakan elemen yang unik.
 
Operasi-operasi yang ada di `std::set`:
* `begin()` - Iterator yang menunjuk awal sekuens dari set.
* `end()` - Iterator yang menunjuk elemen setelah akhir sekuens set.
* `size()` - Mendapatkan jumlah elemen pada set.
* `max_size()` - Mendapakan jumlah maksimal elemen yang dapat ditampung oleh set.
* `empty()` - Memeriksa apakah set kosong atau tidak. Jika ukuran set adalah 0, mengembalikan nilai `true`  tetapi sebaliknya program akan mengembalikan `false`.
* `insert()` - Memasukkan nilai di posisi (atau range) tertentu.
* `erase()` - Menghapus nilai di posisi (atau range) tertentu.
* `clear()` - Menghapus seluruh elemen sehingga ukuran map menjadi 0.
* `swap()` - Menukar seluruh elemen pada sebuah set dengan seluruh elemen pada set lain yang memiliki tipe data yang sama (ukuran dapat berbeda).
* `find()` - Menemukan elemen berdasarkan key.
* `count()` - Mencari jumlah elemen dengan nilai yang sama. Karena setiap elemen di set merupakan elemen yang unik, maka jika elemen ditemukan akan mengembalikan nilai `1` sedangkan jika tidak, maka program akan mengembalikan nilai `0`.
* `lower_bound(val)` - mengembalikan iterator yang menunjuk ke key yang memiliki nilai terkecil yang tidak lebih kecil dari *va;*. Jika tidak ada, maka akan mengembalikan iterator `end()`.
* `upper_bound(val)` - mengembalikan iterator yang menunjuk ke key yang memiliki nilai terkecil yang lebih besar dari *val*. Jika tidak ada, maka akan mengembalikan iterator `end()`.

### `std::unordered_map`

Masih ingat dengan Hash table ?

std::unordered_map adalah sebuah associative container yang menampung elemen dalam bentuk key-value dengan tidak ada urutan tertentu. Container ini menggunakan hash table untuk menyimpan data, sehingga operasi pencarian, penyisipan, dan penghapusan memiliki kompleksitas waktu rata-rata O(1).

Operasi-operasi yang ada di std::unordered_map:

* `operator[]` - Mengakses value dari suatu key tertentu. Jika key tidak ada, operasi ini akan membuat entry baru dengan key tersebut dan value default.
* `begin()` - Iterator yang menunjuk awal sekuens dari map (urutan tidak terdefinisi).
* `end()` - Iterator yang menunjuk elemen setelah akhir sekuens map.
* `size()` - Mendapatkan jumlah elemen pada map.
* `empty()` - Memeriksa apakah map kosong. Mengembalikan true jika ukuran map 0, sebaliknya false.
* `insert()` - Memasukkan pasangan key-value. Jika key sudah ada, operasi ini tidak akan mengubah value.
* `erase()` - Menghapus elemen berdasarkan key atau posisi iterator.
* `clear()` - Menghapus seluruh elemen.
* `swap()` - Menukar seluruh elemen dengan map lain yang bertipe sama.
* `find()` - Mencari elemen berdasarkan key. Mengembalikan iterator ke elemen jika ditemukan, atau end() jika tidak.
* `count()` - Mengembalikan 1 jika key ada, atau 0 jika tidak (karena key bersifat unik).
* `bucket_count()` - Mendapatkan jumlah bucket (slot hash) yang digunakan dalam hash table.
* `bucket(key)` - Mendapatkan nomor bucket tempat key tertentu disimpan.
* `load_factor()` - Mendapatkan rasio rata-rata elemen per bucket.
* `max_load_factor()` - Mendapatkan atau mengatur rasio maksimum elemen per bucket sebelum rehashing dilakukan.
* `rehash(n)` - Mengatur ulang jumlah bucket untuk menampung setidaknya n elemen.
* `reserve(n)` - Mengatur jumlah bucket agar dapat menampung n elemen tanpa melebihi max_load_factor.
* `hash_function()` - Mengembalikan fungsi hash yang digunakan.
* `key_eq()` - Mengembalikan fungsi pembanding kesamaan key.

Contoh implementasi STL unordered_map dapat dilihat di link [berikut]
 
### `PBDS`
 
Kurang lebih, struktur data ini berfungsi sama seperti `std::set` tetapi, memiliki tambahan fungsi lain, yaitu:
* `find_by_order(k)` - Mengembalikan bilangan pada urutan ke - K jika diurutkan secara *ascending*.
* `order_of_key(val)` - Mengembalikan banyaknya bilangan yang memiliki nilai lebih kecil dari.
 
Implementasi `map`, `set`, `priority_queue`, dan `PBDS` menggunakan struktur data balanced binary search tree atau heap yang menyebabkan pengaksesan elemen pada STL tersebut membutuhkan waktu yang logaritmik terhadap jumlah elemennya *O(lgN)*. Sedangkan STL lain yang dijelaskan di modul ini membutuhkan waktu konstan untuk mengakses elemen-elemennya *O(1)*.
 
Contoh implementasi STL PBDS dapat dilihat di link [berikut].


Untuk informasi lebih detail mengenai STL dapat dibaca di : cplusplus.com Khusus untuk PBDS dapat dilihat di : [https://codeforces.com/blog/entry/11080](https://codeforces.com/blog/entry/11080).

## [ 3 ] Standard Template Library Functors
Komponen functors di STL (Standard Template Library) mengacu pada objek yang bertindak seperti fungsi. Functors, atau function objects, adalah kelas atau struct yang mengimplementasikan operator () sehingga objek dari kelas tersebut bisa digunakan sebagai fungsi. Functors sering digunakan untuk mengkustomisasi perilaku algoritma STL.

### Contoh penggunaan functors
```cpp
#include <iostream>

// Definisi functor yang mengimplementasikan operator ()
struct Add {
    int operator()(int a, int b) const {
        return a + b;
    }
};

int main() {
    Add add;
    std::cout << "5 + 3 = " << add(5, 3) << std::endl;
    return 0;
}
```

### Lambda Expressions
C++11 memperkenalkan lambda expressions, yang sering digunakan sebagai alternatif functors. Lambda memungkinkan pembuatan fungsi anonim dengan sintaks yang lebih ringkas.


## [ 4 ] Standard Template Library Iterator
Komponen iterator di STL (Standard Template Library) adalah objek yang digunakan untuk melintasi dan mengakses elemen-elemen dalam sebuah kontainer seperti vector, list, atau map. Mereka terutama digunakan dalam urutan angka, karakter, dll. Iterator menyediakan cara yang abstrak dan konsisten untuk mengakses elemen-elemen dalam kontainer tanpa tergantung pada tipe kontainer itu sendiri. 

### Operations of iterators:
1. begin(): Fungsi ini digunakan untuk mengembalikan posisi awal (iterator) dari kontainer.
2. end(): Fungsi ini digunakan untuk mengembalikan posisi setelah akhir (iterator) dari kontainer.
3. advance(): Fungsi ini digunakan untuk menginkrementasi posisi iterator sebanyak jumlah tertentu yang ditentukan dalam argumennya.
4. next(): Fungsi ini mengembalikan iterator baru yang menunjukkan posisi setelah menginkrementasi posisi sebanyak yang ditentukan dalam argumennya.
5. prev(): Fungsi ini mengembalikan iterator baru yang menunjukkan posisi setelah mengurangi posisi sebanyak yang ditentukan dalam argumennya.
6. inserter(): Fungsi ini digunakan untuk menyisipkan elemen pada posisi tertentu dalam kontainer. Fungsi ini menerima 2 argumen, yaitu kontainer dan iterator ke posisi di mana elemen akan disisipkan.


### Contoh penggunaan iterator dalam C++
```cpp
#include<iostream> 
#include<iterator> // for iterators 
#include<vector> // for vectors 
using namespace std; 
int main() 
{ 
	vector<int> ar = { 1, 2, 3, 4, 5 }; 
	
	// Declaring iterator to a vector 
	vector<int>::iterator ptr = ar.begin(); 
	
	// Using advance() to increment iterator position 
	// points to 4 
	advance(ptr, 3); 
	
	// Displaying iterator position 
	cout << "The position of iterator after advancing is : "; 
	cout << *ptr << " "; 
	
	return 0; 
	
} 
```

## Graf

### Graph terminology
Berikut adalah pengertian dari komponen/tipe-tipe graf

| Terminologi | Pengertian |
| -- | -- |
| `Nodes` | Titik-titik dalam graph yang mewakili entitas atau objek. Contohnya, orang dalam jaringan sosial atau kota dalam peta.
| `Vertex` | unit dasar dari graf |
| `Edge` | garis yang menghubungkan 2 *vertex* |
| `Weight` | berat / panjang dari suatu *edge* |
| `Weighted graph` | graf dengan setiap *edge*-nya **memiliki** berat |
| `Unweighted graph` | graf dengan setiap *edge*-nya **tidak** memiliki berat |
| `Directed graph` | graf dimana *edge* nya **memiliki** arah |
| `Undirected graph` | graf dimana *edge*-nya **tidak** memiliki arah |
| `Path` | Urutan dari *vertex* dan *edge* yang menghubungkan 2 *vertex* |
| `Cycle` | *path* yang dimulai dan diakhiri pada 1 buah vertex yang sama |


## Implementasi Graf

Beberapa implementasi graf dalam kehidupan sehari-hari:

* Umum digunakan oleh compiler untuk menggambarkan alokasi sumber daya ke proses atau menunjukkan analisis aliran data, dll.
* Umum digunakan untuk menggambarkan grafik jaringan, atau grafik semantik atau bahkan untuk menggambarkan aliran komputasi.
* Digunakan untuk membangun sistem transportasi khususnya jaringan jalan. Contoh populer: peta Google yang secara ekstensif menggunakan graph.

Beberapa kelebihan dari graf:

* Mudah diimplementasikan untuk mencari rute terdekat, tetangga dari vertex/node, dan sebagainya
* Membantu dalam mengorganisir data

Kekurangan dari graf:

* Menggunakan banyak pointer sehingga program dapat menjadi kompleks
* Dapat menggunakan memory yang besar

## Cara merepresentasikan graf

Terdapat beberapa cara yang biasa digunakan untuk merepresentasikan graf, yaitu:

### Sequential Representation / Adjacency Matrix

Kita bisa merepresentasikan graf dengan menggunakan array 2 dimensi `Adjmat[V][V]` dengan `AdjMat[i][j]` bernilai 1 apabila terdapat *edge* yang menghubungkan vertex i dan j, bernilai 0 jika tidak ada *edge*.

Nilai `AdjMat[i][j]` bisa bernilai *weight* dari suatu *edge* untuk weighted graf.

Contoh Adjacency Matrix

* Unweighted & Undirected Graph

![image](https://user-images.githubusercontent.com/77750276/201638781-62b65963-e776-4645-a3df-78f18022a697.png)

> Sumber gambar: [softwaretestinghelp.com](https://www.softwaretestinghelp.com/graph-implementation-cpp/)

* Unweighted & Directed Graph

![image](https://user-images.githubusercontent.com/77750276/201638804-68d9c29c-2771-43f0-9fe5-aed16843c46c.png)

> Sumber gambar: [softwaretestinghelp.com](https://www.softwaretestinghelp.com/graph-implementation-cpp/)

* Weighted & Directed Graph

![image](https://user-images.githubusercontent.com/77750276/201638818-a6775be3-88c8-48dc-be2d-45a13f2cb31a.png)

> Sumber gambar: [softwaretestinghelp.com](https://www.softwaretestinghelp.com/graph-implementation-cpp/)

Untuk implementasi pada codingan, dapat menggunakan array 2 Dimensi (sudah jarang digunakan)

### Linked Representation / Adjacency List

Masalah utama dari penggunaan adjacency matrix adalah penggunaan memory sebanyak $V^2$ memory untuk graph dengan *vertex* sebanyak V sehingga tidak cocok untuk graph dengan ukuran besar.

Solusi dari masalah itu adalah *Adjacency List*. Ide dari perepresentasian dengan menggunakan Adjacency list adalah dengan hanya menyimpan daftar dari vertex-vertx lain yang memiliki edge yang terhubung dengan suatu vertex.

Contoh Adjacency List:

* Unweighted & Undirected Graph

![image](https://user-images.githubusercontent.com/77750276/201638839-8a87453f-f0d6-4511-b914-8159986f9d3e.png)

> Sumber gambar: [softwaretestinghelp.com](https://www.softwaretestinghelp.com/graph-implementation-cpp/)

* Unweighted & Directed Graph

![image](https://user-images.githubusercontent.com/77750276/201638858-ebc75f8e-a05d-4114-ac4b-18d9b5b0ec5b.png)

> Sumber gambar: [softwaretestinghelp.com](https://www.softwaretestinghelp.com/graph-implementation-cpp/)

### Contoh Implementasi Code Adjacency List

Weighted Graph

```cpp
#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<pair <int, int>> adj[],int u,int v, int weight){
    adj[u].push_back(make_pair(v, weight));

    // Jika undirected, maka dipush ke 2 2 nya

    // adj[v].push_back(make_pair(u, weight));
}

void printGraph(vector<pair <int, int>> adj[],int V){
    // Loop sebanyak jumlah vertex
    for (int v = 0; v < V; v++){
        cout << "\n Adjacency list of vertex "
            << v << "\n head";

        for (int i = 0; i < adj[v].size(); i++){
            // Karena pakai <pair <int, int>>, jadi untuk ngeprint bisa menggunakan .first dan .second
            cout<<" --> "<< adj[v][i].first << " " << adj[v][i].second;
        }

        printf("\n");
    }
}

int main(){
    // Jumlah Vertex
    int V = 5;

    vector<pair <int, int>> adj[V];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 4, 3);
    addEdge(adj, 1, 3, 4);
    addEdge(adj, 2, 4, 2);
    addEdge(adj, 1, 2, 3);

    printGraph(adj, V);

    return 0;
}
```

Unweighted Graph

```cpp
#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);

    // Jika undirected, maka dipush ke 2 2 nya

    // adj[v].push_back(u)
}

void printGraph(vector<int> adj[],int V){
    // Loop sebanyak jumlah vertex
    for (int v = 0; v < V; v++){
        cout << "\n Adjacency list of vertex "
            << v << "\n head";

        for (int i = 0; i < adj[v].size(); i++){
            cout<<" --> "<<adj[v][i];
        }

        printf("\n");
    }
}

int main(){
    // Jumlah Vertex
    int V = 5;

    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 1, 2);

    printGraph(adj, V);

    return 0;
}
```

## Referensi

* https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/ 
* https://www.techiedelight.com/terminology-and-representations-of-graphs/ 
* https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-graph/
* https://www.softwaretestinghelp.com/graph-implementation-cpp/

interactive visualization <br />
https://csacademy.com/lesson/graph_representation


## Graph Traversal
### DFS
DFS atau *Depth First Search* adalah metode yang digunakan untuk mencari jalur agar dapat menghindari cycle pada graph. Bedanya dengan BFS adalah DFS melakukan traversal hingga ke vertex paling 'dalam'.

DFS memanfaatkan **stack** & mengkategorikan vertex pada graph menjadi 2 kategori:

1. Visited
2. Not Visited

Cara Kerja DFS:

1. Dimulai dengan meletakkan vertex awal dari graph pada stack (push).
2. Ambil node yang berada paling bawah (pop) lalu tambahkan vertex ke list *visited*.
3. Cari tetangga dari node yang berada di paling bawah. Apabila tidak ada di list *visited*, masukkan ke dalam stack (push).
4. Ulangi langkah 2 - 3 hingga seluruh node sudah dikunjungi

Berikut adalah ilustrasi dari penggunaan DFS.

![image](https://user-images.githubusercontent.com/77750276/201640404-1090310d-1144-4eaa-af84-08ab2d87dabd.png)

![image](https://user-images.githubusercontent.com/77750276/201640433-4379380f-39b2-4a80-82a2-1266a875618b.png)

![image](https://user-images.githubusercontent.com/77750276/201640448-ff680965-4b1c-4a1b-98be-59faa0a288d2.png)

![image](https://user-images.githubusercontent.com/77750276/201640463-ef03631d-1af5-4406-bba3-f51fc1bae5d5.png)

![image](https://user-images.githubusercontent.com/77750276/201640489-65fcd18c-d769-4e50-a0eb-003754d88fde.png)


> Sumber gambar: [programiz.com](https://www.programiz.com/dsa/graph-dfs)
https://github.com/user-attachments/assets/4914b497-8724-42eb-a9c6-abe51cc715cf

### BFS
BFS atau *Breadth First Search* adalah metode pencarian jalur agar tidak ada 1 node yang sama terulang (untuk menghindari cycle) pada graph. BFS akan melakukan traversal untuk setiap layer dari graph. Layer 1 -> Layer 2 -> dst hingga selesai.

BFS bekerja dengan mengimplementasikan **queue**. BFS biasanya membagi *vertex* pada graph menjadi 2 kategori:

1. Visited
2. Not Visited

Cara Kerja BFS:

1. Dimulai dengan meletakkan vertex awal dari graph di queue paling belakang (enqueue)
2. Ambil node yang berada paling depan (deque) lalu tambahkan vertex ke list *visited*.
3. Cari tetangga dari node yang berada di queue paling depan. Apabila tidak ada di list *visited*, masukkan ke dalam list queue paling belakang (enqueue).
4. Ulangi langkah 2 - 3 hingga seluruh node sudah dikunjungi.

Berikut adalah ilustrasi dari penggunaan BFS.

![image](https://user-images.githubusercontent.com/77750276/201640865-76d9b5f8-305b-44eb-94a1-034258c20fe8.png)

![image](https://user-images.githubusercontent.com/77750276/201640879-2ce58772-e759-4dd8-b110-c756183c6f86.png)

![image](https://user-images.githubusercontent.com/77750276/201640906-b08abe69-7e1f-43d4-8f32-2492fb86d13e.png)

![image](https://user-images.githubusercontent.com/77750276/201640940-ce496e76-bd80-48b7-9275-c79feaa07a9b.png)

![image](https://user-images.githubusercontent.com/77750276/201640959-84a19607-0dc1-448f-b5f7-a2550d6b06a6.png)

> Sumber gambar: [programiz.com](https://www.programiz.com/dsa/graph-bfs)
https://github.com/user-attachments/assets/5c084a10-f2d7-4ac6-a900-cbf6287daf33

> interactive visualization <br />
https://csacademy.com/lesson/breadth_first_search <br />
https://csacademy.com/lesson/depth_first_search <br />

Application of graph traversal

Flood Fill <br />
Finding connected components in a graph represented by a grid.


## Shortest path
- Dijkstra 

Latihan <br />
https://cses.fi/problemset/task/1671

- Bellman–Ford
- Floyd–Warshall

Latihan <br />
https://cses.fi/problemset/task/1672

### Minimum spanning tree
- Prim

https://www.cs.usfca.edu/~galles/visualization/Prim.html

- Kruskal

https://github.com/user-attachments/assets/a0f43df4-11dc-40eb-8ab7-471ba2ee32a7

Latihan <br />
https://cses.fi/problemset/task/1675

Reference

https://cplusplus.com/reference/stl/ <br />
https://cses.fi/book/book.pdf <br />
https://cp-algorithms.com/ <br />
https://usaco.guide/dashboard <br />


