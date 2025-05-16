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
   
    void solution(int a, int b) {
        // store values > arr
        int* values = new int[size];
        SListNode* temp = head;
       
        for (int i = 0; i < size; i++) {
            values[i] = temp->data;
            temp = temp->next;
        }

        // make arrays for the ranges
        int rangeLength = b - a + 1;
        int* frontRange = new int[rangeLength];
        int* backRange = new int[rangeLength];
        for (int i = 0; i < rangeLength; i++) {
            frontRange[i] = values[a - 1 + i];
            backRange[i] = values[size - b + i];
        }
       
        for (int i = 0; i < rangeLength / 2; i++) {
            // rev front
            int temp = frontRange[i];
            frontRange[i] = frontRange[rangeLength - 1 - i];
            frontRange[rangeLength - 1 - i] = temp;
            // rev back
            temp = backRange[i];
            backRange[i] = backRange[rangeLength - 1 - i];
            backRange[rangeLength - 1 - i] = temp;
        }
       
        // place reversed range but swapped
        for (int i = 0; i < rangeLength; i++) {
            values[a - 1 + i] = backRange[i];
            values[size - b + i] = frontRange[i];
        }
       
        temp = head;
        for (int i = 0; i < size; i++) {
            temp->data = values[i];
            temp = temp->next;
        }
    }
};

int main() {
    SinglyList list;
    int n;
    cin >> n;

    if (n <= 0 || n % 2 != 1) {
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

    list.solution(a, b);
    cout << ":3 nodes = ";
    list.printList();

    return 0;
}