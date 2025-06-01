#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class UnorderedMapManager {
private:
    unordered_map<int, string> myMap;

public:
    // Constructor
    UnorderedMapManager() {}
    
    // Constructor dengan initialization list
    UnorderedMapManager(const vector<pair<int, string>>& init_data) {
        for (const auto& p : init_data) {
            myMap.insert(p);
        }
    }
    
    // Method untuk demonstrasi declaration dan initialization
    void demonstrateInitialization() {
        cout << "\n1. Declaration dan Initialization:" << endl;
        unordered_map<int, string> um1; // Empty map
        unordered_map<int, string> um2 = {{1, "Geeks"}, {2, "For"}, {3, "C++"}};
        
        cout << "Empty map size: " << um1.size() << endl;
        cout << "Initialized map size: " << um2.size() << endl;
    }
    
    // Method untuk accessing dan updating elements
    void demonstrateAccessAndUpdate() {
        cout << "\n2. Accessing dan Updating elements:" << endl;
        
        // Insert using []
        myMap[1] = "Apple";
        myMap[2] = "Banana";
        myMap[3] = "Orange";
        
        // Insert using insert()
        myMap.insert({4, "Mango"});
        myMap.insert(make_pair(5, "Grape"));
        
        cout << "Using []: " << myMap[2] << endl;
        cout << "Using at(): " << myMap.at(1) << endl;
        
        // Update using []
        myMap[2] = "Blueberry";
        cout << "Updated value: " << myMap[2] << endl;
        
        // Update using at()
        myMap.at(3) = "Strawberry";
        cout << "Updated value: " << myMap.at(3) << endl;
    }
    
    // Method untuk check key existence
    void checkKeyExistence(int key) {
        cout << "\n3. Check if key " << key << " exists:" << endl;
        cout << "Key " << key << " exists? " << (myMap.count(key) ? "Yes" : "No") << endl;
    }
    
    // Method untuk finding elements
    void findElement(int key) {
        cout << "\n4. Finding element with key " << key << ":" << endl;
        auto findResult = myMap.find(key);
        if (findResult != myMap.end()) {
            cout << "Found: " << findResult->first << " -> " << findResult->second << endl;
        } else {
            cout << "Key " << key << " not found" << endl;
        }
    }
    
    // Method untuk traversing dengan berbagai cara
    void demonstrateTraversal() {
        cout << "\n5. Traversing using iterators:" << endl;
        
        cout << "Using begin() and end():" << endl;
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            cout << it->first << ": " << it->second << endl;
        }
        
        cout << "Using cbegin() and cend() (const iterators):" << endl;
        for (auto it = myMap.cbegin(); it != myMap.cend(); ++it) {
            cout << it->first << ": " << it->second << endl;
        }
        
        cout << "Using range-based for loop:" << endl;
        for (const auto& pair : myMap) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
    
    // Method untuk size operations
    void showSizeOperations() {
        cout << "\n6. Size operations:" << endl;
        cout << "Size: " << myMap.size() << endl;
        cout << "Empty? " << (myMap.empty() ? "Yes" : "No") << endl;
        cout << "Max size: " << myMap.max_size() << endl;
    }
    
    // Method untuk bucket operations
    void demonstrateBucketOperations() {
        cout << "\n7. Bucket operations:" << endl;
        cout << "Bucket count: " << myMap.bucket_count() << endl;
        cout << "Max bucket count: " << myMap.max_bucket_count() << endl;
        cout << "Load factor: " << myMap.load_factor() << endl;
        cout << "Max load factor: " << myMap.max_load_factor() << endl;
        
        // bucket() and bucket_size()
        for (const auto& pair : myMap) {
            size_t bucket_num = myMap.bucket(pair.first);
            cout << "Key " << pair.first << " is in bucket " << bucket_num 
                 << " (size: " << myMap.bucket_size(bucket_num) << ")" << endl;
        }
    }
    
    // Method untuk equal_range
    void demonstrateEqualRange(int key) {
        cout << "\n8. Equal range for key " << key << ":" << endl;
        auto range = myMap.equal_range(key);
        for (auto it = range.first; it != range.second; ++it) {
            cout << it->first << ": " << it->second << endl;
        }
    }
    
    // Method untuk deleting elements
    void demonstrateErase() {
        cout << "\n9. Deleting elements:" << endl;
        cout << "Size before erase: " << myMap.size() << endl;
        
        // Erase by key
        if (myMap.count(3)) {
            myMap.erase(3);
            cout << "Size after erasing key 3: " << myMap.size() << endl;
        }
        
        // Erase by iterator
        auto it_to_erase = myMap.find(4);
        if (it_to_erase != myMap.end()) {
            myMap.erase(it_to_erase);
            cout << "Size after erasing by iterator: " << myMap.size() << endl;
        }
    }
    
    // Method untuk emplace operations
    void demonstrateEmplace() {
        cout << "\n10. Emplace operations:" << endl;
        auto emplace_result = myMap.emplace(6, "Kiwi");
        cout << "Emplace successful? " << (emplace_result.second ? "Yes" : "No") << endl;
        
        // emplace_hint()
        auto hint = myMap.begin();
        myMap.emplace_hint(hint, 7, "Pineapple");
        cout << "Size after emplace operations: " << myMap.size() << endl;
    }
    
    // Method untuk swap operation
    void demonstrateSwap() {
        cout << "\n11. Swap operation:" << endl;
        unordered_map<int, string> otherMap = {{10, "Ten"}, {20, "Twenty"}};
        
        cout << "Before swap - myMap size: " << myMap.size() << endl;
        cout << "Before swap - otherMap size: " << otherMap.size() << endl;
        
        myMap.swap(otherMap);
        
        cout << "After swap - myMap size: " << myMap.size() << endl;
        cout << "After swap - otherMap size: " << otherMap.size() << endl;
    }
    
    // Method untuk extract operation
    void demonstrateExtract(int key) {
        cout << "\n12. Extract operation for key " << key << ":" << endl;
        auto extracted_node = myMap.extract(key);
        if (!extracted_node.empty()) {
            cout << "Extracted: " << extracted_node.key() << " -> " << extracted_node.mapped() << endl;
            cout << "Map size after extract: " << myMap.size() << endl;
            
            // Insert back
            myMap.insert(move(extracted_node));
            cout << "Map size after inserting extracted node: " << myMap.size() << endl;
        } else {
            cout << "Key " << key << " not found for extraction" << endl;
        }
    }
    
    // Method untuk merge operation
    void demonstrateMerge() {
        cout << "\n13. Merge operation:" << endl;
        unordered_map<int, string> mapToMerge = {{30, "Thirty"}, {40, "Forty"}};
        
        cout << "Before merge - myMap size: " << myMap.size() << endl;
        cout << "Before merge - mapToMerge size: " << mapToMerge.size() << endl;
        
        myMap.merge(mapToMerge);
        
        cout << "After merge - myMap size: " << myMap.size() << endl;
        cout << "After merge - mapToMerge size: " << mapToMerge.size() << endl;
    }
    
    // Method untuk insert range
    void demonstrateInsertRange() {
        cout << "\n14. Insert range operation:" << endl;
        vector<pair<int, string>> range_data = {{50, "Fifty"}, {60, "Sixty"}};
        
        for (const auto& p : range_data) {
            myMap.insert(p);
        }
        cout << "Size after range insert: " << myMap.size() << endl;
    }
    
    // Method untuk rehash operations
    void demonstrateRehash() {
        cout << "\n15. Rehash operations:" << endl;
        cout << "Bucket count before rehash: " << myMap.bucket_count() << endl;
        myMap.rehash(50);
        cout << "Bucket count after rehash(50): " << myMap.bucket_count() << endl;
        
        myMap.reserve(100);
        cout << "Bucket count after reserve(100): " << myMap.bucket_count() << endl;
    }
    
    // Method untuk hash function dan key equality
    void demonstrateHashFunction() {
        cout << "\n16. Hash function dan key equality:" << endl;
        auto hasher = myMap.hash_function();
        auto key_equal = myMap.key_eq();
        
        cout << "Hash of key 10: " << hasher(10) << endl;
        cout << "Hash of key 20: " << hasher(20) << endl;
        cout << "Keys 10 and 10 equal? " << (key_equal(10, 10) ? "Yes" : "No") << endl;
        cout << "Keys 10 and 20 equal? " << (key_equal(10, 20) ? "Yes" : "No") << endl;
    }
    
    // Method untuk menampilkan final state
    void displayFinalState() {
        cout << "\n17. Final map contents:" << endl;
        for (const auto& pair : myMap) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
    
    // Method untuk clear operation
    void demonstrateClear() {
        cout << "\n18. Clear operation:" << endl;
        cout << "Size before clear: " << myMap.size() << endl;
        myMap.clear();
        cout << "Size after clear: " << myMap.size() << endl;
        cout << "Empty after clear? " << (myMap.empty() ? "Yes" : "No") << endl;
    }
    
    // Getter untuk ukuran map
    size_t getSize() const {
        return myMap.size();
    }
    
    // Method untuk cek apakah kosong
    bool isEmpty() const {
        return myMap.empty();
    }
    
    // Method untuk insert single element
    void insertElement(int key, const string& value) {
        myMap[key] = value;
    }
    
    // Method untuk get element
    string getElement(int key) const {
        auto it = myMap.find(key);
        return (it != myMap.end()) ? it->second : "Not Found";
    }
};

