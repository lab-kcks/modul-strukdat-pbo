#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main() {
    
    // 1. Declaration dan Initialization
    cout << "\n1. Declaration dan Initialization:" << endl;
    unordered_map<int, string> um1; // Empty map
    unordered_map<int, string> um2 = {{1, "Geeks"}, {2, "For"}, {3, "C++"}};
    
    cout << "Empty map size: " << um1.size() << endl;
    cout << "Initialized map size: " << um2.size() << endl;
    
    // 2. operator[] dan at() - Accessing/Updating elements
    cout << "\n2. Accessing dan Updating elements:" << endl;
    unordered_map<int, string> myMap;
    
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
    
    // 3. contains() - Check if key exists (C++20)
    cout << "\n3. Check if key exists using count():" << endl;
    cout << "Key 2 exists? " << (myMap.count(2) ? "Yes" : "No") << endl;
    cout << "Key 10 exists? " << (myMap.count(10) ? "Yes" : "No") << endl;
    
    // 4. find() - Finding elements
    cout << "\n4. Finding elements:" << endl;
    auto findResult = myMap.find(3);
    if (findResult != myMap.end()) {
        cout << "Found: " << findResult->first << " -> " << findResult->second << endl;
    }
    
    // 5. begin(), end(), cbegin(), cend() - Iterators
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
    
    // 6. size(), empty(), max_size()
    cout << "\n6. Size operations:" << endl;
    cout << "Size: " << myMap.size() << endl;
    cout << "Empty? " << (myMap.empty() ? "Yes" : "No") << endl;
    cout << "Max size: " << myMap.max_size() << endl;
    
    // 7. Bucket operations
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
    
    // 8. equal_range()
    cout << "\n8. Equal range:" << endl;
    auto range = myMap.equal_range(2);
    cout << "Equal range for key 2:" << endl;
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->first << ": " << it->second << endl;
    }
    
    // 9. erase() - Deleting elements
    cout << "\n9. Deleting elements:" << endl;
    cout << "Size before erase: " << myMap.size() << endl;
    
    // Erase by key
    myMap.erase(3);
    cout << "Size after erasing key 3: " << myMap.size() << endl;
    
    // Erase by iterator
    auto it_to_erase = myMap.find(4);
    if (it_to_erase != myMap.end()) {
        myMap.erase(it_to_erase);
        cout << "Size after erasing by iterator: " << myMap.size() << endl;
    }
    
    // 10. emplace() dan emplace_hint()
    cout << "\n10. Emplace operations:" << endl;
    auto emplace_result = myMap.emplace(6, "Kiwi");
    cout << "Emplace successful? " << (emplace_result.second ? "Yes" : "No") << endl;
    
    // emplace_hint()
    auto hint = myMap.begin();
    myMap.emplace_hint(hint, 7, "Pineapple");
    cout << "Size after emplace operations: " << myMap.size() << endl;
    
    // 11. swap()
    cout << "\n11. Swap operation:" << endl;
    unordered_map<int, string> otherMap = {{10, "Ten"}, {20, "Twenty"}};
    
    cout << "Before swap - myMap size: " << myMap.size() << endl;
    cout << "Before swap - otherMap size: " << otherMap.size() << endl;
    
    myMap.swap(otherMap);
    
    cout << "After swap - myMap size: " << myMap.size() << endl;
    cout << "After swap - otherMap size: " << otherMap.size() << endl;
    
    // 12. extract() - Extract node (C++17)
    cout << "\n12. Extract operation:" << endl;
    auto extracted_node = otherMap.extract(1);
    if (!extracted_node.empty()) {
        cout << "Extracted: " << extracted_node.key() << " -> " << extracted_node.mapped() << endl;
        cout << "otherMap size after extract: " << otherMap.size() << endl;
        
        // Insert back
        myMap.insert(move(extracted_node));
        cout << "myMap size after inserting extracted node: " << myMap.size() << endl;
    }
    
    // 13. merge() - Merge maps (C++17)
    cout << "\n13. Merge operation:" << endl;
    unordered_map<int, string> mapToMerge = {{30, "Thirty"}, {40, "Forty"}};
    
    cout << "Before merge - myMap size: " << myMap.size() << endl;
    cout << "Before merge - mapToMerge size: " << mapToMerge.size() << endl;
    
    myMap.merge(mapToMerge);
    
    cout << "After merge - myMap size: " << myMap.size() << endl;
    cout << "After merge - mapToMerge size: " << mapToMerge.size() << endl;
    
    // 14. insert_range() (C++23 - might not be available in all compilers)
    cout << "\n14. Insert range operation:" << endl;
    vector<pair<int, string>> range_data = {{50, "Fifty"}, {60, "Sixty"}};
    
    for (const auto& p : range_data) {
        myMap.insert(p);
    }
    cout << "Size after range insert: " << myMap.size() << endl;
    
    // 15. rehash() dan reserve()
    cout << "\n15. Rehash operations:" << endl;
    cout << "Bucket count before rehash: " << myMap.bucket_count() << endl;
    myMap.rehash(50);
    cout << "Bucket count after rehash(50): " << myMap.bucket_count() << endl;
    
    myMap.reserve(100);
    cout << "Bucket count after reserve(100): " << myMap.bucket_count() << endl;
    
    // 16. hash_function() dan key_eq()
    cout << "\n16. Hash function dan key equality:" << endl;
    auto hasher = myMap.hash_function();
    auto key_equal = myMap.key_eq();
    
    cout << "Hash of key 10: " << hasher(10) << endl;
    cout << "Hash of key 20: " << hasher(20) << endl;
    cout << "Keys 10 and 10 equal? " << (key_equal(10, 10) ? "Yes" : "No") << endl;
    cout << "Keys 10 and 20 equal? " << (key_equal(10, 20) ? "Yes" : "No") << endl;
    
    // 17. Final state
    cout << "\n17. Final map contents:" << endl;
    for (const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // 18. clear()
    cout << "\n18. Clear operation:" << endl;
    cout << "Size before clear: " << myMap.size() << endl;
    myMap.clear();
    cout << "Size after clear: " << myMap.size() << endl;
    cout << "Empty after clear? " << (myMap.empty() ? "Yes" : "No") << endl;
    
    return 0;
}