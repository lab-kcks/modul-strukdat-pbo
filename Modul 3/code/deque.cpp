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

    return 0;
}