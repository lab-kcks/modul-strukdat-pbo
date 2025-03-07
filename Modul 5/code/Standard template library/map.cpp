#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

// Class untuk mengelola katalog perpustakaan
class LibraryCatalog {
private:
    map<string, map<string, string>> books; // ISBN -> {title, author, genre, year, status}
    string libraryName;

public:
    // Constructor
    LibraryCatalog(string name) : libraryName(name) {
        cout << "Katalog Perpustakaan untuk " << libraryName << " telah dibuat!" << endl;
    }
    
    // Menambahkan buku ke katalog
    void addBook(const string& isbn, const string& title, const string& author, 
                 const string& genre, const string& year) {
        
        // Membuat map untuk detail buku
        map<string, string> bookDetails;
        bookDetails["title"] = title;
        bookDetails["author"] = author;
        bookDetails["genre"] = genre;
        bookDetails["year"] = year;
        bookDetails["status"] = "Available"; // Default status
        
        // Memeriksa apakah ISBN sudah ada
        if (books.find(isbn) != books.end()) {
            cout << "Buku dengan ISBN " << isbn << " sudah ada dalam katalog!" << endl;
            return;
        }
        
        // Memasukkan buku ke katalog
        books.insert(make_pair(isbn, bookDetails));
        
        cout << "Buku berhasil ditambahkan:" << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Judul: " << title << endl;
        cout << "Penulis: " << author << endl;
        cout << "Genre: " << genre << endl;
        cout << "Tahun: " << year << endl;
    }
    
    // Mengakses informasi buku dengan operator[]
    void getBookInfo(const string& isbn) {
        if (books.find(isbn) == books.end()) {
            cout << "Buku dengan ISBN " << isbn << " tidak ditemukan!" << endl;
            return;
        }
        
        cout << "\nInformasi Buku:" << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Judul: " << books[isbn]["title"] << endl;
        cout << "Penulis: " << books[isbn]["author"] << endl;
        cout << "Genre: " << books[isbn]["genre"] << endl;
        cout << "Tahun: " << books[isbn]["year"] << endl;
        cout << "Status: " << books[isbn]["status"] << endl;
    }
    
    // Memperbarui status buku (dipinjam/tersedia)
    void updateBookStatus(const string& isbn, const string& newStatus) {
        if (books.find(isbn) == books.end()) {
            cout << "Buku dengan ISBN " << isbn << " tidak ditemukan!" << endl;
            return;
        }
        
        books[isbn]["status"] = newStatus;
        cout << "Status buku " << books[isbn]["title"] << " diperbarui menjadi: " << newStatus << endl;
    }
    
    // Menghapus buku dari katalog
    void removeBook(const string& isbn) {
        if (books.find(isbn) == books.end()) {
            cout << "Buku dengan ISBN " << isbn << " tidak ditemukan!" << endl;
            return;
        }
        
        string title = books[isbn]["title"];
        books.erase(isbn);
        cout << "Buku " << title << " dengan ISBN " << isbn << " telah dihapus dari katalog." << endl;
    }
    
