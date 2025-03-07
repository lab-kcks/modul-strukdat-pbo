#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Class untuk memodelkan antrian pesanan di restoran
class OrderQueue {
private:
    queue<string> orders;
    string restaurantName;

public:
    // Constructor
    OrderQueue(string name) : restaurantName(name) {
        cout << "Sistem antrian untuk " << restaurantName << " telah dibuat!" << endl;
    }
    
    // Menambahkan pesanan baru ke antrian
    void addOrder(const string& orderDetails) {
        orders.push(orderDetails);
        cout << "Pesanan baru ditambahkan: " << orderDetails << endl;
        cout << "Jumlah pesanan dalam antrian: " << orders.size() << endl;
    }
    
    // Memproses pesanan (menghapus dari antrian)
    void processOrder() {
        if (orders.empty()) {
            cout << "Tidak ada pesanan dalam antrian!" << endl;
            return;
        }
        
        string currentOrder = orders.front();
        cout << "Memproses pesanan: " << currentOrder << endl;
        orders.pop();
        cout << "Pesanan telah selesai diproses!" << endl;
        cout << "Jumlah pesanan dalam antrian: " << orders.size() << endl;
    }
    
    // Melihat pesanan yang sedang diproses (di depan antrian)
    void viewCurrentOrder() {
        if (orders.empty()) {
            cout << "Tidak ada pesanan dalam antrian!" << endl;
            return;
        }
        
        cout << "Pesanan yang sedang diproses: " << orders.front() << endl;
    }
    
    // Melihat pesanan terakhir yang masuk
    void viewLastOrder() {
        if (orders.empty()) {
            cout << "Tidak ada pesanan dalam antrian!" << endl;
            return;
        }
        
        cout << "Pesanan terakhir yang masuk: " << orders.back() << endl;
    }
    
    // Cek apakah antrian kosong
    bool isQueueEmpty() {
        return orders.empty();
    }
    
    // Mendapatkan jumlah pesanan dalam antrian
    int getQueueSize() {
        return orders.size();
    }
    
    // Menukar antrian dengan restoran lain
    void swapQueues(OrderQueue& other) {
        orders.swap(other.orders);
        cout << "Antrian " << restaurantName << " dan " << other.restaurantName 
             << " telah ditukar!" << endl;
    }
    
    // Menampilkan informasi antrian
    void displayQueueInfo() {
        cout << "Informasi Antrian " << restaurantName << ":" << endl;
        cout << "Jumlah pesanan: " << orders.size() << endl;
        
        if (!orders.empty()) {
            cout << "Pesanan pertama: " << orders.front() << endl;
            cout << "Pesanan terakhir: " << orders.back() << endl;
        }
    }
};

int main() {
    // Membuat objek antrian untuk dua restoran
    OrderQueue burgerShop("Burger Shop");
    OrderQueue pizzaPlace("Pizza Place");
    
    // Menambahkan pesanan ke Burger Shop
    burgerShop.addOrder("Cheese Burger - Meja 5");
    burgerShop.addOrder("Double Burger - Meja 3");
    burgerShop.addOrder("Chicken Burger - Meja 7");
    
    // Menambahkan pesanan ke Pizza Place
    pizzaPlace.addOrder("Pepperoni Pizza - Meja 2");
    pizzaPlace.addOrder("Vegetarian Pizza - Meja 4");
    
    // Menampilkan informasi kedua antrian
    cout << "\n=== Informasi Antrian ===" << endl;
    burgerShop.displayQueueInfo();
    cout << endl;
    pizzaPlace.displayQueueInfo();
    
    // Proses pesanan di Burger Shop
    cout << "\n=== Memproses Pesanan Burger Shop ===" << endl;
    burgerShop.processOrder();
    
    // Melihat pesanan yang sedang diproses
    cout << "\n=== Pesanan yang Diproses ===" << endl;
    burgerShop.viewCurrentOrder();
    
    // Menukar antrian
    cout << "\n=== Menukar Antrian ===" << endl;
    burgerShop.swapQueues(pizzaPlace);
    
    // Menampilkan informasi setelah pertukaran
    cout << "\n=== Informasi Antrian Setelah Pertukaran ===" << endl;
    burgerShop.displayQueueInfo();
    cout << endl;
    pizzaPlace.displayQueueInfo();
    
    return 0;
}