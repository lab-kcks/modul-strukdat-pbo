#include <iostream>  
using namespace std;  

class DanceNode {  
public:  
     
};  

class TikTokCarousel {  
private:  
    

public:  
    TikTokCarousel() : _head(nullptr), _size(0) {}  

    bool isEmpty() { /* Implementasi */ }  
    void addFront(int value) { /* Tambah di depan */ }  
    void addBack(int value) { /* Tambah di belakang */ }  
    void del(int index) { /* Hapus gerakan */ }  
    void insert(int index, int value) { /* Sisipkan gerakan */ }  
    void play() { /* Traversal maju */ }  
    void rewind() { /* Traversal mundur */ }  
};  

// Your Code Here


Solver

Solver
#include <iostream>
using namespace std;

class DanceNode {
public:
    int gerakan;
    DanceNode *next, *prev;
    DanceNode(int value) : gerakan(value), next(nullptr), prev(nullptr) {}
};

class TikTokCarousel {
private:
    DanceNode* _head;
    unsigned _size;

public:
    TikTokCarousel() : _head(nullptr), _size(0) {}

    bool isEmpty() {
        return _head == nullptr;
    }

    void addFront(int value) {
        if (value < 1 || value > 1000) {
            cout << "FAIL" << endl;
            return;
        }
        DanceNode* newNode = new DanceNode(value);
        if (isEmpty()) {
            newNode->next = newNode;
            newNode->prev = newNode;
            _head = newNode;
        } else {
            DanceNode* tail = _head->prev;
            newNode->next = _head;
            newNode->prev = tail;
            tail->next = newNode;
            _head->prev = newNode;
            _head = newNode;
        }
        _size++;
    }

    void addBack(int value) {
        if (value < 1 || value > 1000) {
            cout << "FAIL" << endl;
            return;
        }
        DanceNode* newNode = new DanceNode(value);
        if (isEmpty()) {
            newNode->next = newNode;
            newNode->prev = newNode;
            _head = newNode;
        } else {
            DanceNode* tail = _head->prev;
            newNode->next = _head;
            newNode->prev = tail;
            tail->next = newNode;
            _head->prev = newNode;
        }
        _size++;
    }

    void del(int index) {
        if (isEmpty() || index >= _size) {
            cout << "FAIL" << endl;
            return;
        }
        if (_size == 1) {
            delete _head;
            _head = nullptr;
        } else {
            DanceNode* temp = _head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            if (temp == _head) {
                _head = _head->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        _size--;
    }

    void insert(int index, int value) {
        if (value < 1 || value > 1000 || index > _size) {
            cout << "FAIL" << endl;
            return;
        }
        if (index == 0) {
            addFront(value);
            return;
        } else if (index == _size) {
            addBack(value);
            return;
        }
        DanceNode* newNode = new DanceNode(value);
        DanceNode* temp = _head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        _size++;
    }

    void play() {
        if (isEmpty()) {
            cout << "FAIL" << endl;
            return;
        }
        DanceNode* temp = _head;
        do {
            cout << temp->gerakan << " ";
            temp = temp->next;
        } while (temp != _head);
        cout << endl;
    }

    void rewind() {
        if (isEmpty()) {
            cout << "FAIL" << endl;
            return;
        }
        DanceNode* temp = _head->prev;
        do {
            cout << temp->gerakan << " ";
            temp = temp->prev;
        } while (temp != _head->prev);
        cout << endl;
    }
};

int main() {
    TikTokCarousel challenge;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "ADD_FRONT") {
            int val;
            cin >> val;
            challenge.addFront(val);
        }
        else if (cmd == "ADD_BACK") {
            int val;
            cin >> val;
            challenge.addBack(val);
        }
        else if (cmd == "DEL") {
            int index;
            cin >> index;
            challenge.del(index);
        }
        else if (cmd == "INSERT") {
            int index, val;
            cin >> index >> val;
            challenge.insert(index, val);
        }
        else if (cmd == "PLAY") {
            challenge.play();
        }
        else if (cmd == "REWIND") {
            challenge.rewind();
        }
        else if (cmd == "DONE") {
            cout << "Challenge selesai!\n";
            break;
        }
    }
    return 0;
}

