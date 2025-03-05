/**
 * Implementasi ADT Queue (Queue menggunakan Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Diubah oleh Nathan Kho Pancras
 * -- tanggal 5 Maret 2025
 * Struktur Data & Pemorograman Berorientasi Objek 2025
 * Implementasi untuk bahasa C++
 * 
 */

#include <iostream>
using namespace std;

// Queue class using Linked List
class Queue {
private:
    // Node Structure
    struct QueueNode {
        int data;
        QueueNode *next;
        QueueNode(int value) : data(value), next(nullptr) {}
    };

    QueueNode *_front, *_rear;
    unsigned _size;

public:
    // Constructor
    Queue() {
        _size = 0;
        _front = nullptr;
        _rear = nullptr;
    }

    // Destructor
    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return (_front == nullptr && _rear == nullptr);
    }

    void push(int value) {
        QueueNode *newNode = new QueueNode(value);
        _size++;
        
        if (isEmpty())                 
            _front = _rear = newNode;
        else {
            _rear->next = newNode;
            _rear = newNode;
        }
    }

    void pop() {
        if (!isEmpty()) {
            QueueNode *temp = _front;
            _front = _front->next;
            delete temp;
            
            if (_front == nullptr)
                _rear = nullptr;
            _size--;
        }
    }

    int front() {
        if (!isEmpty())
            return _front->data;
        throw runtime_error("Queue kosong");
    }

    unsigned size() {
        return _size;
    }
};

int main(int argc, char const *argv[])
{
    // Buat objek queue
    Queue myQueue;

    myQueue.push(23);
    myQueue.push(11);
    myQueue.push(3);
    myQueue.push(35);

    // Cetak isi queue
    while (!myQueue.isEmpty()) {
        printf("%d ", myQueue.front());
        myQueue.pop();
    }
    puts("");
    return 0;
}