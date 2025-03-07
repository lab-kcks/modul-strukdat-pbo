#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// Struktur untuk merepresentasikan pasien
struct Patient {
    string name;
    int urgencyLevel; // 1-10, di mana 10 adalah yang paling mendesak
    string complaint;
    
    Patient(string n, int u, string c) : name(n), urgencyLevel(u), complaint(c) {}
    
    // Operator overloading untuk membandingkan pasien
    // Perhatikan bahwa priority_queue secara default mengurutkan dari yang terbesar
    bool operator<(const Patient& other) const {
        return urgencyLevel < other.urgencyLevel;
    }
};

// Class untuk mengelola pasien di ruang gawat darurat
class EmergencyRoom {
private:
    priority_queue<Patient> patients;
    string hospitalName;

public:
    // Constructor
    EmergencyRoom(string name) : hospitalName(name) {
        cout << "Sistem triage untuk " << hospitalName << " telah diaktifkan!" << endl;
    }
    
    // Mendaftarkan pasien baru
    void registerPatient(const string& name, int urgencyLevel, const string& complaint) {
        if (urgencyLevel < 1 || urgencyLevel > 10) {
            cout << "Error: Level urgensi harus antara 1-10!" << endl;
            return;
        }
        
        Patient newPatient(name, urgencyLevel, complaint);
        patients.push(newPatient);
        
        cout << "Pasien " << name << " terdaftar dengan level urgensi " << urgencyLevel << endl;
        cout << "Keluhan: " << complaint << endl;
        cout << "Jumlah pasien dalam antrian: " << patients.size() << endl;
    }
    
    // Menangani pasien berikutnya (yang paling mendesak)
    void treatNextPatient() {
        if (patients.empty()) {
            cout << "Tidak ada pasien dalam antrian!" << endl;
            return;
        }
        
        Patient nextPatient = patients.top();
        cout << "\nMenangani pasien berikutnya:" << endl;
        cout << "Nama: " << nextPatient.name << endl;
        cout << "Level urgensi: " << nextPatient.urgencyLevel << endl;
        cout << "Keluhan: " << nextPatient.complaint << endl;
        
        patients.pop();
        cout << "Pasien telah ditangani." << endl;
        cout << "Sisa pasien dalam antrian: " << patients.size() << endl;
    }
    
    // Melihat pasien yang akan ditangani berikutnya
    void viewNextPatient() {
        if (patients.empty()) {
            cout << "Tidak ada pasien dalam antrian!" << endl;
            return;
        }
        
        Patient nextPatient = patients.top();
        cout << "\nPasien berikutnya yang akan ditangani:" << endl;
        cout << "Nama: " << nextPatient.name << endl;
        cout << "Level urgensi: " << nextPatient.urgencyLevel << endl;
        cout << "Keluhan: " << nextPatient.complaint << endl;
    }
    
    // Cek apakah antrian kosong
    bool isQueueEmpty() {
        return patients.empty();
    }
    
    // Mendapatkan jumlah pasien dalam antrian
    int getQueueSize() {
        return patients.size();
    }
    
    // Menukar antrian dengan rumah sakit lain
    void transferPatients(EmergencyRoom& other) {
        cout << "\nMentransfer pasien antara " << hospitalName << " dan " << other.hospitalName << endl;
        patients.swap(other.patients);
        cout << "Transfer selesai!" << endl;
        cout << hospitalName << " sekarang memiliki " << patients.size() << " pasien." << endl;
        cout << other.hospitalName << " sekarang memiliki " << other.patients.size() << " pasien." << endl;
    }
    
    // Menangani semua pasien dalam antrian
    void treatAllPatients() {
        cout << "\nMemulai operasi untuk menangani semua pasien di " << hospitalName << "..." << endl;
        
        if (patients.empty()) {
            cout << "Tidak ada pasien dalam antrian!" << endl;
            return;
        }
        
        int count = 0;
        while (!patients.empty()) {
            Patient patient = patients.top();
            patients.pop();
            
            count++;
            cout << "Menangani pasien #" << count << ":" << endl;
            cout << "Nama: " << patient.name << endl;
            cout << "Level urgensi: " << patient.urgencyLevel << endl;
            cout << "Keluhan: " << patient.complaint << endl;
            cout << "----------------------------------------" << endl;
        }
        
        cout << "Semua pasien telah ditangani. Antrian kosong." << endl;
    }
    
