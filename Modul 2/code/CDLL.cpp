#include <iostream>

using namespace std;

// Node class
class CDListNode {
public:
    int data;
    CDListNode *next, *prev;

    CDListNode(int value) {
        data = value;
        next = prev = nullptr;
    }
};

// Circular Doubly Linked List class
class CircularDoublyList {
private:
    CDListNode *_head;
    unsigned _size;

public:
    CircularDoublyList() {
        _head = nullptr;
        _size = 0;
    }

    bool isEmpty() {
        return (_head == nullptr);
    }

    void pushFront(int value) {
        CDListNode *newNode = new CDListNode(value);
        if (newNode) {
            _size++;
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
        CDListNode *newNode = new CDListNode(value);
        if (newNode) {
            _size++;
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
                delete temp;
            } else {
                for (int i = 0; i < index; i++)
                    temp = temp->next;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
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
            CDListNode *newNode = new CDListNode(value);
            if (newNode) {
                CDListNode *temp = _head;
                for (int i = 0; i < index - 1; i++)
                    temp = temp->next;
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
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != _head);
            cout << endl;
        }
    }

    void traverseBackward() {
        if (!isEmpty()) {
            CDListNode *temp = _head->prev;
            do {
                cout << temp->data << " ";
                temp = temp->prev;
            } while (temp != _head->prev);
            cout << endl;
        }
    }
};

int main() {
    CircularDoublyList myList;

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

    cout << "Traversing backward:" << endl;
    myList.traverseBackward();

    return 0;
}