int main() {
    cout << "=== DEMONSTRASI STD::UNORDERED_MAP OOP VERSION ===" << endl;
    
    // Membuat objek UnorderedMapManager
    UnorderedMapManager mapMgr;
    
    // Menjalankan semua demonstrasi
    mapMgr.demonstrateInitialization();
    mapMgr.demonstrateAccessAndUpdate();
    mapMgr.checkKeyExistence(2);
    mapMgr.checkKeyExistence(10);
    mapMgr.findElement(3);
    mapMgr.demonstrateTraversal();
    mapMgr.showSizeOperations();
    mapMgr.demonstrateBucketOperations();
    mapMgr.demonstrateEqualRange(2);
    mapMgr.demonstrateErase();
    mapMgr.demonstrateEmplace();
    mapMgr.demonstrateSwap();
    mapMgr.demonstrateExtract(1);
    mapMgr.demonstrateMerge();
    mapMgr.demonstrateInsertRange();
    mapMgr.demonstrateRehash();
    mapMgr.demonstrateHashFunction();
    mapMgr.displayFinalState();
    mapMgr.demonstrateClear();
    
    cout << "\n=== DEMO TAMBAHAN ===" << endl;
    
    // Membuat objek baru dengan initial data
    vector<pair<int, string>> initial_data = {{100, "Hundred"}, {200, "Two Hundred"}};
    UnorderedMapManager mapMgr2(initial_data);
    
    cout << "Initial size of mapMgr2: " << mapMgr2.getSize() << endl;
    cout << "Is mapMgr2 empty? " << (mapMgr2.isEmpty() ? "Yes" : "No") << endl;
    
    mapMgr2.insertElement(300, "Three Hundred");
    cout << "Element with key 200: " << mapMgr2.getElement(200) << endl;
    cout << "Element with key 999: " << mapMgr2.getElement(999) << endl;
    
    return 0;
}