    // Membuat pasien dengan prioritas khusus
    class CustomPriorityQueue {
    private:
        // Ini adalah priority queue dengan aturan pengurutan kustom (min heap)
        // Pasien dengan level urgensi lebih rendah akan diutamakan (misal: untuk pasien VIP)
        priority_queue<Patient, vector<Patient>, greater<Patient>> vipPatients;
        
    public:
        void addVipPatient(const string& name, int urgencyLevel, const string& complaint) {
            Patient vip(name, urgencyLevel, complaint);
            vipPatients.push(vip);
            cout << "Pasien VIP " << name << " ditambahkan dengan prioritas khusus." << endl;
        }
        
        void treatNextVipPatient() {
            if (vipPatients.empty()) {
                cout << "Tidak ada pasien VIP dalam antrian!" << endl;
                return;
            }
            
            Patient nextVip = vipPatients.top();
            cout << "\nMenangani pasien VIP berikutnya:" << endl;
            cout << "Nama: " << nextVip.name << endl;
            cout << "Level urgensi: " << nextVip.urgencyLevel << endl;
            cout << "Keluhan: " << nextVip.complaint << endl;
            
            vipPatients.pop();
            cout << "Pasien VIP telah ditangani." << endl;
        }
        
        int getVipCount() {
            return vipPatients.size();
        }
    };
    
    // Instance dari custom priority queue
    CustomPriorityQueue vipQueue;
};

int main() {
    // Membuat objek ruang gawat darurat untuk dua rumah sakit
    EmergencyRoom generalHospital("RS Umum");
    EmergencyRoom specialistClinic("Klinik Spesialis");
    
    // Mendaftarkan beberapa pasien di RS Umum dengan berbagai level urgensi
    generalHospital.registerPatient("Ahmad", 7, "Patah kaki");
    generalHospital.registerPatient("Budi", 9, "Serangan jantung");
    generalHospital.registerPatient("Cindy", 3, "Sakit kepala");
    generalHospital.registerPatient("Dewi", 8, "Luka bakar serius");
    generalHospital.registerPatient("Eko", 5, "Demam tinggi");
    
    // Mendaftarkan beberapa pasien di Klinik Spesialis
    specialistClinic.registerPatient("Fani", 6, "Masalah pernapasan");
    specialistClinic.registerPatient("Gunawan", 10, "Kecelakaan parah");
    specialistClinic.registerPatient("Hendra", 4, "Infeksi kulit");
    
    // Melihat pasien berikutnya yang akan ditangani di kedua rumah sakit
    cout << "\n=== Pasien Prioritas ===" << endl;
    generalHospital.viewNextPatient();
    specialistClinic.viewNextPatient();
    
    // Menangani beberapa pasien di RS Umum
    cout << "\n=== Menangani Pasien RS Umum ===" << endl;
    generalHospital.treatNextPatient();
    generalHospital.treatNextPatient();
    
    // Menangani pasien di Klinik Spesialis
    cout << "\n=== Menangani Pasien Klinik Spesialis ===" << endl;
    specialistClinic.treatNextPatient();
    
    // Melihat pasien berikutnya setelah beberapa pasien ditangani
    cout << "\n=== Pasien Prioritas Terbaru ===" << endl;
    generalHospital.viewNextPatient();
    
    // Menukar pasien antara dua rumah sakit (misalnya: untuk pemerataan beban)
    generalHospital.transferPatients(specialistClinic);
    
    // Menggunakan custom priority queue untuk pasien VIP
    cout << "\n=== Pasien VIP ===" << endl;
    generalHospital.vipQueue.addVipPatient("Irene", 2, "Check-up rutin");
    generalHospital.vipQueue.addVipPatient("Joko", 1, "Konsultasi ringan");
    generalHospital.vipQueue.treatNextVipPatient();
    
    // Menangani semua pasien yang tersisa di Klinik Spesialis
    cout << "\n=== Menangani Semua Pasien Tersisa ===" << endl;
    specialistClinic.treatAllPatients();
    
    return 0;
}