#include <iostream>
#include <deque>
#include <string>

using namespace std;

// Class untuk merepresentasikan browser history dengan deque
class BrowserHistory {
private:
    deque<string> history;
    string browserName;
    size_t maxHistorySize;

public:
    // Constructor
    BrowserHistory(string name, size_t maxSize = 100) : browserName(name), maxHistorySize(maxSize) {
        cout << "Browser History untuk " << browserName << " telah dibuat dengan kapasitas " << maxHistorySize << " halaman!" << endl;
    }
    
    // Menambahkan website ke history (di akhir)
    void visitWebsite(const string& url) {
        // Jika history mencapai batas maksimum, hapus history paling lama
        if (history.size() == maxHistorySize) {
            history.pop_front();
        }
        
        history.push_back(url);
        cout << "Mengunjungi: " << url << endl;
    }
    
    // Melihat website saat ini (yang terakhir dikunjungi)
    void currentWebsite() {
        if (history.empty()) {
            cout << "Belum ada website yang dikunjungi!" << endl;
            return;
        }
        
        cout << "Website saat ini: " << history.back() << endl;
    }
    
    // Menampilkan website yang pertama dikunjungi
    void firstVisitedWebsite() {
        if (history.empty()) {
            cout << "Belum ada website yang dikunjungi!" << endl;
            return;
        }
        
        cout << "Website pertama yang dikunjungi: " << history.front() << endl;
    }
    
    // Mengakses elemen pada posisi tertentu
    void viewWebsiteAt(size_t position) {
        try {
            cout << "Website pada posisi " << position << ": " << history.at(position) << endl;
        } catch (const out_of_range& e) {
            cout << "Error: Posisi " << position << " diluar batas history! (Ukuran history: " << history.size() << ")" << endl;
        }
    }
    
    // Menambahkan website langsung ke awal history (misal: dari bookmark)
    void addToHistoryStart(const string& url) {
        history.push_front(url);
        cout << "Menambahkan " << url << " ke awal history" << endl;
        
        // Jika history melebihi batas maksimum, hapus history paling lama
        if (history.size() > maxHistorySize) {
            history.pop_back();
        }
    }
    
    // Menghapus website terakhir dari history (misalnya: undo)
    void removeLastWebsite() {
        if (history.empty()) {
            cout << "History sudah kosong!" << endl;
            return;
        }
        
        cout << "Menghapus " << history.back() << " dari history" << endl;
        history.pop_back();
    }
    
    // Menghapus website pertama dari history
    void removeFirstWebsite() {
        if (history.empty()) {
            cout << "History sudah kosong!" << endl;
            return;
        }
        
        cout << "Menghapus " << history.front() << " dari history" << endl;
        history.pop_front();
    }
    
    // Mengubah ukuran history
    void changeHistorySize(size_t newSize) {
        cout << "Mengubah ukuran history dari " << history.size() << " menjadi " << newSize << endl;
        
        // Jika ukuran baru lebih kecil, elemen terakhir akan dihapus
        history.resize(newSize);
        maxHistorySize = newSize;
    }
    
    // Membersihkan seluruh history
    void clearHistory() {
        cout << "Menghapus seluruh history (" << history.size() << " website)" << endl;
        history.clear();
    }
    
    // Menetapkan history baru (misalnya: restore dari backup)
    void restoreHistory(size_t count, const string& defaultSite) {
        cout << "Menetapkan history baru dengan " << count << " entri \"" << defaultSite << "\"" << endl;
        history.assign(count, defaultSite);
    }
    
    // Menyisipkan website di posisi tertentu
    void insertWebsite(size_t position, const string& url) {
        if (position > history.size()) {
            cout << "Posisi tidak valid! Maksimal posisi: " << history.size() << endl;
            return;
        }
        
        cout << "Menyisipkan " << url << " pada posisi " << position << endl;
        history.insert(history.begin() + position, url);
        
        // Jika history melebihi batas maksimum, hapus history paling lama
        if (history.size() > maxHistorySize) {
            history.pop_front();
        }
    }
    
