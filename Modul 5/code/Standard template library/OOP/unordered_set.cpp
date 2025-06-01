#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

void demonstrateBasicOperations() {
    std::cout << "=== BASIC OPERATIONS ===" << std::endl;
    
    // Membuat unordered_set
    std::unordered_set<int> mySet;
    
    // Insert - memasukkan elemen
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(10); // Duplikat, tidak akan dimasukkan
    
    // Size - mendapatkan ukuran
    std::cout << "Size: " << mySet.size() << std::endl;
    
    // Empty - cek apakah kosong
    std::cout << "Is empty: " << (mySet.empty() ? "Yes" : "No") << std::endl;
    
    // Max size - ukuran maksimal
    std::cout << "Max size: " << mySet.max_size() << std::endl;
    
    // Menampilkan semua elemen
    std::cout << "Elements: ";
    for (const auto& element : mySet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void demonstrateIterators() {
    std::cout << "\n=== ITERATORS ===" << std::endl;
    
    std::unordered_set<std::string> stringSet = {"apple", "banana", "cherry", "date"};
    
    // Begin dan end iterators
    std::cout << "Using begin() and end(): ";
    for (auto it = stringSet.begin(); it != stringSet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Const iterators
    std::cout << "Using cbegin() and cend(): ";
    for (auto it = stringSet.cbegin(); it != stringSet.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Range-based for loop
    std::cout << "Using range-based for: ";
    for (const auto& str : stringSet) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
}

void demonstrateElementLookup() {
    std::cout << "\n=== ELEMENT LOOKUP ===" << std::endl;
    
    std::unordered_set<int> numbers = {1, 5, 10, 15, 20, 25};
    
    // Find - mencari elemen
    int searchValue = 15;
    auto found = numbers.find(searchValue);
    if (found != numbers.end()) {
        std::cout << "Found " << searchValue << " in set" << std::endl;
    } else {
        std::cout << searchValue << " not found in set" << std::endl;
    }
    
    // Count - menghitung elemen (selalu 0 atau 1 untuk unordered_set)
    std::cout << "Count of 15: " << numbers.count(15) << std::endl;
    std::cout << "Count of 100: " << numbers.count(100) << std::endl;
    
    // Equal range - mendapatkan range elemen dengan key tertentu
    auto range = numbers.equal_range(10);
    std::cout << "Equal range for 10: ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void demonstrateModifiers() {
    std::cout << "\n=== MODIFIERS ===" << std::endl;
    
    std::unordered_set<int> mySet;
    
    // Insert dengan berbagai cara
    mySet.insert(100);
    mySet.insert({200, 300, 400});
    
    // Emplace - membangun elemen in-place
    mySet.emplace(500);
    
    std::cout << "After insert and emplace: ";
    for (const auto& elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    // Erase - menghapus elemen
    mySet.erase(200);
    std::cout << "After erasing 200: ";
    for (const auto& elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    // Erase dengan iterator
    auto it = mySet.find(300);
    if (it != mySet.end()) {
        mySet.erase(it);
    }
    std::cout << "After erasing 300 with iterator: ";
    for (const auto& elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    // Swap dengan set lain
    std::unordered_set<int> otherSet = {1000, 2000, 3000};
    std::cout << "Before swap - mySet: ";
    for (const auto& elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << ", otherSet: ";
    for (const auto& elem : otherSet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    mySet.swap(otherSet);
    std::cout << "After swap - mySet: ";
    for (const auto& elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << ", otherSet: ";
    for (const auto& elem : otherSet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    // Clear - menghapus semua elemen
    mySet.clear();
    std::cout << "After clear - size: " << mySet.size() << std::endl;
}

void demonstrateBuckets() {
    std::cout << "\n=== BUCKETS ===" << std::endl;
    
    std::unordered_set<int> mySet = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Bucket count - jumlah bucket
    std::cout << "Bucket count: " << mySet.bucket_count() << std::endl;
    
    // Max bucket count
    std::cout << "Max bucket count: " << mySet.max_bucket_count() << std::endl;
    
    // Bucket size - ukuran setiap bucket
    for (size_t i = 0; i < mySet.bucket_count(); ++i) {
        std::cout << "Bucket " << i << " size: " << mySet.bucket_size(i) << std::endl;
    }
    
    // Bucket - menentukan bucket dari elemen
    int element = 5;
    std::cout << "Element " << element << " is in bucket: " << mySet.bucket(element) << std::endl;
}

void demonstrateHashPolicy() {
    std::cout << "\n=== HASH POLICY ===" << std::endl;
    
    std::unordered_set<int> mySet = {1, 2, 3, 4, 5};
    
    // Load factor - rasio elemen terhadap bucket
    std::cout << "Load factor: " << mySet.load_factor() << std::endl;
    
    // Max load factor
    std::cout << "Max load factor: " << mySet.max_load_factor() << std::endl;
    
    // Mengatur max load factor
    mySet.max_load_factor(0.5);
    std::cout << "New max load factor: " << mySet.max_load_factor() << std::endl;
    
    // Rehash - mengatur jumlah bucket
    std::cout << "Bucket count before rehash: " << mySet.bucket_count() << std::endl;
    mySet.rehash(20);
    std::cout << "Bucket count after rehash(20): " << mySet.bucket_count() << std::endl;
    
    // Reserve - meminta kapasitas untuk elemen tertentu
    mySet.reserve(100);
    std::cout << "Bucket count after reserve(100): " << mySet.bucket_count() << std::endl;
}

void demonstrateObservers() {
    std::cout << "\n=== OBSERVERS ===" << std::endl;
    
    std::unordered_set<std::string> mySet = {"hello", "world"};
    
    // Hash function
    auto hasher = mySet.hash_function();
    std::string testStr = "hello";
    std::cout << "Hash of '" << testStr << "': " << hasher(testStr) << std::endl;
    
    // Key equality predicate
    auto key_eq = mySet.key_eq();
    std::cout << "Are 'hello' and 'hello' equal? " << (key_eq("hello", "hello") ? "Yes" : "No") << std::endl;
    std::cout << "Are 'hello' and 'world' equal? " << (key_eq("hello", "world") ? "Yes" : "No") << std::endl;
    
    // Get allocator
    auto alloc = mySet.get_allocator();
    std::cout << "Allocator obtained successfully" << std::endl;
}

void demonstrateCustomHashAndPredicate() {
    std::cout << "\n=== CUSTOM HASH AND PREDICATE ===" << std::endl;
    
    // Custom hash function untuk struct
    struct Person {
        std::string name;
        int age;
        
        bool operator==(const Person& other) const {
            return name == other.name && age == other.age;
        }
    };
    
    // Custom hash function
    struct PersonHash {
        std::size_t operator()(const Person& p) const {
            return std::hash<std::string>{}(p.name) ^ 
                   (std::hash<int>{}(p.age) << 1);
        }
    };
    
    // Custom equality predicate
    struct PersonEqual {
        bool operator()(const Person& lhs, const Person& rhs) const {
            return lhs.name == rhs.name && lhs.age == rhs.age;
        }
    };
    
    std::unordered_set<Person, PersonHash, PersonEqual> personSet;
    
    personSet.insert({"Alice", 25});
    personSet.insert({"Bob", 30});
    personSet.insert({"Alice", 25}); // Duplikat, tidak akan dimasukkan
    
    std::cout << "Person set size: " << personSet.size() << std::endl;
    
    // Mencari person
    Person searchPerson = {"Alice", 25};
    if (personSet.find(searchPerson) != personSet.end()) {
        std::cout << "Found Alice, age 25" << std::endl;
    }
}

int main() {
    std::cout << "=== STD::UNORDERED_SET DEMONSTRATION ===" << std::endl;
    
    demonstrateBasicOperations();
    demonstrateIterators();
    demonstrateElementLookup();
    demonstrateModifiers();
    demonstrateBuckets();
    demonstrateHashPolicy();
    demonstrateObservers();
    demonstrateCustomHashAndPredicate();
    
    return 0;
}