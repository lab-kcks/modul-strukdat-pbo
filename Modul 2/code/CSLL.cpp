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
 */

#include <iostream>

using namespace std;

// Node structure
struct CListNode 
{
    int data;
    CListNode *next;
}; 

/* Struktur Circular Singly Linked List */
struct CircularSinglyList
{
    CListNode *_head;
    unsigned _size;

    void init() {
        _head = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_head == NULL);
    }

    void pushFront(int value) {
        CListNode *newNode = (CListNode*) malloc(sizeof(CListNode));
        if (newNode) {
            _size++;
            newNode->data = value;
            
            if (isEmpty()) {
                newNode->next = newNode; // Point to itself
                _head = newNode;
            } else {
                CListNode *temp = _head;
                while (temp->next != _head) 
                    temp = temp->next;
                temp->next = newNode;
                newNode->next = _head;
                _head = newNode;
            }
        }
    }

    void pushBack(int value) {
        CListNode *newNode = (CListNode*) malloc(sizeof(CListNode));
        if (newNode) {
            _size++;
            newNode->data = value;
            
            if (isEmpty()) {
                newNode->next = newNode;
                _head = newNode;
            } else {
                CListNode *temp = _head;
                while (temp->next != _head) 
                    temp = temp->next;
                temp->next = newNode;
                newNode->next = _head;
            }
        }
    }

    void popAt(int index) {
        if (!isEmpty() && index < _size) {
            _size--;
            CListNode *temp = _head, *prev = NULL;
            
            if (index == 0) {
                while (temp->next != _head) 
                    temp = temp->next;
                CListNode *toDelete = _head;
                _head = _head->next;
                temp->next = _head;
                free(toDelete);
            } else {
                for (int i = 0; i < index; i++) {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = temp->next;
                free(temp);
            }
        }
    }

    void insertAt(int index, int value) {
        if (isEmpty() || index >= _size) {
            pushBack(value);
        } else if (index == 0) {
            pushFront(value);
        } else {
            CListNode *newNode = (CListNode*) malloc(sizeof(CListNode));
            if (newNode) {
                CListNode *temp = _head;
                for (int i = 0; i < index - 1; i++) 
                    temp = temp->next;
                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;
                _size++;
            }
        }
    }

    void traverse() {
        if (!isEmpty()) {
            CListNode *temp = _head;
            do {
                printf("%d ", temp->data);
                temp = temp->next;
            } while (temp != _head);
            printf("\n");
        }
    }
};

int main(int argc, char const *argv[]) {
    CircularSinglyList myList;
    myList.init();
    
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