    // Mencari buku berdasarkan judul (partial search)
    void searchByTitle(const string& titleQuery) {
        cout << "\nHasil pencarian untuk judul \"" << titleQuery << "\":" << endl;
        
        bool found = false;
        for (auto& book : books) {
            if (book.second["title"].find(titleQuery) != string::npos) {
                cout << "ISBN: " << book.first << ", Judul: " << book.second["title"] 
                     << ", Penulis: " << book.second["author"] << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "Tidak ditemukan buku dengan judul yang mengandung \"" << titleQuery << "\"." << endl;
        }
    }
    
    // Mencari buku berdasarkan penulis
    void searchByAuthor(const string& authorQuery) {
        cout << "\nHasil pencarian untuk penulis \"" << authorQuery << "\":" << endl;
        
        bool found = false;
        for (auto& book : books) {
            if (book.second["author"].find(authorQuery) != string::npos) {
                cout << "ISBN: " << book.first << ", Judul: " << book.second["title"] 
                     << ", Penulis: " << book.second["author"] << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "Tidak ditemukan buku dengan penulis yang mengandung \"" << authorQuery << "\"." << endl;
        }
    }
    
    // Menghitung jumlah buku per genre
    void countBooksByGenre() {
        map<string, int> genreCounts;
        
        for (auto& book : books) {
            genreCounts[book.second["genre"]]++;
        }
        
        cout << "\nJumlah Buku per Genre:" << endl;
        for (auto& genre : genreCounts) {
            cout << genre.first << ": " << genre.second << " buku" << endl;
        }
    }
    
    // Mencari jumlah buku dengan status tertentu
    int countBooksByStatus(const string& status) {
        int count = 0;
        
        for (auto& book : books) {
            if (book.second["status"] == status) {
                count++;
            }
        }
        
        return count;
    }
    
    // Menampilkan seluruh katalog
    void displayCatalog() {
        cout << "\n=== Katalog Perpustakaan " << libraryName << " (" << books.size() << " buku) ===" << endl;
        
        if (books.empty()) {
            cout << "Katalog kosong!" << endl;
            return;
        }
        
        cout << left << setw(15) << "ISBN" << setw(30) << "Judul" << setw(20) << "Penulis" 
             << setw(15) << "Genre" << setw(10) << "Tahun" << setw(15) << "Status" << endl;
        cout << string(105, '-') << endl;
        
        for (auto it = books.begin(); it != books.end(); ++it) {
            cout << left << setw(15) << it->first << setw(30) << it->second["title"] 
                 << setw(20) << it->second["author"] << setw(15) << it->second["genre"] 
                 << setw(10) << it->second["year"] << setw(15) << it->second["status"] << endl;
        }
        
        cout << "\nTotal buku dalam katalog: " << books.size() << endl;
        cout << "Buku tersedia: " << countBooksByStatus("Available") << endl;
        cout << "Buku dipinjam: " << countBooksByStatus("Borrowed") << endl;
    }
    
    // Menukar katalog dengan perpustakaan lain
    void swapCatalog(LibraryCatalog& other) {
        cout << "\nMenukar katalog antara " << libraryName << " dan " << other.libraryName << endl;
        books.swap(other.books);
        cout << "Pertukaran selesai!" << endl;
    }
    
    // Membersihkan seluruh katalog
    void clearCatalog() {
        int count = books.size();
        books.clear();
        cout << "Seluruh katalog dibersihkan. " << count << " buku dihapus dari sistem." << endl;
    }
    
    // Mendapatkan ukuran maksimum map
    void showMapCapacity() {
        cout << "Kapasitas maksimum katalog: " << books.max_size() << " entri." << endl;
    }
};

int main() {
    // Membuat objek katalog untuk dua perpustakaan
    LibraryCatalog centralLibrary("Perpustakaan Pusat");
    LibraryCatalog branchLibrary("Perpustakaan Cabang");
    
    // Menambahkan beberapa buku ke katalog Perpustakaan Pusat
    centralLibrary.addBook("978-0451524935", "1984", "George Orwell", "Dystopian", "1949");
    centralLibrary.addBook("978-0061120084", "To Kill a Mockingbird", "Harper Lee", "Fiction", "1960");
    centralLibrary.addBook("978-0141439518", "Pride and Prejudice", "Jane Austen", "Romance", "1813");
    centralLibrary.addBook("978-0307474278", "The Da Vinci Code", "Dan Brown", "Mystery", "2003");
    centralLibrary.addBook("978-0316769488", "The Catcher in the Rye", "J.D. Salinger", "Fiction", "1951");
    
    // Menambahkan beberapa buku ke katalog Perpustakaan Cabang
    branchLibrary.addBook("978-0553296983", "The Ultimate Hitchhiker's Guide to the Galaxy", "Douglas Adams", "Sci-Fi", "1979");
    branchLibrary.addBook("978-0544003415", "The Lord of the Rings", "J.R.R. Tolkien", "Fantasy", "1954");
    branchLibrary.addBook("978-0060935467", "To Kill a Mockingbird", "Harper Lee", "Fiction", "1960");
    
    // Menampilkan katalog kedua perpustakaan
    centralLibrary.displayCatalog();
    branchLibrary.displayCatalog();
    
    // Demonstrasi operator[] dan find()
    cout << "\n=== Demonstrasi Akses dan Pencarian ===" << endl;
    centralLibrary.getBookInfo("978-0451524935");
    centralLibrary.getBookInfo("978-1234567890"); // ISBN yang tidak ada
    
    // Demonstrasi update status
    cout << "\n=== Demonstrasi Update Status ===" << endl;
    centralLibrary.updateBookStatus("978-0061120084", "Borrowed");
    centralLibrary.getBookInfo("978-0061120084");
    
    // Demonstrasi pencarian
    cout << "\n=== Demonstrasi Pencarian ===" << endl;
    centralLibrary.searchByTitle("the");
    centralLibrary.searchByAuthor("Orwell");
    
    // Demonstrasi count dan statistik
    cout << "\n=== Demonstrasi Statistik ===" << endl;
    centralLibrary.countBooksByGenre();
    cout << "Jumlah buku yang dipinjam: " << centralLibrary.countBooksByStatus("Borrowed") << endl;
    
    // Demonstrasi erase
    cout << "\n=== Demonstrasi Penghapusan ===" << endl;
    centralLibrary.removeBook("978-0307474278");
    centralLibrary.displayCatalog();
    
    // Demonstrasi swap
    cout << "\n=== Demonstrasi Swap ===" << endl;
    centralLibrary.swapCatalog(branchLibrary);
    centralLibrary.displayCatalog();
    branchLibrary.displayCatalog();
    
    // Demonstrasi max_size
    cout << "\n=== Demonstrasi Kapasitas ===" << endl;
    centralLibrary.showMapCapacity();
    
    // Demonstrasi clear
    cout << "\n=== Demonstrasi Clear ===" << endl;
    branchLibrary.clearCatalog();
    branchLibrary.displayCatalog();
    
    return 0;
}