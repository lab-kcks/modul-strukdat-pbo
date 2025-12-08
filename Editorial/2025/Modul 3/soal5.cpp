#include <iostream>
#include <string>
using namespace std;

const int MAX_RESULT = 10000; 

class Node {
public:
    char data;
    Node* prev;
    Node* next;

    Node(char val) : data(val), prev(nullptr), next(nullptr) {}
};

class Deque {
private:
    Node* head;
    Node* tail;
    int length;

public:
    Deque() : head(nullptr), tail(nullptr), length(0) {}

    void push_back(char val) {
        Node* node = new Node(val);
        if (!tail) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        ++length;
    }

    char get(int index) const {
        Node* curr = head;
        for (int i = 0; i < index && curr; ++i) {
            curr = curr->next;
        }
        return curr ? curr->data : '\0';
    }

    void set(int index, char val) {
        Node* curr = head;
        for (int i = 0; i < index && curr; ++i) {
            curr = curr->next;
        }
        if (curr) curr->data = val;
    }

    int size() const {
        return length;
    }

    string toString() const {
        string res;
        Node* curr = head;
        while (curr) {
            res += curr->data;
            curr = curr->next;
        }
        return res;
    }

    ~Deque() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};

class PalindromeSolver {
private:
    Deque dq;
    int minChanges;
    string results[MAX_RESULT]; 
    int resultCount;

    void countChanges() {
        int n = dq.size();
        minChanges = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (dq.get(i) != dq.get(n - 1 - i)) {
                ++minChanges;
            }
        }
    }

    bool isDuplicate(const string& s) const {
        for (int i = 0; i < resultCount; ++i) {
            if (results[i] == s) return true;
        }
        return false;
    }

    void addResult(const string& s) {
        if (!isDuplicate(s) && resultCount < MAX_RESULT) {
            results[resultCount++] = s;
        }
    }

    void generate(string& s, int left, int right, int currChanges) {
        if (left >= right) {
            if (currChanges == minChanges) {
                addResult(s);
            }
            return;
        }

        if (s[left] == s[right]) {
            generate(s, left + 1, right - 1, currChanges);
        } else {
            char origL = s[left], origR = s[right];

            s[left] = origR;
            generate(s, left + 1, right - 1, currChanges + 1);
            s[left] = origL;

            s[right] = origL;
            generate(s, left + 1, right - 1, currChanges + 1);
            s[right] = origR;
        }
    }

    void manualSort() {
        for (int i = 0; i < resultCount - 1; ++i) {
            for (int j = i + 1; j < resultCount; ++j) {
                if (results[j] < results[i]) {
                    string temp = results[i];
                    results[i] = results[j];
                    results[j] = temp;
                }
            }
        }
    }

public:
    PalindromeSolver() : minChanges(0), resultCount(0) {}

    void input(int n, const string& s) {
        for (char c : s) {
            dq.push_back(c);
        }
    }

    void solve() {
        countChanges();
        string s = dq.toString();
        generate(s, 0, s.size() - 1, 0);
        manualSort();

        cout << minChanges << "\n";
        for (int i = 0; i < resultCount; ++i) {
            cout << results[i] << "\n";
        }
    }
};

int main() {
    int n;
    string s;
    cin >> n >> s;

    PalindromeSolver solver;
    solver.input(n, s);
    solver.solve();

    return 0;
}


