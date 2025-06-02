## Daftar Isi
- [Daftar Isi](#Daftar-Isi)
- [Standard Template Library](#Standard-Template-Library)
- [Standard_Template_Library_Algorithm](##Standard-Template-Library-Algorithm)
- [Standard_Template_Library_Container](##Standard-Template-Library-Container)
    - [Array](###`std::array`) 
    - [vector](###`std::vector`)
    - [list](###`std::list`)
    - [stack](###`std::stack`)
    - [queue](###`std::queue`)
    - [deque](###`std::deque`)
    - [priority_queue](###`std::priority_queue`)
    - [map](###`std::map`)
    - [set](###`std::set`)
    - [unordered_set](###`std::unordered_set`)
    - [unordered_map](###`std::unordered_map`)
    - [PBDS](###`PBDS`)
- [Standard Template Library Functors](##Standard-Template-Library-Functors)
	- [Lambda Expressions](###Lambda-Expressions)
- [Standard Template Library Iterator](##Standard-Template-Library-Iterator)
	- [Operations of iterators](###Operations-of-iterators:)
- [Reference](##Reference)

## Standard Template Library

Standard Template Library (STL) di C++ adalah sebuah library standar yang menyediakan sejumlah kelas template dan fungsi yang dirancang untuk mempermudah dan mempercepat proses pengembangan program. STL memberikan berbagai struktur data dan algoritma yang sering digunakan, yang diimplementasikan dengan efisien dan konsisten, sehingga programmer tidak perlu menulis ulang kode-kode yang umum digunakan. Tujuan utama dari STL adalah untuk men-standarisasi dan meningkatkan performa kode yang dituliskan dengan tepat.

STL ini sendiri memiliki empat komponen, yaitu:

1. Algoritma
2. Containers
3. Function
4. Iterators


## Standard Template Library Algorithm
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


## Standard Template Library Container

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
* Reverse iteration, Memakai `rbegin()` dan `rend()` yang mengembalikan reverse-iterator—yakni iterator yang berjalan dari elemen terakhir menuju pertama.
* Structured binding (C++17), Fitur C++17 untuk “mengurai” aggregate (termasuk std::array) ke variabel terpisah dalam satu baris. 
* Comparison operators, std::array mendukung semua operator perbandingan lexicographical: ==, !=, <, <=, >, >= (dan <=> di C++20). Perbandingan < akan memeriksa elemen satu per satu dari depan: Jika ganjil[0] < genap[0] maka ganjil < genap tanpa memeriksa lebih lanjut. Jika sama terus, baru lanjut ke indeks berikutnya.

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
* `rbegin()` dan `rend()` menyediakan reverse iterators untuk melakukan iterasi dari akhir ke awal
 
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
* `rbegin()` dan `rend()` pada `std::deque` (dan container STL lainnya) menyediakan reverse iterators untuk melakukan iterasi dari akhir ke awal

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

### `std::unordered_set`

std::unordered_set adalah sebuah **associative container** yang menampung elemen-elemen unik tanpa urutan tertentu, dan memungkinkan pengambilan elemen individu yang cepat berdasarkan nilai mereka menggunakan **hash table**.

Dalam std::unordered_set, nilai elemen sekaligus merupakan **key** yang mengidentifikasinya secara unik. Key bersifat **immutable** (tidak dapat diubah), oleh karena itu elemen dalam unordered_set tidak dapat dimodifikasi setelah berada di dalam container - mereka hanya dapat dimasukkan dan dihapus.

Secara internal, elemen-elemen dalam unordered_set tidak diurutkan dalam urutan tertentu, tetapi diorganisir ke dalam **bucket** berdasarkan **hash values** mereka untuk memungkinkan akses cepat ke elemen individu secara langsung berdasarkan nilai mereka (dengan kompleksitas waktu rata-rata konstan).

Container unordered_set **lebih cepat** daripada set container untuk mengakses elemen individu berdasarkan key mereka, meskipun umumnya kurang efisien untuk iterasi rentang melalui subset elemen mereka.

Template Declaration <br/>

```cpp
template < class Key,                        // unordered_set::key_type/value_type
           class Hash = hash<Key>,           // unordered_set::hasher
           class Pred = equal_to<Key>,       // unordered_set::key_equal
           class Alloc = allocator<Key>      // unordered_set::allocator_type
           > class unordered_set;
```

Template Parameters<br/>
* **Key** - Tipe elemen. Setiap elemen dalam unordered_set juga diidentifikasi secara unik oleh nilai ini.
* **Hash** - Fungsi hash yang mengambil objek bertipe sama dengan elemen dan mengembalikan nilai unik bertipe size_t.
* **Pred** - Predikat biner untuk menentukan kesetaraan dua key.
* **Alloc** - Tipe objek allocator untuk mengelola alokasi memori.

Container Properties <br/>
* **Associative** - Elemen direferensikan berdasarkan key mereka, bukan posisi absolut.
* **Unordered** - Menggunakan hash table untuk organisasi elemen.
* **Set** - Nilai elemen sekaligus merupakan key yang mengidentifikasinya.
* **Unique keys** - Tidak ada dua elemen yang dapat memiliki key yang setara.
* **Allocator-aware** - Menggunakan objek allocator untuk mengelola kebutuhan storage secara dinamis.

Operasi-operasi yang ada di std::unordered_set: <br/>

Capacity <br/>
* `empty()` - Memeriksa apakah container kosong atau tidak.
* `size()` - Mendapatkan jumlah elemen pada unordered_set.
* `max_size()` - Mendapatkan jumlah maksimal elemen yang dapat ditampung.

Iterators <br/>
* `begin()` - Iterator yang menunjuk awal sekuens dari unordered_set.
* `end()` - Iterator yang menunjuk elemen setelah akhir sekuens unordered_set.
* `cbegin()` - Const iterator yang menunjuk awal sekuens.
* `cend()` - Const iterator yang menunjuk elemen setelah akhir sekuens.

Element Lookup <br/>
* `find()` - Menemukan elemen berdasarkan key dan mengembalikan iterator.
* `count()` - Mencari jumlah elemen dengan nilai yang sama. Karena setiap elemen di unordered_set unik, mengembalikan 1 jika ditemukan, 0 jika tidak.
* `equal_range()` - Mendapatkan rentang elemen dengan key tertentu.

Modifiers <br/>
* `insert()` - Memasukkan elemen ke dalam container.
* `emplace()` - Membangun dan memasukkan elemen secara in-place.
* `emplace_hint()` - Membangun dan memasukkan elemen dengan hint posisi.
* `erase()` - Menghapus elemen di posisi atau range tertentu.
* `clear()` - Menghapus seluruh elemen sehingga ukuran container menjadi 0.
* `swap()` - Menukar seluruh elemen dengan unordered_set lain yang memiliki tipe data yang sama.
 
Buckets <br/>
* `bucket_count()` - Mengembalikan jumlah bucket.
* `max_bucket_count()` - Mengembalikan jumlah maksimal bucket.
* `bucket_size()` - Mengembalikan ukuran bucket tertentu.
* `bucket()` - Menentukan bucket mana yang berisi elemen tertentu.

Hash Policy <br/>
* `load_factor()` - Mengembalikan load factor saat ini (rasio elemen terhadap bucket).
* `max_load_factor()` - Mendapatkan atau mengatur maksimal load factor.
* `rehash()` - Mengatur jumlah bucket.
* `reserve()` - Meminta perubahan kapasitas untuk menampung elemen tertentu.

Observers <br/>
* `hash_function()` - Mendapatkan fungsi hash yang digunakan.
* `key_eq()` - Mendapatkan predikat kesetaraan key.
* `get_allocator()` - Mendapatkan objek allocator.

Keunggulan std::unordered_set: <br/>
* **Akses cepat** - Kompleksitas waktu rata-rata O(1) untuk operasi pencarian, penyisipan, dan penghapusan.
* **Efisiensi memori** - Hanya menyimpan key sekali karena sifat unique.
* **Fleksibilitas** - Mendukung custom hash function dan equality predicate.

Kekurangan std::unordered_set: <br/>
* **Tidak terurut** - Elemen tidak disimpan dalam urutan tertentu.
* **Tidak ada lower_bound/upper_bound** - Operasi ini tidak tersedia karena tidak ada pengurutan.
* **Overhead hash** - Memerlukan perhitungan hash yang dapat mempengaruhi performa pada kasus terburuk.

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

### `PBDS`
 
Kurang lebih, struktur data ini berfungsi sama seperti `std::set` tetapi, memiliki tambahan fungsi lain, yaitu:
* `find_by_order(k)` - Mengembalikan bilangan pada urutan ke - K jika diurutkan secara *ascending*.
* `order_of_key(val)` - Mengembalikan banyaknya bilangan yang memiliki nilai lebih kecil dari.
 
Implementasi `map`, `set`, `priority_queue`, dan `PBDS` menggunakan struktur data balanced binary search tree atau heap yang menyebabkan pengaksesan elemen pada STL tersebut membutuhkan waktu yang logaritmik terhadap jumlah elemennya *O(lgN)*. Sedangkan STL lain yang dijelaskan di modul ini membutuhkan waktu konstan untuk mengakses elemen-elemennya *O(1)*.

Untuk informasi lebih detail mengenai  PBDS dapat dilihat di : [https://codeforces.com/blog/entry/11080](https://codeforces.com/blog/entry/11080).

Contoh implementasi STL Container dapat dilihat pada link [berikut](https://github.com/lab-kcks/modul-strukdat-pbo/tree/main/Modul%205/code/Standard%20template%20library)

Contoh implementasi STL Container menggunakan OOP dapat dilihat pada link [berikut](https://github.com/lab-kcks/modul-strukdat-pbo/tree/main/Modul%205/code/Standard%20template%20library/OOP)

## Standard Template Library Functors
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


## Standard Template Library Iterator
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

## Contoh Penyelesaian Soal menggunakan stl

https://cses.fi/problemset/task/1164

```
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> ans(N);
	vector<pair<pair<int, int>, int>> v(N);

	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first.first >> v[i].first.second;
		v[i].second = i;  // store the original index
	}
	sort(v.begin(), v.end());

	int last_room = 0;
	using Room = pair<int, int>;
	priority_queue<Room, vector<Room>, greater<Room>>
	    pq;  // min heap to store departure times.
	for (int i = 0; i < N; i++) {
		if (pq.empty() || pq.top().first >= v[i].first.first) {
			last_room++;
			pq.push(make_pair(v[i].first.second, last_room));
			ans[v[i].second] = last_room;
		} else {
			// accessing the minimum departure time
			Room minimum = pq.top();
			pq.pop();
			pq.push(make_pair(v[i].first.second, minimum.second));
			ans[v[i].second] = minimum.second;
		}
	}

	cout << last_room << "\n";
	for (int i = 0; i < N; i++) { cout << ans[i] << " "; }
}
```

## Reference

https://cplusplus.com/reference/stl/ <br />
https://cses.fi/book/book.pdf <br />
https://cp-algorithms.com/ <br />
https://usaco.guide/dashboard <br />
https://www.learncpp.com/ <br />


