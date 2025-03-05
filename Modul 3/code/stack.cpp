/**
 * Implementasi ADT Stack (Stack menggunakan Linked List)
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

// Stack class using Linked List
class Stack {
private:
    // Node structure
    struct StackNode {
        int data;
        StackNode *next;
        StackNode(int value) : data(value), next(nullptr) {}
    };

    StackNode *_top;
    unsigned _size;

public:
    // Constructor
    Stack() {
        _top = nullptr;
        _size = 0;
    }

    // Destructor
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return (_top == nullptr);
    }

    void push(int value) {
        StackNode *newNode = new StackNode(value);
        if (newNode) {
            _size++;
            if (isEmpty()) newNode->next = nullptr;
            else newNode->next = _top;
            _top = newNode;
        }
    }

    void pop() {
        if (!isEmpty()) {
            StackNode *temp = _top;
            _top = _top->next;
            delete temp;
            _size--;
        }
    }

    int top() {
        if (!isEmpty())
            return _top->data;
        throw runtime_error("Stack kosong");
    }

    unsigned size() {
        return _size;
    }
};

int main(int argc, char const *argv[])
{
    // Buat objek stack
    Stack myStack;

    myStack.push(63);
    myStack.push(75);
    myStack.push(12);
    myStack.push(24);

    // Cetak isi stack
    while (!myStack.isEmpty()) {
        printf("%d ", myStack.top());
        myStack.pop();
    }
    puts("");
    return 0;
}