    // Menghapus website di posisi tertentu
    void deleteWebsite(size_t position) {
        if (history.empty()) {
            cout << "History sudah kosong!" << endl;
            return;
        }
        
        if (position >= history.size()) {
            cout << "Posisi tidak valid! Maksimal posisi: " << (history.size() - 1) << endl;
            return;
        }
        
        cout << "Menghapus website pada posisi " << position << ": " << history[position] << endl;
        history.erase(history.begin() + position);
    }
    
    // Menukar history dengan browser lain
    void swapHistory(BrowserHistory& other) {
        cout << "Menukar history antara " << browserName << " dan " << other.browserName << endl;
        history.swap(other.history);
    }
    
    // Menampilkan seluruh history
    void displayHistory() {
        cout << "\n=== Browser History " << browserName << " (" << history.size() << " websites) ===" << endl;
        
        if (history.empty()) {
            cout << "History kosong!" << endl;
            return;
        }
        
        for (size_t i = 0; i < history.size(); ++i) {
            cout << i << ". " << history[i] << endl;
        }
        
        cout << "Kapasitas maksimum: " << maxHistorySize << " websites" << endl;
        cout << "Jumlah maksimal elemen yang dapat ditampung: " << history.max_size() << " websites" << endl;
    }
};

int main() {
    // Membuat objek browser history untuk dua browser
    BrowserHistory chrome("Chrome", 10);
    BrowserHistory firefox("Firefox", 5);
    
    // Menambahkan beberapa website ke history Chrome
    chrome.visitWebsite("google.com");
    chrome.visitWebsite("youtube.com");
    chrome.visitWebsite("github.com");
    chrome.visitWebsite("stackoverflow.com");
    chrome.visitWebsite("reddit.com");
    
    // Menambahkan beberapa website ke history Firefox
    firefox.visitWebsite("mozilla.org");
    firefox.visitWebsite("developer.mozilla.org");
    firefox.visitWebsite("addons.mozilla.org");
    
    // Menampilkan history kedua browser
    chrome.displayHistory();
    firefox.displayHistory();
    
    // Demonstrasi operator[]
    cout << "\n=== Demonstrasi Akses Elemen ===" << endl;
    
    // Menggunakan at() yang aman dengan exception handling
    chrome.viewWebsiteAt(2);
    chrome.viewWebsiteAt(10); // Ini akan menampilkan pesan error
    
    // Demonstrasi front() dan back()
    cout << "\n=== Demonstrasi front() dan back() ===" << endl;
    chrome.firstVisitedWebsite();
    chrome.currentWebsite();
    
    // Demonstrasi push_front() dan pop_front()
    cout << "\n=== Demonstrasi push_front() dan pop_front() ===" << endl;
    chrome.addToHistoryStart("startpage.com");
    chrome.displayHistory();
    chrome.removeFirstWebsite();
    chrome.displayHistory();
    
    // Demonstrasi push_back() dan pop_back()
    cout << "\n=== Demonstrasi push_back() dan pop_back() ===" << endl;
    chrome.visitWebsite("netflix.com");
    chrome.displayHistory();
    chrome.removeLastWebsite();
    chrome.displayHistory();
    
    // Demonstrasi insert() dan erase()
    cout << "\n=== Demonstrasi insert() dan erase() ===" << endl;
    chrome.insertWebsite(2, "amazon.com");
    chrome.displayHistory();
    chrome.deleteWebsite(1);
    chrome.displayHistory();
    
    // Demonstrasi resize()
    cout << "\n=== Demonstrasi resize() ===" << endl;
    chrome.changeHistorySize(3);
    chrome.displayHistory();
    
    // Demonstrasi assign()
    cout << "\n=== Demonstrasi assign() ===" << endl;
    firefox.restoreHistory(3, "default.com");
    firefox.displayHistory();
    
    // Demonstrasi swap()
    cout << "\n=== Demonstrasi swap() ===" << endl;
    chrome.swapHistory(firefox);
    chrome.displayHistory();
    firefox.displayHistory();
    
    // Demonstrasi clear()
    cout << "\n=== Demonstrasi clear() ===" << endl;
    chrome.clearHistory();
    chrome.displayHistory();
    
    return 0;
}