# Modul 3 - Struktur Data Dasar: Stack, Queue, Dictionary, dan Hashing

## <b>Daftar Isi</b>
- [Stack](#stack)
- [Queue](#queue)
- [Deque](#deque)
- [Priority Queue](#priority-queue)
- [Dictionary](#dictionary)
- [Hashing](#hashing)


## <b>Stack</b>
<a name="stack"></a>

### Terminologi

- `Top` - node paling atas dalam stack.
- `LIFO` - last in first out.

### Definisi

Stack adalah struktur data dinamis yang mengikuti prinsip `LIFO`. Pada stack, elemen yang terakhir masuk ke dalam stack adalah elemen pertama yang dapat dihapus. Contoh implementasi stack dalam kehidupan sehari-hari adalah tumpukan kursi.

![Contoh Stack](images/contoh-stack-basic.jpg)

<!-- ## Operasi Dasar
Berikut adalah beberapa operasi yang dapat dilakukan pada stack
- isEmpty - untuk memeriksa apakah stack kosong atau tidak.
- size - untuk mendapatkan jumlah elemen pada stack.
- push - untuk menambahkan data pada tumpukan paling atas.
- pop - untuk menghapus data pada tumpukan paling atas.
- top/peek - untuk mendapatkan data pada tumpukan paling atas. -->

### Aplikasi Stack

Salah satu contoh penerapan dari stack adalah `mengubah notasi infix menjadi postfix`. Notasi infix adalah notasi matematika yang biasa dibaca dan dapat diselesaikan oleh manusia, contoh `A + B`. Sedangkan notasi postfix adalah notasi matematika yang dapat dibaca dan diselesaikan oleh komputer, contoh `A B +`. Untuk mengubah notasi infix menjadi postfix salah satunya yaitu dengan cara menggunakan konsep stack. Contoh mengubah notasi infix `(A + B) * C - D` secara bertahap:

- Stack: (, Hasil:  
`(Setiap bertemu operator "(", masukkan saja langsung ke dalam stack).`
- Stack: (, Hasil: A  
`(Setiap operand, masukkan ke dalam hasil).`
- Stack: ( +, Hasil: A  
`(Untuk operator "+", masukkan ke dalam stack, karena top dari stack adalah operator "(").`
- Stack: ( +, Hasil: A B  
`(Setiap operand, masukkan ke dalam hasil).`
- Stack: , Hasil: A B +  
`(Untuk operator ")", keluarkan semua isi stack hingga bertemu "(").`
- Stack: *, Hasil: A B +  
`(Untuk operator "*", masukkan ke dalam stack).`
- Stack: *, Hasil: A B + C  
`(Setiap operand, masukkan ke dalam hasil).`
- Stack: -, Hasil: A B + C *  
`(Karena yang ingin diproses adalah operator, sedangkan di dalam stack terdapat operator lain, maka harus dilakukan perbandingan. Apabila operator yang ingin masuk derajatnya lebih besar dibandingkan top stack, maka masukkan ke dalam stack. Apabila sebaliknya, maka keluarkan top stack dan bandingkan kembali. Sehingga, operator "*" dikeluarkan dan operator "-" masuk ke dalam stack).`
- Stack: -, Hasil: A B + C * D  
`(Setiap operand, masukkan ke dalam hasil).`
- Stack: , Hasil: A B + C * D -  
`(Keluarkan semua isi stack apabila tidak ada lagi yang ingin diproses).`

### Implementasi ADT Stack (Linked List Based)

[Kode Lengkap Dapat Dilihat Disini](code/stack.cpp)

Implentasi stack dapat dilakukan dengan menggunakan Singly Linked List dengan mengubah head pada Singly Linked List menjadi Top.

_Kompleksitas waktu semua operasi pada stack dilakukan secara konstan O(1)._

- #### <b>Representasi Node</b>
  Setiap node pada stack dapat direpresentasikan oleh sebuah struct `StackNode` yang menyimpan tipe data `int` dan referensi pada node selanjutnya menggunakan pointer struct `StackNode` inu sendiri.

  ```c
  typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
  } StackNode;
  ```
- #### <b>Struktur Stack</b>
    Keseluruhan stack dapat direpresentasikan oleh sebuah struct `Stack` yang menyimpan referensi node yang berada pada top menggunakan pointer struct `StackNode` serta jumlah elemen yang berada pada node menggunakan `unsigned`.
    ```c
    typedef struct stack_t {
      StackNode *_top;
      unsigned _size;
    } Stack;
    ```
- #### <b>Fungsi isEmpty()</b>
  Fungsi ini digunakan untuk memeriksa apakah stack yang ada kosong atau tidak. Operasinya dilakukan dengan memeriksa apakah `top` dari stack tersebut bernilai `NULL` atau tidak.
  ```c
  bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
  }
  ```

- #### <b>Fungsi push()</b>
  Fungsi ini digunakan untuk menambahkan elemen baru pada stack. Operasinya dilakukan dengan tahap sebagai berikut:

  - Buat node baru dengan struct `StackNode`.
  - Jika stack sedang kosong, jadikan node baru ini sebagai `top`.
  - Jika tidak kosong, maka next dari node baru adalah `top` dan jadikan node baru sebagai `top`.

  ```c
  void stack_push(Stack *stack, int value)
  {
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
      stack->_size++;
      newNode->data = value;

      if (stack_isEmpty(stack)) newNode->next = NULL;
      else newNode->next = stack->_top;

      stack->_top = newNode;
    }
  }
  ```
- #### Fungsi pop()
  Fungsi ini digunakan untuk menghapus / mengambil node yang berada pada `top` stack. Operasinya dilakukan dengan tahap sebagai berikut:
  - Tampung `top` pada variabel sementara `temp`.
  - Mengganti `top` dengan referensi next dari `top`.
  - Menghapus variabel semetara sebelumnya.
  ```c
  void stack_pop(Stack *stack)
  {
    if (!stack_isEmpty(stack)) {
      StackNode *temp = stack->_top;
      stack->_top = stack->_top->next;
      free(temp);
      stack->_size--;
    }
  }
  ```

- #### Fungsi top()

  Fungsi ini digunakan untuk mendapatkan data top dari stack. Operasinya dilakukan dengan:

  - Apabila stack tidak kosong, maka return data `top`.
  - Apabila stack kosong, maka return 0.

  ```c
  int stack_top(Stack *stack)
  {
    if (!stack_isEmpty(stack))
      return stack->_top->data;
    return 0;
  }
  ```

## <b>Queue</b>
<a name="queue"></a>

### Terminologi
- `front` - merupakan node terdepan pada queue.
- `rear` - merupakan node terbelakang pada queue.
- `FIFO` - first in first out.

### Definisi
Queue adalah struktur data linear yang mengikuti prinsip FIFO. Pada queue, elemen pertama yang dimasukkan adalah elemen pertama yang dapat dikeluarkan. Setiap elemen pada queue selalu ditambahkan dari bagian belakang dan dikeluarkan dari bagian depan. Contoh penerapan dari queue dalam kehidupan sehari-hari adalah proses pengecekan STNK untuk keluar dari gerbang ITS :D.

![Contoh Queue](images/contoh-queue-basic.png)

### Aplikasi Queue
Queue biasa digunakan pada `BFS (Breadth First Search) Graph Traversal` yang nantinya akan dibahas pada modul 4-5 serta penyelesaian problem generate binary number dari 1 hingga n.

### Implementasi ADT Queue (Linked List Based)

[Kode Lengkap Dapat Dilihat Disini](code/queue.cpp)

Implementasi queue dapat dilakukan dengan menggunakan Singly Linked List dengan menggunakan pointer `rear` untuk menunjukkan node paling belakang dan `front` untuk menunjukkan node terdepan.

_Kompleksitas waktu semua operasi dilakukan secara konstan O(1)._

- #### <b>Representasi Node</b>
  Setiap node yang ada pada queue dapat direpresentasikan oleh sebuah struct `QueueNode` yang menyimpan data `int` dan refernsi node selanjutnya menggunakan pointer struct `QueueNode` ini sendiri.

  ```c
  typedef struct queueNode_t {
    int data;
    struct queueNode_t *next;
  } QueueNode;
  ```
- #### <b>Struktur Queue</b>
  Keseluruhan queue yang ada dikontrol oleh sebuah struct `Queue` yang menyimpan referensi node terdepan dan node terbelekang menggunakan pointer struct `QueueNode` serta data jumlah node yang ada pada queue menggunakan `unsigned`.
  ```c
  typedef struct queue_t {
    QueueNode   *_front, *_rear;
    unsigned _size;
  } Queue;
  ```

- #### <b>Fungsi isEmpty()</b>
  Fungsi ini diguakan untuk memeriksa apakah queue kosong atau tidak. Prosesnya dilakukan dengan memeriksa apakah pointer `front` atau `rear` bernilai `NULL` atau tidak.

  ```c
  bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
  }
  ```

- #### <b>Fungsi queue_push()</b>
  Fungsi ini digunakan untuk menambahkan data pada queue. Operasinya dilakukan melalui tahap sebagai berikut:
  - Buat node baru dengan struct `QueueNode`.
  - Jika queue kosong, jadikan node baru ini sebagai `front` dan `rear`.
  - Jika queue tidak kosong, maka next dari `rear` adalah node baru, dan jadikan node baru sebagai rear.
  ```c
  void queue_push(Queue *queue, int value) {
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
      queue->_size++;
      newNode->data = value;
      newNode->next = NULL;
      
      if (queue_isEmpty(queue))                 
        queue->_front = queue->_rear = newNode;
      else {
        queue->_rear->next = newNode;
        queue->_rear = newNode;
      }
    }
  }
  ```

- #### <b>Fungsi queue_pop()</b>
  Fungsi ini digunakan untuk menghapus/mengambil `node` terdepan dari queue. Operasinya dilakukan dengan tahap sebagai berikut:

  - Tampung `front` pada variabel sementara `temp`.
  - Mengganti `front` dengan referensi next dari `front`.
  - Menghapus variabel sementara sebelumnya.
  - Jika `front` kosong, maka `rear` juga kosong.

  ```c
  void queue_pop(Queue *queue) {
    if (!queue_isEmpty(queue)) {
      QueueNode *temp = queue->_front;
      queue->_front = queue->_front->next;
      free(temp);

      if (queue->_front == NULL)
        queue->_rear = NULL;
      queue->_size--;
    }
  }
  ```

- #### <b>Fungsi queue_front()</b>
  Fungsi ini digunakan untuk mengambil `data` terdepan dari queue. Operasinya dilakukan dengan tahap sebagai berikut:
  - Apabila queue tidak kosong, maka return data `front`.
  - Apabila queue kosong, maka return 0. 
  ```c
  int queue_front(Queue *queue) {
    if (!queue_isEmpty(queue)) {
      return (queue->_front->data);
    }
    return 0;
  }
  ```

## <b>Deque</b>
<a name="deque"></a>
### Terminologi
- `Head` - merupakan node pertama/paling depan dari deque.
- `Tail` - merupakan node terakhir/paling belakang dari deque.

### Definisi
Deque (Double-ended Queue) merupakan struktur data linear yang mirip dengan doubly linked list sekaligus variasi dari queue. Yang membedakan antara deque dan queue terletak pada posisi untuk menambah atau mengurangi data. Queue hanya dapat menambah data di belakang dan mengurangi data di depan, sementara deque dapat melakukan keduanya (menambah/mengurangi data di depan/belakang).

### Operasi Dasar
- `isEmpty` - untuk memeriksa apakah deque kosong atau tidak.
- `pushFront` - operasi untuk menambahkan data baru dari depan deque.
- `pushBack` - operasi untuk menambahkan data baru dari belakang deque.
- `front` - untuk memperoleh data yang berada pada paling depan.
- `back` - untuk memperoleh data yang berada pada paling belakang.
- `popFront` - operasi untuk menghapus data yang berada pada paling depan.
- `popBack` - operasi untuk menghapus data yang berada pada paling belakang.

Kompleksitas waktu semua operasi dilakukan secara konstan O(1).

### Aplikasi Deque
Deque umumnya digunakan untuk menyelesaikan problem dengan karakteristik Sliding Window. Pada problem Sliding Window, kita perlu untuk menghapus data dari depan dan belakang queue. Contoh problem Sliding Window adalah mencari nilai maksimum dari seluruh subarray dengan size tertentu.

### Implementasi ADT : `Deque`
[Link Implementasi Lengkap `Deque` dapat dilihat disini](code/deque.cpp)

![Contoh Deque](https://user-images.githubusercontent.com/83171211/189658945-13029da9-a032-4498-9637-0fd77248d3ac.png)

Implementasi deque dapat dilakukan dengan menggunakan Doubly Linked List dengan menggunakan pointer tail/rear untuk menunjukkan index paling belakang dan head/front untuk menunjukkan index terdepan pada deque.

- #### <b> Representasi Node </b>
Node dari Deque direpresentasikan oleh node bernama `DListNode` yang menyimpan data int dan referensi untuk node sebelum dan selanjutnya.
```c
typedef struct dnode_t {
    int data;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;
```

- #### <b> Struktur Deque </b>
Deque memiliki dua pointer referensi pada strukturnya yaitu `head` dan `tail`.
```c
typedef struct deque_t {
    DListNode           \
        *_head, 
        *_tail;
    unsigned _size;
} Deque;

```

- #### <b> isEmpty </b>
Untuk memeriksa apakah deque kosong, cukup dengan memeriksa apakah `tail` dan `tail` deque tersebut bernilai `NULL` atau tidak.
```c
bool deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && \
            deque->_tail == NULL);
}
```

- #### <b> pushFront </b>
Untuk melakukan pushFront, langkah-langkahnya adalah sebagai berikut.
- Buat node baru.
- Jika deque kosong, jadikan node baru sebagai `head` dan `tail`.
- Jika tidak kosong, maka buat next dari node baru ke `head` dan prev dari `head` ke node baru.
- Kemudian pindah `head` ke node baru.
```c
void deq_pushFront(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }
        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}
```

- #### <b> pushBack </b>
Untuk melakukan pushBack, langkah-langkahnya adalah sebagai berikut.
- Buat node baru.
- Jika deque kosong, jadikan node baru sebagai `head` dan `tail`.
- Jika tidak kosong, maka buat next dari node baru ke `tail` dan prev dari `tail` ke node baru.
- Kemudian pindah `tail` ke node baru.
```c
void deq_pushBack(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}
```
- #### <b> front </b>
```c
int deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}
```

- #### <b> rear </b>
```c
int deq_back(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_tail->data);
    }
    return 0;
}
```

- #### <b> popFront </b>
Untuk melakukan popFront, dilakukan langkah langkah berikut.
- Tampung `head` pada variabel `temp` (temporary).
- Mengganti `head` dengan referensi next dari `head`.
- Menghapus node `temp`.
- Jika `head` kosong, maka `tail` juga kosong.
```c
void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp = deque->_head;
        if (deque->_head == deque->_tail) {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}
```

- #### <b> popBack </b>
Untuk melakukan popBack, dilakukan langkah langkah berikut.
- Tampung `tail` pada variabel `temp` (temporary).
- Mengganti `tail` dengan referensi prev dari `tail`.
- Menghapus node `temp`.
- Jika `head` kosong, maka `tail` juga kosong.
```c
void deq_popBack(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp;
        if (deque->_head == deque->_tail) {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}
```

## <b>Priority Queue</b>
<a name="priority-queuek"></a>
### Terminologi
- `Top` - merupakan node yang mempunyai prioritas tertinggi pada priority queue.

### Definisi
Priority Queue adalah salah satu variasi queue yang cukup unik, karena priority queue secara default langsung mengurutkan data yang dimasukkan kedalamnya. Pada priority queue, data akan disusun berdasarkan prioritasnya secara urut, sehingga data yang pertama keluar merupakan data yang mempunyai prioritas tertinggi. Hal ini bisa dimanfaatkan untuk menyelesaikan masalah yang berhubungan dengan hal-hal yang memiliki prioritas berbeda-beda, tidak hanya sekedar push atau pop.

*Istilah "pqueue" akan digunakan untuk memperpendek penulisan "Priority queue".*

### Operasi Dasar
- `isEmpty` - untuk memeriksa apakah pqueue kosong atau tidak.
- `push` - untuk menambahkan data baru pada top pqueue.
- `pop` - untuk menghapus data yang berada pada top pqueue.
- `top/peek` - untuk memperoleh data yang berada pada top pqueue.

### Aplikasi Priority Queue
Priotiry Queue digunakan dalam menyelesaikan beberapa permasalahan sebagai berikut.

1. Penjadwalan pada CPU.
2. Algoritma graph seperti Dijkstra shortest path dan Prim Minimum Spanning Tree menggunakan struktur data priority queue.
3. Permasalahan pada queue yang melibatkan prioritas didalamnya.

### Implementasi ADT : *`PriorityQueue`*
[Link Implementasi Lengkap `PriorityQueue` dapat dilihat disini](code/priority_queue.cpp)

Implementasi yang disajikan disini adalah implementasi Min-Priority Queue, yakni memprioritaskan bilangan terkecil.

![Contoh Priority Deque](https://user-images.githubusercontent.com/83171211/189660126-bd97e1f7-8a68-4680-b689-278a9f63745a.png)

Implementasi paling sederhana dari pqueue dapat dilakukan dengan menggunakan Singly Linked List dengan menggunakan pointer top untuk menunjukkan data paling tinggi prioritasnya pada antrian.

*Catatan: Implementasi Priority Queue menggunakan Linked List bukanlah implementasi yang paling efisien. Jika ingin priority queue yang lebih efisien, dapat diimplementasikan menggunakan struktur data Heap Tree (yang pasti akan lebih kompleks).*

- #### <b> Representasi Node </b>
Priority Queue direpresentasikan oleh node bernama PqueueNode yang menyimpan data int dan referensi untuk node selanjutnya.
```c
typedef struct pqueueNode_t {
    int data;
    struct pqueueNode_t *next;
} PQueueNode;
```

- #### <b> Struktur PriorityQueue </b>
Priority Queue memiliki satu pointer referensi pada strukturnya yaitu top, untuk menunjukkan data yang paling tinggi prioritasnya.
```c
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;
```

- #### <b> isEmpty </b>
Untuk memeriksa apakah Priority Queue kosong, cukup dengan memeriksa apakah top Priority Queue tersebut bernilai `NULL` atau tidak.
```c
bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}
```

- #### <b> push </b>
Untuk melakukan push, langkah-langkahnya adalah sebagai berikut.
- Buat node temp (temporary) yang mengacu pada `top` pqueue.
- Buat node baru.
- Jika Priority Queue kosong, jadikan node baru sebagai `top`.
- Jika tidak kosong, masih terdapat 2 kasus.
**Kasus 1, data node baru lebih kecil dari top**
- Buat next node baru ke top pqueue.
- Pindah top pqueue ke node baru.
![Case-1](https://user-images.githubusercontent.com/83171211/189660169-9e26d817-de11-4801-b5e0-c2c2f4c6ea7a.png)
**Kasus 2, data node baru lebih besar dari top**
- Iterasi temp sampai data sebelum node baru tidak ada yang lebih besar.
- Atau sampai akhir dari pqueue (null).
- Arahkan next node baru ke next dari temp.
- Arahkan next dari temp ke node baru.
![Case-2](https://user-images.githubusercontent.com/83171211/189660234-2479ad73-2b95-4d80-8796-41d7b72ef9da.png)
```c
void pqueue_push(PriorityQueue *pqueue, int value)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;
    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }
    if (value < pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                temp->next->data < value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
```

- #### <b> pop </b>
Untuk melakukan pop, langkah-langkahnya adalah sebagai berikut.
- Memastikan Priority Queue tidak kosong.
- Membuat node temp (temporary) yang mengacu pada `top` pqueue.
- Memindah `top` pqueue ke node selanjutnya.
- Menghapus node temp yang telah dibuat sebelumnya.
```c
void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}
```

- #### <b> top </b>
```c
int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}
```

## <b>Dictionary</b>
<a name="dictionary"></a>
### Terminologi

- `Key` - Elemen unik yang digunakan untuk mengakses value dalam dictionary.
- `Value` - Data yang disimpan dan berasosiasi dengan key.

### Definisi
<p>Dictionary adalah struktur data yang digunakan untuk menyimpan pasangan data berupa key-value. Setiap key bersifat unik dan digunakan untuk mengakses value yang berhubungan.</p>

<img src="images/dictionary.png" width="500"/>

### Aplikasi
<p>Mencari nomor telepon berdasarkan nama adalah contoh nyata penggunaan dictionary. Misalnya, nomor telepon sebagaikan value dan nama seseorang sebagai key. </p>

Contoh:
| Nama (Key) | No Telp (Value) |
|:----------:|:---------------:|
|   "Anto"   |   081234567xx   |
|   "Budi"   |   082345678xx   |

1. <p>Misal saya ingin mencari nomor telepon Budi maka akan keluar 082345678xx</p>
2. <P>Kita juga dapat menambahkan nomor telepon baru dengan nama sebagai penanda misal Citra dengan nomor telepon 083456789xx.</p>

| Nama (Key) | No Telp (Value) |
|:----------:|:---------------:|
|   "Anto"   |   081234567xx   |
|   "Budi"   |   082345678xx   |
|   "Citra"  |   083456789xx   |

3. <p>Jika misal Citra mengganti nomor telepon, yang diperbarui hanya nomor teleponnya saja, sedangkan namanya tetap sama. </p>

| Nama (Key) | No Telp (Value) |
|:----------:|:---------------:|
|   "Anto"   |   081234567xx   |
|   "Budi"   |   082345678xx   |
|   "Citra"  |   084567890xx   |

4. <p>Jika hubungan pertemanan dengan Citra sudah berakhir, kita cukup menghapus namanya dari kontak, maka nomor teleponnya juga akan ikut terhapus.</p>

| Nama (Key) | No Telp (Value) |
|:----------:|:---------------:|
|   "Anto"   |   081234567xx   |
|   "Budi"   |   082345678xx   |

### Implementasi
<p>Dictionary dapat diimplementasikan secara manual menggunakan Array of Struct. Berikut adalah implementasi untuk setiap operasi dasar:</p>

[Kode Lengkap Dapat Dilihat Disini](code/dictionary.cpp)
- #### <b>Insert</b>
Menambahkan pasangan key-value ke dalam dictionary.
```cpp
void insert(Dictionary dict[], int &size, string key, string value) {
    dict[size++] = {key, value};
}
```
- #### <b>Update</b>
Memperbarui nilai yang terkait dengan key tertentu.

```cpp
void update(Dictionary dict[], int size, string key, string newValue) {
    for (int i = 0; i < size; i++) {
        if (dict[i].key == key) {
            dict[i].value = newValue;
            break;
        }
    }
}
```
- #### <b>Delete</b>
Menghapus pasangan key-value berdasarkan key tertentu.

```cpp
void remove(Dictionary dict[], int &size, string key) {
    for (int i = 0; i < size; i++) {
        if (dict[i].key == key) {
            dict[i] = dict[size-1];
            size--;
            break;
        }
    }
}
```
- #### <b>Search</b>
Mencari value berdasarkan key tertentu.

```cpp
void search(Dictionary dict[], int size, string key) {
    for (int i = 0; i < size; i++) {
        if (dict[i].key == key) {
            cout << "Key: " << dict[i].key << ", Value: " << dict[i].value << endl;
            return;
        }
    }
    cout << "Key tidak ditemukan" << endl;
}
```
## <b>Hashing</b>
<a name="hashing"></a>

### Terminologi

- Hash Table: Struktur data yang menyimpan pasangan kunci-nilai (key-value) untuk pencarian efisien.
- Hash Function: Fungsi yang mengubah kunci menjadi indeks array.
- Collision: Kejadian ketika dua kunci berbeda menghasilkan indeks yang sama.
- Chaining: Metode resolusi collision menggunakan linked list di setiap bucket.
- Load Factor: Rasio jumlah elemen terhadap ukuran tabel (count / size).

### Definisi

Hash Table adalah struktur data yang menggunakan hash function untuk memetakan kunci ke indeks dalam array, memungkinkan akses data dalam waktu rata-rata O(1). Jika terjadi collision (dua kunci berbeda diindeks ke posisi yang sama), teknik chaining digunakan untuk menyimpan beberapa elemen dalam satu bucket. Contoh penerapan dari hashtable yaitu database (cepat untuk mencari data), cache, atau penyimpanan password terenkripsi. 

Di C++, terdapat STL yang berbentuk Hash Table di std::unordered_map, tetapi itu tidak dipakai untuk sekarang.

![Contoh Hash Table](images/HashMap.png)

### Aplikasi Hash Table

Hash Table digunakan dalam berbagai aplikasi yang memerlukan pencarian cepat:

1. **Database Indexing** - Hash table dapat mempercepat pencarian record dalam database yang besar.
2. **Caching** - Browser dan sistem operasi menggunakan hash table untuk menyimpan cache.
3. **Implementasi Set dan Map** - Struktur data seperti HashSet dan HashMap diimplementasikan menggunakan hash table.
4. **Password Storage** - Password tidak disimpan secara langsung, melainkan dalam bentuk hash untuk keamanan.
5. **Compiler Operation** - Compiler menggunakan hash table untuk menyimpan identifier dari kode sumber.
6. **Spell Checking** - Aplikasi spell checker menggunakan hash table untuk menyimpan kamus kata.

Sebagai contoh, implementasi sederhana kamus kata menggunakan hash table:
```
Kata "apple" -> hash("apple") = 42 -> bucket[42] = "buah apel"
Kata "book" -> hash("book") = 17 -> bucket[17] = "buku"
Kata "pencil" -> hash("pencil") = 42 -> bucket[42] -> linked list -> "pensil"
```

### Contoh Implementasi

[code/hash_table.cpp](code/hash_table.cpp)

Implementasi hash table menggunakan metode chaining untuk menangani collision, di mana setiap bucket berisi linked list.

_Kompleksitas waktu operasi pada Hash Table: Average case O(1), Worst case O(n) ketika terjadi banyak collision._

#### Representasi Node

```c
typedef struct HashNode {
    int key;
    int value;
    struct HashNode *next;
} HashNode;
```

#### Struktur HashTable

```c
typedef struct HashTable {
    HashNode **buckets;  // Array of linked lists
    unsigned size;       // Ukuran array
    unsigned count;      // Jumlah elemen
} HashTable;
```

### Operasi

#### hash_init()
Fungsi ini digunakan untuk menginisialisasi hash table dengan ukuran tertentu. Semua bucket awalnya diatur ke NULL.

```c
void hash_init(HashTable *ht, unsigned size) {
    ht->size = size;
    ht->count = 0;
    ht->buckets = (HashNode**) malloc(size * sizeof(HashNode*));
    for (unsigned i = 0; i < size; i++) {
        ht->buckets[i] = NULL;
    }
}
```

#### hash_function()
Fungsi hash sederhana yang memetakan kunci ke indeks dengan operasi modulo.

```c
unsigned hash_function(HashTable *ht, int key) {
    return key % ht->size;
}
```

#### hash_insert()
Memasukkan pasangan key-value ke dalam hash table. Jika key sudah ada, nilai akan diperbarui.

```c
void hash_insert(HashTable *ht, int key, int value) {
    unsigned index = hash_function(ht, key);
    HashNode *current = ht->buckets[index];

    // Cek apakah kunci sudah ada
    while (current != NULL) {
        if (current->key == key) {
            current->value = value;  // Update nilai
            return;
        }
        current = current->next;
    }

    // Buat node baru
    HashNode *newNode = (HashNode*) malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = ht->buckets[index];  // Sisipkan di awal
    ht->buckets[index] = newNode;
    ht->count++;
}
```

#### hash_search()
Mencari nilai berdasarkan kunci tertentu dalam hash table.

```c
bool hash_search(HashTable *ht, int key, int *value) {
    unsigned index = hash_function(ht, key);
    HashNode *current = ht->buckets[index];
    
    while (current != NULL) {
        if (current->key == key) {
            *value = current->value;
            return true;  // Ditemukan
        }
        current = current->next;
    }
    return false;  // Tidak ditemukan
}
```

#### hash_delete()
Menghapus entri berdasarkan kunci dari hash table.

```c
void hash_delete(HashTable *ht, int key) {
    unsigned index = hash_function(ht, key);
    HashNode *current = ht->buckets[index];
    HashNode *prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                ht->buckets[index] = current->next;  // Hapus node pertama
            } else {
                prev->next = current->next;  // Hapus node tengah/akhir
            }
            free(current);
            ht->count--;
            return;
        }
        prev = current;
        current = current->next;
    }
}
```

#### hash_isEmpty()
Memeriksa apakah hash table kosong atau tidak.

```c
bool hash_isEmpty(HashTable *ht) {
    return (ht->count == 0);
}
```

### Contoh Penggunaan

```c
int main() {
    HashTable ht;
    hash_init(&ht, 10);  // Inisialisasi dengan 10 bucket

    // Memasukkan data
    hash_insert(&ht, 5, 100);
    hash_insert(&ht, 15, 200);  // Collision di bucket 5 (jika size=10)
    hash_insert(&ht, 25, 300);  // Collision lagi di bucket 5

    // Mencari data
    int value;
    if (hash_search(&ht, 15, &value)) {
        printf("Nilai untuk kunci 15: %d\n", value);  // Output: 200
    }
    
    // Menghapus data
    hash_delete(&ht, 15);
    
    // Mencari setelah dihapus
    if (!hash_search(&ht, 15, &value)) {
        printf("Kunci 15 telah dihapus\n");
    }
    
    return 0;
}
```