#include <iostream>
#include <array>
#include <string>

class StudentRecord {
private:
    std::array<int, 5> scores;
    std::string name;

public:
    // Constructor
    StudentRecord(const std::string& studentName) : name(studentName) {
        scores.fill(0); // Menggunakan fill() untuk mengisi semua elemen dengan 0
    }

    // Setter untuk skor dengan index tertentu
    void setScore(size_t index, int value) {
        if (index < scores.size()) {
            scores[index] = value; // Menggunakan operator[] untuk mengakses elemen
        } else {
            std::cout << "Index di luar batas!" << std::endl;
        }
    }

    // Setter untuk skor dengan index tertentu (menggunakan at() dengan exception handling)
    void setScoreSafe(size_t index, int value) {
        try {
            scores.at(index) = value; // Menggunakan at() yang lebih aman dengan exception handling
        } catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    // Mendapatkan skor tertinggi
    int getHighestScore() const {
        int highest = scores.front(); // Menggunakan front() untuk mendapatkan elemen pertama
        for (auto it = scores.begin(); it != scores.end(); ++it) { // Menggunakan begin() dan end() untuk iterasi
            if (*it > highest) {
                highest = *it;
            }
        }
        return highest;
    }

    // Mendapatkan skor terendah
    int getLowestScore() const {
        int lowest = scores.front();
        for (const auto& score : scores) { // Iterasi menggunakan range-based for loop
            if (score < lowest && score != 0) {
                lowest = score;
            }
        }
        return lowest;
    }

    // Menukar data dengan record lain
    void swapWith(StudentRecord& other) {
        scores.swap(other.scores); // Menggunakan swap() untuk menukar isi array
        std::string tempName = name;
        name = other.name;
        other.name = tempName;
    }

    // Memeriksa apakah semua skor telah diisi
    bool isComplete() const {
        return !scores.empty() && scores.back() != 0; // Menggunakan empty() dan back()
    }

    // Mendapatkan jumlah maksimum skor yang dapat disimpan
    size_t getMaxScores() const {
        return scores.max_size(); // Menggunakan max_size()
    }

    // Mendapatkan jumlah skor yang tersimpan
    size_t getScoreCount() const {
        return scores.size(); // Menggunakan size()
    }

    // Menampilkan data siswa
    void display() const {
        std::cout << "Nama Siswa: " << name << std::endl;
        std::cout << "Skor: ";
        for (const auto& score : scores) {
            std::cout << score << " ";
        }
        std::cout << std::endl;
        std::cout << "Skor Tertinggi: " << getHighestScore() << std::endl;
        std::cout << "Skor Terendah: " << getLowestScore() << std::endl;
        std::cout << "Jumlah Skor: " << getScoreCount() << std::endl;
    }
};

int main() {
    // Membuat objek StudentRecord
    StudentRecord student1("Budi");
    StudentRecord student2("Ani");

    // Menggunakan berbagai metode
    student1.setScore(0, 85);
    student1.setScore(1, 90);
    student1.setScore(2, 78);
    student1.setScore(3, 92);
    student1.setScore(4, 88);

    student2.setScore(0, 75);
    student2.setScore(1, 82);
    student2.setScoreSafe(2, 79);
    student2.setScoreSafe(3, 81);
    student2.setScoreSafe(4, 77);

    // Menampilkan data sebelum swap
    std::cout << "=== Data Sebelum Swap ===" << std::endl;
    student1.display();
    std::cout << std::endl;
    student2.display();

    // Menukar data antara student1 dan student2
    student1.swapWith(student2);

    // Menampilkan data setelah swap
    std::cout << "\n=== Data Setelah Swap ===" << std::endl;
    student1.display();
    std::cout << std::endl;
    student2.display();

    // Mencoba mengakses index yang tidak valid
    std::cout << "\n=== Pengujian Exception Handling ===" << std::endl;
    student1.setScoreSafe(10, 100); // Akan memunculkan pesan error

    return 0;
}