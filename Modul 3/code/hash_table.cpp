// Simple Hash Table implementation in C++
// Author: Nathan Kho Pancras

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct HashNode {
    int key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct HashTable {
    HashNode **buckets;  // linked lists array
    unsigned size;
    unsigned count;
} HashTable;

/**
 * @param ht Pointer to Hash Table to be initialized
 * @param size Size of the Hash Table
 */
void hash_init(HashTable *ht, unsigned size) {
    ht->size = size;
    ht->count = 0;
    ht->buckets = (HashNode**) malloc(size * sizeof(HashNode*));
    for (unsigned i = 0; i < size; i++) {
        ht->buckets[i] = NULL;
    }
}

/**
 * Map key to index
 * @param ht Pointer to Hash Table
 * @param key Key to be hashed
 * @return Index in the Hash Table
 */
unsigned hash_function(HashTable *ht, int key) {
    return key % ht->size;
}

/**
 * Insert key-value pair into Hash Table
 * @param ht Pointer to Hash Table
 * @param key Key to be inserted
 * @param value Value to be associated with the key
 */
void hash_insert(HashTable *ht, int key, int value) {
    unsigned index = hash_function(ht, key);
    HashNode *current = ht->buckets[index];

    // check if key already exists
    while (current != NULL) {
        if (current->key == key) {
            current->value = value;  // update value
            return;
        }
        current = current->next;
    }

    // create new node
    HashNode *newNode = (HashNode*) malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = ht->buckets[index];  // insert at beginning
    ht->buckets[index] = newNode;
    ht->count++;
}

/**
 * Search for a value by key
 * @param ht Pointer to Hash Table
 * @param key Key to search for
 * @param value Pointer to store the found value
 * @return true if key found, false otherwise
 */
bool hash_search(HashTable *ht, int key, int *value) {
    unsigned index = hash_function(ht, key);
    HashNode *current = ht->buckets[index];
    
    while (current != NULL) {
        if (current->key == key) {
            *value = current->value;
            return true;  // Found
        }
        current = current->next;
    }
    return false;
}

/**
 * Delete a key-value pair by key
 * @param ht Pointer to Hash Table
 * @param key Key to be deleted
 */
void hash_delete(HashTable *ht, int key) {
    unsigned index = hash_function(ht, key);
    HashNode *current = ht->buckets[index];
    HashNode *prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                ht->buckets[index] = current->next;  // Delete node at the beginning
            } else {
                prev->next = current->next;  // Delete node in the middle
            }
            free(current);
            ht->count--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

/**
 * Check if Hash Table is empty
 * @param ht Pointer to Hash Table
 * @return true if empty, false otherwise
 */
bool hash_isEmpty(HashTable *ht) {
    return (ht->count == 0);
}

/**
 * Free memory used by Hash Table
 * @param ht Pointer to Hash Table
 */
void hash_destroy(HashTable *ht) {
    for (unsigned i = 0; i < ht->size; i++) {
        HashNode *current = ht->buckets[i];
        while (current != NULL) {
            HashNode *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->buckets);
    ht->count = 0;
    ht->size = 0;
}

/**
 * Display all elements in the hash table
 * @param ht Pointer to Hash Table
 */
void hash_display(HashTable *ht) {
    printf("\n===== Hash Table Contents =====\n");
    if (hash_isEmpty(ht)) {
        printf("Hash table is empty\n");
        return;
    }
    
    for (unsigned i = 0; i < ht->size; i++) {
        HashNode *current = ht->buckets[i];
        if (current != NULL) {
            printf("Bucket %u: ", i);
            while (current != NULL) {
                printf("[%d:%d] -> ", current->key, current->value);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
    printf("Total elements: %u\n", ht->count);
}

int main() {
    HashTable ht;
    int choice, key, value, size;
    bool initialized = false;
    
    while (1) {
        printf("\n===== Hash Table Operations =====\n");
        printf("1. Initialize a new hash table\n");
        printf("2. Insert a key-value pair\n");
        printf("3. Search for a value by key\n");
        printf("4. Delete a key-value pair\n");
        printf("5. Check if hash table is empty\n");
        printf("6. Display all elements\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (initialized) {
                    printf("Hash table is already initialized. Destroying old one.\n");
                    hash_destroy(&ht);
                }
                printf("Enter the size of hash table: ");
                scanf("%d", &size);
                hash_init(&ht, size);
                initialized = true;
                printf("Hash table initialized with size %d\n", size);
                break;
                
            case 2:
                if (!initialized) {
                    printf("Please initialize the hash table first\n");
                    break;
                }
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                hash_insert(&ht, key, value);
                printf("Key-value pair inserted\n");
                break;
                
            case 3:
                if (!initialized) {
                    printf("Please initialize the hash table first\n");
                    break;
                }
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (hash_search(&ht, key, &value)) {
                    printf("Value found for key %d: %d\n", key, value);
                } else {
                    printf("Key %d not found\n", key);
                }
                break;
                
            case 4:
                if (!initialized) {
                    printf("Please initialize the hash table first\n");
                    break;
                }
                printf("Enter key to delete: ");
                scanf("%d", &key);
                hash_delete(&ht, key);
                printf("Key %d deleted (if it existed)\n", key);
                break;
                
            case 5:
                if (!initialized) {
                    printf("Please initialize the hash table first\n");
                    break;
                }
                if (hash_isEmpty(&ht)) {
                    printf("Hash table is empty\n");
                } else {
                    printf("Hash table is not empty\n");
                }
                break;
                
            case 6:
                if (!initialized) {
                    printf("Please initialize the hash table first\n");
                    break;
                }
                hash_display(&ht);
                break;
                
            case 7:
                if (initialized) {
                    hash_destroy(&ht);
                    printf("Hash table memory freed\n");
                }
                printf("Exiting program. Goodbye!\n");
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
