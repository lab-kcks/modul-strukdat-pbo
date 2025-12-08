#include <iostream>
using namespace std;

class SListNode {
public:
    int data;
    SListNode* next;
   
    SListNode(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyList {
private:
    SListNode* head;
    unsigned size;
   
public:
    SinglyList() {
        head = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void pushBack(int value) {
        SListNode* newNode = new SListNode(value);
        if (isEmpty()) {
            head = newNode;
        } else {
            SListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    void printList() {
        SListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            temp = temp->next;
            if (temp != nullptr) cout << " -> ";
        }
        cout << endl;
    }
       
    void swapNodesRange(int a, int b) {
        SListNode* frontStart = nullptr;
        SListNode* frontPrev = nullptr;
        SListNode* backStart = nullptr;
        SListNode* backPrev = nullptr;

        int backStartPos = size - b + 1;

        SListNode* current = head;
        SListNode* prev = nullptr;
       
        for (int i = 1; i <= size; i++) {
            if (i == a) {
                frontStart = current;
                frontPrev = prev;
            }
            if (i == backStartPos) {
                backStart = current;
                backPrev = prev;
            }
            prev = current;
            current = current->next;
        }
       
        int rangeLength = b - a + 1;
       
        // store pointers to the nodes in the ranges
        SListNode** frontNodes = new SListNode*[rangeLength];
        SListNode** backNodes = new SListNode*[rangeLength];
       
        current = frontStart;
        for (int i = 0; i < rangeLength; i++) {
            frontNodes[i] = current;
            current = current->next;
        }
       
        current = backStart;
        for (int i = 0; i < rangeLength; i++) {
            backNodes[i] = current;
            current = current->next;
        }
       
        // save the nodes after the ranges
        SListNode* afterFront = frontNodes[rangeLength - 1]->next;
        SListNode* afterBack = backNodes[rangeLength - 1]->next;
       
        // swap the ranges with reversed order with pointers
        // connect the node before front range to the reversed back range
        if (frontPrev == nullptr) {
            head = backNodes[rangeLength - 1]; // new head = last node of back range
        } else {
            frontPrev->next = backNodes[rangeLength - 1];
        }
       
        // connect reversed back range nodes
        for (int i = rangeLength - 1; i > 0; i--) {
            backNodes[i]->next = backNodes[i - 1];
        }
        backNodes[0]->next = afterFront;
       
        // connect the node before back range to the reversed front range
        if (backPrev == nullptr) {
            head = frontNodes[rangeLength - 1]; // only if back range starts at head
        } else {
            backPrev->next = frontNodes[rangeLength - 1];
        }
       
        // connect reversed front range nodes
        for (int i = rangeLength - 1; i > 0; i--) {
            frontNodes[i]->next = frontNodes[i - 1];
        }
        frontNodes[0]->next = afterBack;
    }
};

int main() {
    SinglyList list;
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "whuh" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.pushBack(val);
    }

    int a, b;
    cin >> a >> b;

    if (a < 1 || b > n || a > b || (b-a+1) > n/2) {
        cout << "-w- fix your range" << endl;
        return 0;
    }

    list.swapNodesRange(a, b);
    cout << ":3 nodes = ";
    list.printList();

    return 0;
}

