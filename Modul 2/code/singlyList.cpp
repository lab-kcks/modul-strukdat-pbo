/**
 * Implementasi ADT SInglyList (Singly Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Diubah oleh Acintya Edria Sudarsono
 * -- 7 Maret 2025
 * Struktur Data 2025
 * Implementasi untuk bahasa C++
 * 
 */

#include <iostream>
using namespace std;

// Struktur Single Linked List
class SListNode {
public:
    int data;
    SListNode* next;
    
    SListNode(int value) {
        data = value;
        next = nullptr;
    }
};


class SinglyList {
private:
    SListNode* head;
    unsigned size;

public:
    SinglyList() {
        head = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    /* pushFront
        Untuk melakukan pushFront, langkah-langkahnya adalah sebagai berikut.
        1. Membuat node baru.
        2. Jika list kosong, jadikan node baru sebagai head.
        3. Jika tidak kosong, maka next dari node baru adalah head.
    */
    void pushFront(int value) {
        SListNode* newNode = new SListNode(value);
        if (isEmpty()) newNode->next = nullptr;
        else newNode->next = head;
        head = newNode;
        size++;
    }

    /* pushBack
        Secara umum langkah-langkah untuk melakukan pushBack adalah sebagai berikut.
        1. Membuat node baru.
        2. Jika list kosong, maka sudah jelas bahwa head-nya adalah node baru tadi.
        3. Jika tidak kosong, telusuri hingga paling belakang,
           kemudian node paling belakang diarahkan kepada node baru.
           Penelusuran dilakukan dengan bantuan variabel temporary temp.
     */
    void pushBack(int value) {
        SListNode* newNode = new SListNode(value);
        if (isEmpty()) {
            head = newNode;
        } else {
            SListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    /* popFront
        Operasi popFront dapat dilakukan dengan :
        1. Tampung head pada variabel temp (temporary).
        2. Mengganti head dengan referensi/next dari head.
        3. Menghapus node temp.
    */
    void popFront() {
        if (!isEmpty()) {
            SListNode* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }

    /* popBack
        Untuk melakukan operasi popBack, dapat dilakukan dengan:
        1. Melakukan penelusuran dengan bantuan dua node, yakni nextNode dan currNode.
        2. Jika next dari currNode kosong, maka artinya jumlah data hanya satu. Hapus langsung node tersebut.
        3. Lakukan penelusuran hingga akhir.
        4. Saat sampai akhir, hilangkan referensi dari node sekarang (currNode).
        5. Hapus node selanjutnya (nextNode).
    */
    void popBack() {
        if (!isEmpty()) {
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
            } else {
                SListNode* temp = head;
                while (temp->next->next != nullptr) {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = nullptr;
            }
            size--;
        }
    }

    /* insertAt
        Operasi insertAt mempunyai proses yang cukup rumit. Terdapat beberapa kasus yang harus diperhatikan.
        Kasus 1: index 0 -> Cukup melakukan pushFront.
        Kasus 2: index berada di akhir -> Cukup melakukan pushBack.
        Kasus 3: index berada di tengah:
           1. Buat node baru.
           2. Dengan bantuan variabel temp, lakukan penelusuran hingga mencapai posisi index - 1.
           3. Arahkan next dari node baru menuju node selanjutnya dari node hasil penelusuran.
           4. Sambungkan node hasil penelusuran menuju node baru.
    */
    void insertAt(int index, int value) {
        if (isEmpty() || index >= size) {
            pushBack(value);
            return;
        } else if (index == 0) {
            pushFront(value);
            return;
        }

        SListNode* newNode = new SListNode(value);
        SListNode* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    // Menghapus elemen pada posisi tertentu
    void removeAt(int index) {
        if (!isEmpty()) {
            /* Kasus apabila posisinya melebihi batas */
            if (index >= size) {
                popBack();
                return;
            } else if (index == 0) {
                popFront();
                return;
            }

            SListNode* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            SListNode* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            size--;
        }
    }

    /*Menghapus elemen pertama yang memiliki nilai tertentu
    1. Cek apakah list kosong
    2. Jika Jika nilai yang ingin dihapus berada di node pertama (head), maka cukup panggil popFront() untuk menghapusnya.
    3. Jika tidak, lakukan penelusuran hingga menemukan node yang memiliki nilai yang sama dengan value.
    4. Jika nilai tidak ditemukan, keluar dari fungsi
    5. Jika ditemukan, hapus node tersebut.
    */
    void remove(int value) {
        if (!isEmpty()) {
            if (head->data == value) {
                popFront();
                return;
            }
            SListNode* temp = head;
            SListNode* prev = nullptr;
            while (temp != nullptr && temp->data != value) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == nullptr) return;
            prev->next = temp->next;
            delete temp;
            size--;
        }
    }

    /* front
        Untuk mendapatkan elemen pertama pada list, cukup dengan mengembalikan data dari head.
        Namun, perlu diperhatikan bahwa jika list kosong, maka kembalikan -1.
    */
    int front() {
        return isEmpty() ? exit(-1), 0 : head->data;
    }

    /*Cukup dengan menelusuri hingga paling akhir dan return nilainya. */
    int back() {
        if (isEmpty()) exit(-1);
        SListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }

    // Mendapatkan elemen pada index tertentu
    int getAt(int index) {
        if (isEmpty() || index >= size) exit(-1);
        SListNode* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    // Ukuran list
    unsigned getSize() {
        return size;
    }
};

int main() {
    SinglyList myList;
    
    myList.pushBack(2);
    myList.pushBack(3);
    myList.pushBack(4);
    myList.pushBack(5);
    myList.pushBack(6);
    // isi list => [2, 3, 4, 5, 6]
    
    myList.pushFront(9);
    myList.pushFront(8);
    myList.pushFront(7);
    myList.pushFront(6);
    // isi list => [6, 7, 8, 9, 2, 3, 4, 5, 6]
    
    // print isi list dari depan ke belakang
    for (int i = 0; i < myList.getSize(); i++) {
        cout << myList.getAt(i) << " ";
    }
    cout << endl;
    
    myList.popFront();
    myList.popBack();
    myList.insertAt(2, 11);
    myList.insertAt(4, 17);
    // isi list => [7, 8, 11, 9, 17, 2, 3, 4, 5]
    
    myList.removeAt(1);
    myList.remove(3);
    // isi list => [7, 11, 9, 17, 2, 4, 5]
    
    // print list reversed
    while (!myList.isEmpty()) {
        cout << myList.back() << " ";
        myList.popBack();
    }
    cout << endl;
    return 0;
}
