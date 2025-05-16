#include <iostream>  
using namespace std;  

class TimeNode {  
public:  
    int peristiwa;  
    TimeNode* next;  
    TimeNode(int value) : peristiwa(value), next(nullptr) {}  
};  

class TimeCircularList {  
private:  
    TimeNode* _head;  
    unsigned _size;  

public:  
    TimeCircularList() : _head(nullptr), _size(0) {}  

    bool isEmpty() {  
        return _head == nullptr;  
    }  

    void tambahDepan(int value) {  
        if (value < 1 || value > 1000) {  
            cout << "Operasi gagal" << endl;  
            return;  
        }  
        TimeNode* newNode = new TimeNode(value);  
        if (isEmpty()) {  
            newNode->next = newNode;  
            _head = newNode;  
        } else {  
            TimeNode* tail = _head;  
            while (tail->next != _head)  
                tail = tail->next;  
            newNode->next = _head;  
            tail->next = newNode;  
            _head = newNode;  
        }  
        _size++;  
    }  

    void tambahBelakang(int value) {  
        if (value < 1 || value > 1000) {  
            cout << "Operasi gagal" << endl;  
            return;  
        }  
        TimeNode* newNode = new TimeNode(value);  
        if (isEmpty()) {  
            newNode->next = newNode;  
            _head = newNode;  
        } else {  
            TimeNode* tail = _head;  
            while (tail->next != _head)  
                tail = tail->next;  
            tail->next = newNode;  
            newNode->next = _head;  
        }  
        _size++;  
    }  

    void hapus(int index) {  
        if (isEmpty() || index < 0 || static_cast<unsigned>(index) >= _size) {  
            cout << "Operasi gagal" << endl;  
            return;  
        }  
        if (_size == 1) {  
            delete _head;  
            _head = nullptr;  
        } else {  
            TimeNode* temp = _head;  
            if (index == 0) {  
                TimeNode* tail = _head;  
                while (tail->next != _head)  
                    tail = tail->next;  
                _head = _head->next;  
                tail->next = _head;  
                delete temp;  
            } else {  
                TimeNode* prev = nullptr;  
                for (int i = 0; i < index; i++) {  
                    prev = temp;  
                    temp = temp->next;  
                }  
                prev->next = temp->next;  
                delete temp;  
            }  
        }  
        _size--;  
    }  

    void sisip(int index, int value) {  
        if (value < 1 || value > 1000 || index < 0 || static_cast<unsigned>(index) > _size) {  
            cout << "Operasi gagal" << endl;  
            return;  
        }  
        if (index == 0) {  
            tambahDepan(value);  
            return;  
        } else if (static_cast<unsigned>(index) == _size) {  
            tambahBelakang(value);  
            return;  
        }  
        TimeNode* newNode = new TimeNode(value);  
        TimeNode* temp = _head;  
        for (int i = 0; i < index - 1; i++)  
            temp = temp->next;  
        newNode->next = temp->next;  
        temp->next = newNode;  
        _size++;  
    }  

    void tampilkan() {  
        if (isEmpty()) {  
            cout << endl;  
            return;  
        }  
        TimeNode* temp = _head;  
        bool first = true;  
        do {  
            if (!first) cout << " ";  
            cout << temp->peristiwa;  
            first = false;  
            temp = temp->next;  
        } while (temp != _head);  
        cout << endl;  
    }  
};  

int main() {  
    TimeCircularList linimasa;  
    string perintah;  

    while (cin >> perintah) {  
        if (perintah == "TAMBAH_DEPAN") {  
            int nilai;  
            cin >> nilai;  
            linimasa.tambahDepan(nilai);  
        }  
        else if (perintah == "TAMBAH_BELAKANG") {  
            int nilai;  
            cin >> nilai;  
            linimasa.tambahBelakang(nilai);  
        }  
        else if (perintah == "HAPUS") {  
            int index;  
            cin >> index;  
            linimasa.hapus(index);  
        }  
        else if (perintah == "SISIP") {  
            int index, nilai;  
            cin >> index >> nilai;  
            linimasa.sisip(index, nilai);  
        }  
        else if (perintah == "TAMPILKAN") {  
            linimasa.tampilkan();  
        }  
    }  
    return 0;  
}  

