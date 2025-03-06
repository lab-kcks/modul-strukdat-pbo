# Modul 2 - Struktur Data Linier: Linked List dan Variannya

## **Daftar Isi**

- [Linked List](#linked-list)
- [Double Linked List](#double-linked-list)
- [Circular Linked List](#circular-linked-list)
- [Circular Double Linked List](#circular-double-linked-list)

## **Linked List**

### **Terminologi**
Beberapa istilah yang akan sering digunakan dalam mendeskripsikan linked list:
- Node: Sebuah elemen data yang dapat berisikan suatu nilai atau informasi yang dibutuhkan serta pada setiap node mengandung pointer ke node selanjutnya.
- Head: Node pertama dari linked list.
- Tail: Node terakhir dari linked list.

### **Apa itu Linked List?**
Linked list adalah struktur data linear, di mana elemen tidak disimpan di lokasi memori yang berdekatan. Elemen-elemen pada lineked list ditautkan menggunakan pointer seperti gambar di bawah ini:

![LinkedList](img/Singlelinkedlist.png)
> Sumber Gambar : https://www.geeksforgeeks.org/what-is-linked-list/?ref=lbp

Sebuah node pada linked list terdiri atas:
- Data atau informasi yang disimpan.
- Referensi (tautan) ke node selanjutnya.

### **Linked List vs Array**
| No  | Linked List | Array |
|----|-------------|-------|
| 1  | Linked list tidak disimpan di lokasi memori yang berdekatan. | Array disimpan di lokasi memori yang berdekatan. |
| 2  | Ukurannya dinamis. | Ukurannya tetap. |
| 3  | Memori dialokasi pada run time. | Memori dialokasi pada compile time. |
| 4  | Menggunakan memori yang lebih banyak dibandingkan array karena menyimpan data dan referensi ke node selanjutnya. | Menggunakan memori yang lebih sedikit dibandingkan array. |
| 5  | Elemen membutuhkan traversal ke seluruh linked list. | Elemen dapat dengan mudah diakses. |
| 6  | Operasi insert dan delete membutuhkan waktu. | Operasi insert dan delete dilakukan dengan lebih cepat. |

### **Ilustrasi**
Linked list dapat diilustrasikan dengan beberapa node yang saling terhubung satu dengan yang lain sehingga membentuk rangkaian yang saling berurutan. Contohnya terdapat list A dengan beberapa kumpulan data A =[2,6,8,9,15].

![Ilustrasi](img/ilustrasi1.png)

### **Operasi Dasar**
- isEmpty Untuk memeriksa apakah list kosong atau tidak.
- pushBack <br />
Untuk menambahkan data baru dari belakang list. Untuk ilustrasinya terdapat pada gambar di bawah.
![Pushback](img/pushBack.png)

- pushFront <br />
Untuk menambahkan data baru dari depan list. Untuk ilustrasinya terdapat pada gambar di bawah.
![pushFront](img/pushFront.png)

- insertAt <br />
Untuk menambahkan data baru pada posisi yang diinginkan. Untuk ilustrasinya terdapat pada gambar di bawah.
![insertAt](img/insertAt.png)

- back Untuk mendapatkan data yang ada di paling belakang.
- front Untuk mendapatkan data yang ada di paling depan.
- getAt Untuk mendapatkan data pada posisi tertentu.

- popBack <br />
Untuk menghapus data yang berada di posisi paling belakang. Untuk ilustrasinya terdapat pada gambar di bawah.
![popBack](img/popBack.png)

- popFront <br />
Untuk menghapus data yang berada di posisi paling depan. Untuk ilustrasinya terdapat pada gambar di bawah.
![popFront](img/popFront.png)

- remove(x) <br />
  Untuk menghapus data x yang pertama muncul dalam list. Untuk ilustrasinya terdapat pada gambar di bawah.
  ![removeX](img/removex.png)

### **Variasi Linked List**
- Singly-Linked List Setiap node memiliki data dan pointer ke node berikutnya. Untuk ilustrasinya terdapat pada gambar di bawah.
  ![Singly linked list](img/singly-linked-list.png)
- Double-Linked List Terdapat penambahan pointer ke node sebelumnya dalam double-linked list. Sehingga dapat menuju pada node sebelumnya dan node selanjutnya. Dua tautan ini disebut dengan next dan prev. Untuk ilustrasinya terdapat pada gambar di bawah.
  ![Double linked list](img/double-linked-list.png)
- Circular-Linked List Pada variasi ini elemen terakhir ditautkan ke elemen pertama. Ini membentuk lingkaran melingkar. Untuk ilustrasinya terdapat pada gambar di bawah.
  ![Circular-linked list](img/circular-linked-list.png)

### **Implementasi ADT: SinglyList**
Representasi dan Implementasi yang akan dijelaskan dalam modul ini adalah Singly Linked List yang menyimpan tipe data int. Representasi akan dibawa ke dalam bentuk Abstract Data Type (ADT) yang nantinya akan menjadi tipe data baru bernama SinglyList. <br />
Dalam implementasinya, kompleksitas waktunya yaitu:

| Operasi   | Keterangan                                      | Kompleksitas Waktu  |
|-----------|-----------------------------------------------|-----------------------|
| pushBack  | Memasukkan data baru dari belakang.           | O(N)                  |
| pushFront | Memasukkan data baru dari depan.              | O(1)                  |
| insertAt  | Memasukkan data baru pada posisi tertentu.    | O(N) (Worst-case)     |
| popBack   | Menghapus node paling belakang.               | O(N)                  |
| popFront  | Menghapus node paling depan.                  | O(1)                  |
| remove(x) | Menghapus node pertama dengan data x.         | O(N) (Worst-case)     |
| front     | Mendapatkan nilai node terdepan.              | O(1)                  |
| back      | Mendapatkan nilai node paling belakang.       | O(N)                  |
| getAt     | Mendapatkan nilai node pada posisi tertentu.  | O(N) (Worst-case)     |
| isEmpty   | Memeriksa apakah list kosong.                 | O(1)                  |

- Representasi Node


## **Double Linked List**
