/**
 * Implementasi Hash Table
 * 
 * Dibuat dan ditulis oleh Nathan Kho Pancras
 * -- tanggal 5 Maret 2025
 * Struktur Data & Pemorograman Berorientasi Objek 2025
 * Implementasi untuk bahasa C++
 * 
 */

#include <iostream>
using namespace std;

class HashTable {
private:
    // Node Structure
    struct HashNode {
        int key;
        int value;
        HashNode *next;
        HashNode(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    HashNode **buckets;  // linked lists array
    unsigned size;
    unsigned count;

    // Map key to index
    unsigned hash_function(int key) {
        return key % size;
    }

public:
    // Constructor
    HashTable(unsigned tableSize) {
        size = tableSize;
        count = 0;
        buckets = new HashNode*[size];
        for (unsigned i = 0; i < size; i++) {
            buckets[i] = nullptr;
        }
    }

    // Destructor
    ~HashTable() {
        for (unsigned i = 0; i < size; i++) {
            HashNode *current = buckets[i];
            while (current != nullptr) {
                HashNode *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] buckets;
    }

    // Insert key-value pair into Hash Table
    void insert(int key, int value) {
        unsigned index = hash_function(key);
        HashNode *current = buckets[index];

        // check if key already exists
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;  // update value
                return;
            }
            current = current->next;
        }

        // create new node
        HashNode *newNode = new HashNode(key, value);
        newNode->next = buckets[index];  // insert at beginning
        buckets[index] = newNode;
        count++;
    }

    // Search for a value by key
    bool search(int key, int *value) {
        unsigned index = hash_function(key);
        HashNode *current = buckets[index];
        
        while (current != nullptr) {
            if (current->key == key) {
                *value = current->value;
                return true;  // Found
            }
            current = current->next;
        }
        return false;
    }

    // Delete a key-value pair by key
    void remove(int key) {
        unsigned index = hash_function(key);
        HashNode *current = buckets[index];
        HashNode *prev = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    buckets[index] = current->next;  // Delete node at the beginning
                } else {
                    prev->next = current->next;  // Delete node in the middle
                }
                delete current;
                count--;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Check if Hash Table is empty
    bool isEmpty() {
        return (count == 0);
    }

    // Display all elements in the hash table
    void display() {
        cout << "\n===== Hash Table Contents =====" << endl;
        if (isEmpty()) {
            cout << "Hash table is empty" << endl;
            return;
        }
        
        for (unsigned i = 0; i < size; i++) {
            HashNode *current = buckets[i];
            if (current != nullptr) {
                cout << "Bucket " << i << ": ";
                while (current != nullptr) {
                    cout << "[" << current->key << ":" << current->value << "] -> ";
                    current = current->next;
                }
                cout << "NULL" << endl;
            }
        }
        cout << "Total elements: " << count << endl;
    }

    // Get count of elements
    unsigned getCount() {
        return count;
    }
};

int main() {
    int choice, key, value, size;
    HashTable *ht = nullptr;
    bool initialized = false;
    
    while (1) {
        cout << "\n===== Hash Table Operations =====" << endl;
        cout << "1. Initialize a new hash table" << endl;
        cout << "2. Insert a key-value pair" << endl;
        cout << "3. Search for a value by key" << endl;
        cout << "4. Delete a key-value pair" << endl;
        cout << "5. Check if hash table is empty" << endl;
        cout << "6. Display all elements" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                if (initialized) {
                    cout << "Hash table is already initialized. Destroying old one." << endl;
                    delete ht;
                }
                cout << "Enter the size of hash table: ";
                cin >> size;
                ht = new HashTable(size);
                initialized = true;
                cout << "Hash table initialized with size " << size << endl;
                break;
                
            case 2:
                if (!initialized) {
                    cout << "Please initialize the hash table first" << endl;
                    break;
                }
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                ht->insert(key, value);
                cout << "Key-value pair inserted" << endl;
                break;
                
            case 3:
                if (!initialized) {
                    cout << "Please initialize the hash table first" << endl;
                    break;
                }
                cout << "Enter key to search: ";
                cin >> key;
                if (ht->search(key, &value)) {
                    cout << "Value found for key " << key << ": " << value << endl;
                } else {
                    cout << "Key " << key << " not found" << endl;
                }
                break;
                
            case 4:
                if (!initialized) {
                    cout << "Please initialize the hash table first" << endl;
                    break;
                }
                cout << "Enter key to delete: ";
                cin >> key;
                ht->remove(key);
                cout << "Key " << key << " deleted (if it existed)" << endl;
                break;
                
            case 5:
                if (!initialized) {
                    cout << "Please initialize the hash table first" << endl;
                    break;
                }
                if (ht->isEmpty()) {
                    cout << "Hash table is empty" << endl;
                } else {
                    cout << "Hash table is not empty" << endl;
                }
                break;
                
            case 6:
                if (!initialized) {
                    cout << "Please initialize the hash table first" << endl;
                    break;
                }
                ht->display();
                break;
                
            case 7:
                if (initialized) {
                    delete ht;
                    cout << "Hash table memory freed" << endl;
                }
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    return 0;
}
