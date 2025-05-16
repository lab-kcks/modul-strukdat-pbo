/**
 * Implementasi ADT Deque (Double-ended Queue)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019 
 * Diubah oleh Steven Figo
 * -- tanggal 3 Maret 2025
 * Struktur Data & Pemorograman Berorientasi Objek 2025
 * Implementasi untuk bahasa C++
 * 
 */

#include <iostream>

using namespace std;

// Node structure
class Deque {
private:
    struct DListNode {
        int data;
        DListNode *next, *prev;
        DListNode(int value) : data(value), next(nullptr), prev(nullptr) {}
    };
    
    DListNode *_head, *_tail;
    unsigned _size;

// Methods
public:
    Deque() {
        _head = _tail = nullptr;
        _size = 0;
    }

    bool isEmpty() {
        return (_head == nullptr && _tail == nullptr);
    }

    void pushFront(int value) {
        DListNode *newNode = new DListNode(value);
        if (isEmpty()) {
            _head = _tail = newNode;
        } else {
            newNode->next = _head;
            _head->prev = newNode;
            _head = newNode;
        }
        _size++;
    }

    void pushBack(int value) {
        DListNode *newNode = new DListNode(value);
        if (isEmpty()) {
            _head = _tail = newNode;
        } else {
            _tail->next = newNode;
            newNode->prev = _tail;
            _tail = newNode;
        }
        _size++;
    }

    int front() {
        if (!isEmpty())
            return _head->data;
        throw runtime_error("Deque kosong");
    }

    int back() {
        if (!isEmpty())
            return _tail->data;
        throw runtime_error("Deque kosong");
    }

    void popFront() {
        if (isEmpty()) throw runtime_error("Deque kosong");
        DListNode *temp = _head;
        if (_head == _tail) {
            _head = _tail = nullptr;
        } else {
            _head = _head->next;
            _head->prev = nullptr;
        }
        delete temp;
        _size--;
    }

    void popBack() {
        if (isEmpty()) throw runtime_error("Deque kosong");
        DListNode *temp = _tail;
        if (_head == _tail) {
            _head = _tail = nullptr;
        } else {
            _tail = _tail->prev;
            _tail->next = nullptr;
        }
        delete temp;
        _size--;
    }

    unsigned size() {
        return _size;
    }
};


int main() {
    Deque dq;

    // masukkan perintah di sini dengan memanggil fungsi-fungsi yang ada di ADT Deque
    // dq.{fungsi}

    // Isi deque dengan 1, 2, 3, 4, 5
    dq.pushBack(1);
    dq.pushBack(2);
    dq.pushBack(3);
    dq.pushBack(4);
    dq.pushBack(5);

    // dq front menapilkan elemen pertama
    cout << dq.front() << endl;
    
    // dq back menampilkan elemen terakhir
    cout << dq.back() << endl;

    // Cetak isi deque
    while (!dq.isEmpty()) {
        printf("%d ", dq.front());
        dq.popFront();
        // hasilnya 1 2 3 4 5
    }
    puts("");

    // Isi deque dengan 6, 7, 8, 9
    dq.pushFront(9);
    dq.pushFront(8);
    dq.pushFront(7);
    dq.pushFront(6);
    
    // Cetak isi deque balik
    while (!dq.isEmpty()) {
        printf("%d ", dq.back());
        dq.popBack();
        // hasilnya 9 8 7 6
    }
    puts("");

    return 0;
}