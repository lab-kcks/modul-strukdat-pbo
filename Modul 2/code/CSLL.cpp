/**
 * Implementasi ADT CircularSinglyList (Circular Singly Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Diubah oleh Daffa RP 
 * -- 7 Maret 2025
 * Struktur Data 2025
 * Implementasi untuk bahasa C++
 * 
 **/

#include <iostream>

using namespace std;

// Node class
class CListNode {
public:
    int data;
    CListNode *next;

    CListNode(int value) : data(value), next(nullptr) {}
};

// Circular Singly Linked List class
class CircularSinglyList {
private:
    CListNode *_head;
    unsigned _size;

public:
    CircularSinglyList() : _head(nullptr), _size(0) {}

    bool isEmpty() {
        return _head == nullptr;
    }

    void pushFront(int value) {
        CListNode *newNode = new CListNode(value);
        if (isEmpty()) {
            newNode->next = newNode; // Point to itself
            _head = newNode;
        } else {
            CListNode *tail = _head;
            while (tail->next != _head)
                tail = tail->next;
            newNode->next = _head;
            tail->next = newNode;
            _head = newNode;
        }
        _size++;
    }

    void pushBack(int value) {
        CListNode *newNode = new CListNode(value);
        if (isEmpty()) {
            newNode->next = newNode;
            _head = newNode;
        } else {
            CListNode *tail = _head;
            while (tail->next != _head)
                tail = tail->next;
            tail->next = newNode;
            newNode->next = _head;
        }
        _size++;
    }

    void popAt(int index) {
        if (!isEmpty() && index < _size) {
            _size--;
            CListNode *temp = _head, *prev = nullptr;

            if (index == 0) {
                CListNode *tail = _head;
                while (tail->next != _head)
                    tail = tail->next;
                _head = _head->next;
                tail->next = _head;
                delete temp;
            } else {
                for (int i = 0; i < index; i++) {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = temp->next;
                delete temp;
            }
        }
    }

    void insertAt(int index, int value) {
        if (isEmpty() || index >= _size) {
            pushBack(value);
        } else if (index == 0) {
            pushFront(value);
        } else {
            CListNode *newNode = new CListNode(value);
            CListNode *temp = _head;
            for (int i = 0; i < index - 1; i++)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
            _size++;
        }
    }

    void traverse() {
        if (!isEmpty()) {
            CListNode *temp = _head;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != _head);
            cout << endl;
        }
    }
};

int main() {
    CircularSinglyList myList;

    myList.pushBack(2);
    myList.pushBack(3);
    myList.pushBack(4);
    myList.pushBack(5);
    myList.pushBack(6);
    myList.traverse();

    myList.pushFront(9);
    myList.pushFront(8);
    myList.pushFront(7);
    myList.pushFront(6);
    myList.traverse();

    myList.popAt(3);
    myList.traverse();

    myList.insertAt(2, 99);
    myList.traverse();

    return 0;
}
