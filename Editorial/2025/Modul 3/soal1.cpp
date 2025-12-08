#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    struct StackNode
    {
        char data;
        StackNode *next;
        StackNode(char value) : data(value), next(nullptr) {}
    };

    StackNode *_top;
    unsigned _size;

public:
    Stack()
    {
        _top = nullptr;
        _size = 0;
    }

    ~Stack()
    {
        while (!isEmpty())
            pop();
    }

    bool isEmpty() const
    {
        return (_top == nullptr);
    }

    unsigned size() const
    {
        return _size;
    }

    void push(char value)
    {
        StackNode *newNode = new StackNode(value);
        newNode->next = _top;
        _top = newNode;
        _size++;
    }

    void pop()
    {
        if (!isEmpty())
        {
            StackNode *temp = _top;
            _top = _top->next;
            delete temp;
            _size--;
        }
    }

    char top() const
    {
        if (!isEmpty())
            return _top->data;
        return '\0';
    }

    bool remove(char value)
    {
        StackNode *curr = _top; // Mulai dari node teratas
        StackNode *prev = nullptr;
        while (curr)
        {
            if (curr->data == value)
            {
                // Jika node ditemukan, hapus dari chain
                if (prev)
                    prev->next = curr->next;
                else
                    _top = curr->next; // Jika yang dihapus node teratas
                delete curr;
                _size--;
                return true; // Berhasil dihapus
            }
            prev = curr;       // Simpan node sebelumnya
            curr = curr->next; // Pindah ke node berikutnya
        }
        return false; // Nilai tidak ditemukan
    }
};

char matchingOpening(char c)
{
    switch (c)
    {
    case ')':
        return '(';
    case '}':
        return '{';
    case ']':
        return '[';
    default:
        return '\0';
    }
}

int main()
{
    string input;
    getline(cin, input);

    Stack bracketStack;
    int closedCount = 0;

    for (char c : input)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            bracketStack.push(c); // kalo menemukan bracket pembuka, push ke stack
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            // kalo bracket penutup, cari pasangan pembuka yang cocok
            char openChar = matchingOpening(c);
            if (bracketStack.remove(openChar))
            {
                closedCount++; // kalo berhasil menghapus pasangan pembuka dari stack
            }
            else
            {
                cout << "LUPA NUTUP" << endl; // kalo tidak ada pasangan pembuka yang cocok atau blm ditutup
                return 0;
            }
        }
    }

    // Jika masih ada, berarti ada bracket yang belum ditutup
    if (!bracketStack.isEmpty())
        cout << "LUPA NUTUP" << endl; // Ada bracket pembuka yang tak tertutup
    else
        cout << closedCount << endl; // Semua bracket cocok, tampilkan jumlah

    return 0;
}