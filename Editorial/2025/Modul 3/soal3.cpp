#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    struct PQueueNode {
        int data;
        PQueueNode *next;
        PQueueNode(int value) : data(value), next(nullptr) {}
    };

    PQueueNode *_top;
    unsigned _size;

public:
    PriorityQueue() {
        _top = nullptr;
        _size = 0;
    }

    ~PriorityQueue() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return (_top == nullptr);
    }

    void push(int value) {
        PQueueNode *newNode = new PQueueNode(value);
        _size++;

        if (isEmpty()) {
            _top = newNode;
            return;
        }

        if (value < _top->data) {
            newNode->next = _top;
            _top = newNode;
        } else {
            PQueueNode *temp = _top;
            while (temp->next != nullptr && temp->next->data < value) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void pop() {
        if (!isEmpty()) {
            PQueueNode *temp = _top;
            _top = _top->next;
            delete temp;
            _size--;
        }
    }

    int top() {
        if (!isEmpty())
            return _top->data;
        throw runtime_error("PriorityQueue kosong");
    }

    unsigned size() {
        return _size;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }

    PriorityQueue taken;

    for (int i = 0; i < n; ++i) {
        taken.push(a[i]);
        if (i & 1) taken.pop();  
    }

    long long ans = 0;
    while (!taken.isEmpty()) {
        ans += taken.top();
        taken.pop();
    }

    cout << ans << endl;
    return 0;
}
