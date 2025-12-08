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

    bool isEmpty() {
        return (_front == nullptr && _rear == nullptr);
    }

    void pushFront(int value) {
        QueueNode* newNode = new QueueNode(value);
        if (isEmpty()) {
            _front = _rear = newNode;
        } else {
            newNode->next = _front;
            _front = newNode;
        }
        _size++;
    }

    int popFront() {
        if (isEmpty()) return -1;
        
        QueueNode* temp = _front;
        int value = temp->data;
        
        if (_front == _rear) {
            _front = _rear = nullptr;
        } else {
            _front = _front->next;
        }
        
        delete temp;
        _size--;
        return value;
    }

    void pushMid(int value) {
        if (isEmpty()) {
            pushFront(value);
            return;
        }
        
        QueueNode* newNode = new QueueNode(value);
        if (_size == 1) {
            _front->next = newNode;
            _rear = newNode;
            _size++;
            return;
        }

        QueueNode* slow = _front;
        int midPos = (_size % 2 == 0) ? (_size / 2) : ((_size + 1) / 2);
        
        for (int i = 1; i < midPos; i++) {
            slow = slow->next;
        }
        
        newNode->next = slow->next;
        slow->next = newNode;
        _size++;
    }

    int popMid() {
        if (isEmpty()) return -1;
        if (_size == 1) return popFront();
        
        int midPos = (_size % 2 == 0) ? (_size / 2) : ((_size + 1) / 2);
        QueueNode* curr = _front;
        QueueNode* prev = nullptr;
        
        for (int i = 1; i < midPos; i++) {
            prev = curr;
            curr = curr->next;
        }
        
        int value = curr->data;
        if (prev) {
            prev->next = curr->next;
            if (curr == _rear) {
                _rear = prev;
            }
        } else {
            _front = curr->next;
        }
        
        delete curr;
        _size--;
        return value;
    }

    void pushBack(int value) {
        QueueNode* newNode = new QueueNode(value);
        if (isEmpty()) {
            _front = _rear = newNode;
        } else {
            _rear->next = newNode;
            _rear = newNode;
        }
        _size++;
    }

    int popBack() {
        if (isEmpty()) return -1;
        if (_front == _rear) return popFront();
        
        QueueNode* curr = _front;
        while (curr->next != _rear) {
            curr = curr->next;
        }
        
        int value = _rear->data;
        delete _rear;
        _rear = curr;
        _rear->next = nullptr;
        _size--;
        return value;
    }

    void display() {
        if (isEmpty()) {
            cout << "no notes exist, create some maybe" << endl;
            return;
        }
        
        QueueNode* current = _front;
        cout << "Chart view - ";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << ",";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[]) {
    Queue q;
    string operation;
    
    while (cin >> operation) {
        if (operation == "break") {
            break;
        }
        else if (operation == "chart") {
            q.display();
        }
        else if (operation == "slideend" || operation == "slidestart" || operation == "slidecenter") {
            int N;
            cin >> N;
            for (int i = 0; i < N; i++) {
                int value;
                cin >> value;
                if (operation == "slideend") q.pushBack(value);
                else if (operation == "slidestart") q.pushFront(value);
                else if (operation == "slidecenter") q.pushMid(value);
            }
        }
        else if (operation == "hold" || operation == "tap" || operation == "touch") {
            int N;
            cin >> N;
            for (int i = 0; i < N; i++) {
                int result;
                if (operation == "hold") result = q.popBack();
                else if (operation == "tap") result = q.popFront();
                else if (operation == "touch") result = q.popMid();
                
                if (result == -1) cout << "no notes exist, create some maybe" << endl;
            }
        }
        else {
            cout << "what's that? try adding breaks" << endl;
        }
    }
    
    return 0;
}