#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Inventory {
private:
    vector<string> items;
    vector<int> quantities;
    vector<double> prices;

public:
    // Constructor
    Inventory() {
        cout << "Inventory system initialized. Maximum capacity: " << items.max_size() << " items." << endl;
    }

    // Add new item to inventory
    void addItem(const string& name, int quantity, double price) {
        items.push_back(name);         // Using push_back() to add element at the end
        quantities.push_back(quantity);
        prices.push_back(price);
        cout << "Added " << quantity << " " << name << "(s) at $" << price << " each." << endl;
    }

    // Remove item from inventory by index
    void removeItem(int index) {
        if (index >= 0 && index < items.size()) {
            cout << "Removed " << items[index] << " from inventory." << endl;
            
            // Using erase() to remove element at specific position
            items.erase(items.begin() + index);
            quantities.erase(quantities.begin() + index);
            prices.erase(prices.begin() + index);
        } else {
            cout << "Invalid index! Cannot remove item." << endl;
        }
    }

    // Access item safely using at()
    void getItemDetails(int index) {
        try {
            // Using at() for safe access with bounds checking
            string name = items.at(index);
            int quantity = quantities.at(index);
            double price = prices.at(index);
            
            cout << "Item: " << name << endl;
            cout << "Quantity: " << quantity << endl;
            cout << "Price: $" << price << endl;
            cout << "Total Value: $" << quantity * price << endl;
        } catch (const out_of_range& e) {
            cout << "Error: " << e.what() << " - Invalid index!" << endl;
        }
    }

    // Update quantity
    void updateQuantity(int index, int newQuantity) {
        if (index >= 0 && index < items.size()) {
            quantities[index] = newQuantity;  // Using operator[] for direct access
            cout << "Updated " << items[index] << " quantity to " << newQuantity << endl;
        } else {
            cout << "Invalid index! Cannot update quantity." << endl;
        }
    }

    // Find item by name
    int findItem(const string& name) {
        // Using begin() and end() for iteration
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (*it == name) {
                int index = distance(items.begin(), it);
                cout << "Found " << name << " at index " << index << endl;
                return index;
            }
        }
        
        cout << name << " not found in inventory." << endl;
        return -1;
    }

    // Sort inventory alphabetically
    void sortInventory() {
        // Create a vector of indices
        vector<int> indices(items.size());
        for (int i = 0; i < indices.size(); ++i) {
            indices[i] = i;
        }

        // Sort indices based on item names
        sort(indices.begin(), indices.end(), [this](int a, int b) {
            return items[a] < items[b];
        });

        // Create temporary vectors for sorted items
        vector<string> sortedItems(items.size());
        vector<int> sortedQuantities(items.size());
        vector<double> sortedPrices(items.size());

        // Rearrange all vectors based on sorted indices
        for (int i = 0; i < indices.size(); ++i) {
            sortedItems[i] = items[indices[i]];
            sortedQuantities[i] = quantities[indices[i]];
            sortedPrices[i] = prices[indices[i]];
        }

        // Swap with original vectors
        items.swap(sortedItems);       // Using swap() to exchange contents
        quantities.swap(sortedQuantities);
        prices.swap(sortedPrices);

        cout << "Inventory sorted alphabetically." << endl;
    }

    // Resize inventory (for planning purposes)
    void planInventorySize(int newSize) {
        int oldSize = items.size();
        
        // Using resize() to change vector size
        items.resize(newSize, "Empty Slot");
        quantities.resize(newSize, 0);
        prices.resize(newSize, 0.0);
        
        cout << "Inventory resized from " << oldSize << " to " << newSize << " slots." << endl;
    }

    // Reset inventory with specific number of empty slots
    void resetInventory(int slots) {
        // Using assign() to set new size and values
        items.assign(slots, "Available");
        quantities.assign(slots, 0);
        prices.assign(slots, 0.0);
        
        cout << "Inventory reset with " << slots << " available slots." << endl;
    }

    // Clear inventory completely
    void clearInventory() {
        // Using clear() to remove all elements
        items.clear();
        quantities.clear();
        prices.clear();
        
        cout << "Inventory cleared. Current size: " << items.size() << endl;
    }

    // Search for items in a price range
    void findItemsInPriceRange(double minPrice, double maxPrice) {
        cout << "Items priced between $" << minPrice << " and $" << maxPrice << ":" << endl;
        
        bool found = false;
        // Using lower_bound() and upper_bound() for range search
        auto minIt = lower_bound(prices.begin(), prices.end(), minPrice);
        auto maxIt = upper_bound(prices.begin(), prices.end(), maxPrice);
        
        // Note: This simple example assumes prices are already sorted
        // In a real implementation, we'd need a more complex approach for unsorted data
        for (auto it = minIt; it != maxIt; ++it) {
            int index = distance(prices.begin(), it);
            cout << "- " << items[index] << ": $" << prices[index] << " (Quantity: " << quantities[index] << ")" << endl;
            found = true;
        }
        
        if (!found) {
            cout << "No items found in this price range." << endl;
        }
    }

    // Display full inventory
    void displayInventory() {
        if (items.empty()) {   // Using empty() to check if vector has no elements
            cout << "Inventory is empty!" << endl;
            return;
        }
        
        cout << "\n===== CURRENT INVENTORY =====" << endl;
        cout << "Total Items: " << items.size() << endl;
        
        double totalValue = 0.0;
        
        for (int i = 0; i < items.size(); ++i) {
            cout << i << ". " << items[i] 
                 << " - Qty: " << quantities[i] 
                 << ", Price: $" << prices[i]
                 << ", Value: $" << quantities[i] * prices[i] << endl;
            
            totalValue += quantities[i] * prices[i];
        }
        
        cout << "\nFirst item: " << items.front() << endl;    // Using front() to access first element
        cout << "Last item: " << items.back() << endl;        // Using back() to access last element
        cout << "Total Inventory Value: $" << totalValue << endl;
        cout << "=============================" << endl;
    }
};

