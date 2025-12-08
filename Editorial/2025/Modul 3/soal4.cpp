#include <iostream>
using namespace std;

class Dictionary {
private:
    struct Node {
        int key;
        int value;
        bool used;
    };
    Node dict[100];
    int size;

public:
    Dictionary() {
        size = 0;
        for (int i = 0; i < 100; ++i) {
            dict[i].used = false;
        }
    }
    
    bool contains(int key) {
        for (int i = 0; i < size; ++i) {
            if (dict[i].used && dict[i].key == key) {
                return true;
            }
        }
        return false;
    }
    
    int lookup(int key) {
        for (int i = 0; i < size; ++i) {
            if (dict[i].used && dict[i].key == key) {
                return dict[i].value;
            }
        }
        return -1;
    }
    
    void log(int key, int value) {
        for (int i = 0; i < size; ++i) {
            if (dict[i].used && dict[i].key == key) {
                dict[i].value = value;
                return;
            }
        }
        
        if (size < 100) {
            dict[size].key = key;
            dict[size].value = value;
            dict[size].used = true;
            size++;
        }
    }
};

int main() {
    int N;
    cin >> N;
    
    int A[100];  
    for (int i = 0; i < N; i++) cin >> A[i];
    
    Dictionary dict;
    int B[100];  
    
    for (int i = 0; i < N; i++) {
        B[i] = -1;
    }
    
    for (int i = 0; i < N; ++i) {
        if (dict.contains(A[i])) {
            B[i] = dict.lookup(A[i]);
        }
        dict.log(A[i], i + 1);
    }
    
    for (int i = 0; i < N; ++i) {
        cout << B[i] << (i < N - 1 ? " " : "\n");
    }
}

