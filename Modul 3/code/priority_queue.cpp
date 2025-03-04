/**
 * Implementasi ADT PriorityQueue menggunakan Linked List
 * [default: minimum priority]
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
class PriorityQueue {
private:
    struct PQueueNode {
        int data;
        PQueueNode *next;
        PQueueNode(int value) : data(value), next(nullptr) {}
    };

    PQueueNode *_top;
    unsigned _size;

// Methods
public:
    PriorityQueue() {
        _top = nullptr;
        _size = 0;
    }

    ~PriorityQueue() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return (_top == nullptr);
    }

    void push(int value) {
        PQueueNode *newNode = new PQueueNode(value);
        _size++;

        if (isEmpty()) {
            _top = newNode;
            return;
        }

        if (value < _top->data) {
            newNode->next = _top;
            _top = newNode;
        } else {
            PQueueNode *temp = _top;
            while (temp->next != nullptr && temp->next->data < value) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void pop() {
        if (!isEmpty()) {
            PQueueNode *temp = _top;
            _top = _top->next;
            delete temp;
            _size--;
        }
    }

    int top() {
        if (!isEmpty())
            return _top->data;
        throw runtime_error("PriorityQueue kosong");
    }

    unsigned size() {
        return _size;
    }
};

int main() {
    PriorityQueue pq;

    // masukkan perintah di sini dengan memanggil fungsi-fungsi yang ada di ADT PriorityQueue
    // pq.{fungsi}

    return 0;
}