int main() {
    Inventory store;
    
    // Adding items using push_back()
    store.addItem("Laptop", 5, 999.99);
    store.addItem("Smartphone", 10, 499.50);
    store.addItem("Headphones", 15, 59.99);
    store.addItem("Tablet", 7, 349.99);
    store.addItem("Smartwatch", 8, 199.99);
    
    // Display inventory
    store.displayInventory();
    
    // Access item details using at() with exception handling
    cout << "\nAccessing item details:" << endl;
    store.getItemDetails(1);
    store.getItemDetails(10); // This will throw an out_of_range exception
    
    // Find an item
    cout << "\nSearching for items:" << endl;
    int headphonesIndex = store.findItem("Headphones");
    store.findItem("Desktop"); // Not in inventory
    
    // Update quantity using operator[]
    cout << "\nUpdating quantities:" << endl;
    store.updateQuantity(headphonesIndex, 20);
    
    // Remove an item using erase()
    cout << "\nRemoving items:" << endl;
    store.removeItem(0);
    
    // Display updated inventory
    store.displayInventory();
    
    // Sort inventory alphabetically
    cout << "\nSorting inventory:" << endl;
    store.sortInventory();
    store.displayInventory();
    
    // Find items in price range
    cout << "\nSearching by price range:" << endl;
    store.findItemsInPriceRange(100.0, 400.0);
    
    // Resize inventory
    cout << "\nResizing inventory:" << endl;
    store.planInventorySize(8);
    store.displayInventory();
    
    // Reset inventory
    cout << "\nResetting inventory:" << endl;
    store.resetInventory(3);
    store.displayInventory();
    
    // Add new items after reset
    store.addItem("Camera", 3, 299.99);
    store.addItem("Speaker", 6, 79.99);
    store.displayInventory();
    
    // Clear inventory
    cout << "\nClearing inventory:" << endl;
    store.clearInventory();
    store.displayInventory();
    
    return 0;
}