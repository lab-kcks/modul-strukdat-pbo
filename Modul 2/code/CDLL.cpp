#include <iostream>

using namespace std;

// Node structure
struct CDListNode {
    int data;
    CDListNode *next, *prev;
};

/* Struktur Circular Doubly Linked List */
struct CircularDoublyList {
    CDListNode *_head;
    unsigned _size;

    void init() {
        _head = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_head == NULL);
    }

    void pushFront(int value) {
        CDListNode *newNode = (CDListNode*) malloc(sizeof(CDListNode));
        if (newNode) {
            _size++;
            newNode->data = value;
            
            if (isEmpty()) {
                newNode->next = newNode;
                newNode->prev = newNode;
                _head = newNode;
            } else {
                CDListNode *tail = _head->prev;
                newNode->next = _head;
                newNode->prev = tail;
                _head->prev = newNode;
                tail->next = newNode;
                _head = newNode;
            }
        }
    }

    void pushBack(int value) {
        CDListNode *newNode = (CDListNode*) malloc(sizeof(CDListNode));
        if (newNode) {
            _size++;
            newNode->data = value;
            
            if (isEmpty()) {
                newNode->next = newNode;
                newNode->prev = newNode;
                _head = newNode;
            } else {
                CDListNode *tail = _head->prev;
                newNode->next = _head;
                newNode->prev = tail;
                tail->next = newNode;
                _head->prev = newNode;
            }
        }
    }

    void popAt(int index) {
        if (!isEmpty() && index < _size) {
            _size--;
            CDListNode *temp = _head;
            
            if (index == 0) {
                CDListNode *tail = _head->prev;
                _head = _head->next;
                _head->prev = tail;
                tail->next = _head;
                free(temp);
            } else {
                for (int i = 0; i < index; i++) 
                    temp = temp->next;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
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
            CDListNode *newNode = (CDListNode*) malloc(sizeof(CDListNode));
            if (newNode) {
                CDListNode *temp = _head;
                for (int i = 0; i < index - 1; i++) 
                    temp = temp->next;
                newNode->data = value;
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
                _size++;
            }
        }
    }

    void traverseForward() {
        if (!isEmpty()) {
            CDListNode *temp = _head;
            do {
                printf("%d ", temp->data);
                temp = temp->next;
            } while (temp != _head);
            printf("\n");
        }
    }

    void traverseBackward() {
        if (!isEmpty()) {
            CDListNode *temp = _head->prev;
            do {
                printf("%d ", temp->data);
                temp = temp->prev;
            } while (temp != _head->prev);
            printf("\n");
        }
    }
};

int main(int argc, char const *argv[]) {
    CircularDoublyList myList;
    myList.init();
    
    myList.pushBack(2);
    myList.pushBack(3);
    myList.pushBack(4);
    myList.pushBack(5);
    myList.pushBack(6);
    
    myList.traverseForward();
    
    myList.pushFront(9);
    myList.pushFront(8);
    myList.pushFront(7);
    myList.pushFront(6);
    
    myList.traverseForward();
    
    myList.popAt(3);
    myList.traverseForward();
    
    myList.insertAt(2, 99);
    myList.traverseForward();
    
    printf("Traversing backward:\n");
    myList.traverseBackward();
    
    return 0;
}
