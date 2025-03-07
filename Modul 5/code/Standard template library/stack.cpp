#include <iostream>
#include <stack>
#include <string>

using namespace std;

class BookStack {
private:
    stack<string> books;
    string stackName;

public:
    // Constructor
    BookStack(const string& name) : stackName(name) {
        cout << "Stack buku '" << stackName << "' telah dibuat" << endl;
    }

    // Menambahkan buku ke stack
    void addBook(const string& bookTitle) {
        books.push(bookTitle);
        cout << "Buku '" << bookTitle << "' ditambahkan ke stack '" << stackName << "'" << endl;
    }

    // Mengambil buku teratas
    string takeTopBook() {
        if (books.empty()) {
            cout << "Stack '" << stackName << "' kosong, tidak ada buku yang bisa diambil" << endl;
            return "";
        }

        string topBook = books.top();
        books.pop();
        cout << "Buku '" << topBook << "' diambil dari stack '" << stackName << "'" << endl;
        return topBook;
    }

    // Melihat buku teratas tanpa mengambilnya
    string peekTopBook() const {
        if (books.empty()) {
            cout << "Stack '" << stackName << "' kosong" << endl;
            return "";
        }

        cout << "Buku teratas di stack '" << stackName << "' adalah '" << books.top() << "'" << endl;
        return books.top();
    }

    // Mengecek apakah stack kosong
    bool isEmpty() const {
        return books.empty();
    }

    // Mendapatkan jumlah buku di stack
    int getBookCount() const {
        return books.size();
    }

    // Menukar isi dengan stack lain
    void swapWith(BookStack& otherStack) {
        books.swap(otherStack.books);
        cout << "Stack '" << stackName << "' ditukar dengan stack '" << otherStack.stackName << "'" << endl;
    }

    // Menampilkan semua buku dalam stack (tanpa mengubah stack asli)
    void displayBooks() const {
        if (books.empty()) {
            cout << "Stack '" << stackName << "' kosong" << endl;
            return;
        }

        cout << "Buku dalam stack '" << stackName << "' (dari atas ke bawah):" << endl;
        
        // Buat salinan stack untuk ditampilkan
        stack<string> tempStack = books;
        int position = 1;
        
        while (!tempStack.empty()) {
            cout << position << ". " << tempStack.top() << endl;
            tempStack.pop();
            position++;
        }
    }
};

int main() {
    // Membuat dua stack buku
    BookStack fictionBooks("Fiksi");
    BookStack nonFictionBooks("Non-Fiksi");

    // Menambahkan buku ke stack fiksi
    fictionBooks.addBook("Harry Potter");
    fictionBooks.addBook("Lord of the Rings");
    fictionBooks.addBook("Game of Thrones");

    // Menambahkan buku ke stack non-fiksi
    nonFictionBooks.addBook("Atomic Habits");
    nonFictionBooks.addBook("Sapiens");

    // Menampilkan semua buku di kedua stack
    fictionBooks.displayBooks();
    nonFictionBooks.displayBooks();

    // Melihat buku teratas di stack fiksi
    fictionBooks.peekTopBook();

    // Mengambil buku teratas dari stack fiksi
    string takenBook = fictionBooks.takeTopBook();
    cout << "Buku yang diambil: " << takenBook << endl;

    // Menampilkan stack fiksi setelah pengambilan buku
    fictionBooks.displayBooks();

    // Menukar kedua stack
    fictionBooks.swapWith(nonFictionBooks);

    // Menampilkan stack setelah ditukar
    cout << "\nSetelah pertukaran stack:" << endl;
    fictionBooks.displayBooks();
    nonFictionBooks.displayBooks();

    // Mengecek jumlah buku
    cout << "Jumlah buku di stack Fiksi: " << fictionBooks.getBookCount() << endl;
    cout << "Jumlah buku di stack Non-Fiksi: " << nonFictionBooks.getBookCount() << endl;

    // Mengecek apakah stack kosong
    cout << "Apakah stack Fiksi kosong? " << (fictionBooks.isEmpty() ? "Ya" : "Tidak") << endl;

    return 0;
}