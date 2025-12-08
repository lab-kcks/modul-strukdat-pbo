#include <iostream>
using namespace std;

// Kelas Node
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Kelas LinkedList
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Menambahkan node di akhir
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Menampilkan isi linked list
    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Menggabungkan dua linked list terurut (fungsi static)
    static LinkedList merge(LinkedList& a, LinkedList& b) {
        Node* head1 = a.head;
        Node* head2 = b.head;

        LinkedList result;
        Node* mergedHead = nullptr;
        Node* mergedTail = nullptr;

        // Jika salah satu list kosong
        if (!head1) return b;
        if (!head2) return a;

        // Menentukan node pertama
        if (head1->data < head2->data) {
            mergedHead = mergedTail = new Node(head1->data);
            head1 = head1->next;
        } else {
            mergedHead = mergedTail = new Node(head2->data);
            head2 = head2->next;
        }

        // Proses penggabungan
        while (head1 && head2) {
            Node* temp;
            if (head1->data < head2->data) {
                temp = new Node(head1->data);
                head1 = head1->next;
            } else {
                temp = new Node(head2->data);
                head2 = head2->next;
            }
            mergedTail->next = temp;
            mergedTail = temp;
        }

        // Sisa elemen list
        while (head1) {
            mergedTail->next = new Node(head1->data);
            mergedTail = mergedTail->next;
            head1 = head1->next;
        }

        while (head2) {
            mergedTail->next = new Node(head2->data);
            mergedTail = mergedTail->next;
            head2 = head2->next;
        }

        result.head = mergedHead;
        return result;
    }
};

int main() {
    LinkedList kelasA, kelasB;
    int nA, nB, val;

    // Input Kelas A
    cin >> nA;
    for (int i = 0; i < nA; ++i) {
        cin >> val;
        kelasA.append(val);
    }

    // Input Kelas B
    cin >> nB;
    for (int i = 0; i < nB; ++i) {
        cin >> val;
        kelasB.append(val);
    }

    // Menampilkan daftar nilai kelas A dan B
    cout << "Kelas A: ";
    kelasA.print();

    cout << "Kelas B: ";
    kelasB.print();

    // Menggabungkan dan menampilkan hasil
    LinkedList hasilGabungan = LinkedList::merge(kelasA, kelasB);
    cout << "Nilai Gabungan: ";
    hasilGabungan.print();

    return 0;
}
