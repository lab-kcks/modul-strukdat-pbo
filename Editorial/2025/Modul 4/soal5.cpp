#include <iostream>
using namespace std;

// Class Node
class Node
{
public:
    int value;
    int height;
    Node *left;
    Node *right;

    // Konstruktor untuk Node
    Node(int val)
    {
        value = val;
        height = 1;
        left = right = nullptr;
    }
};

// Class AVL Tree
class AVLTree
{
private:
    Node *root;

    // Fungsi untuk mendapatkan tinggi node
    int height(Node *node)
    {
        return node ? node->height : 0;
    }

    // Fungsi untuk mendapatkan balance factor
    int getBalance(Node *node)
    {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // Fungsi untuk melakukan rotasi kanan
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    // Fungsi untuk melakukan rotasi kiri
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    // Fungsi untuk memasukkan node ke dalam AVL Tree
    Node *insert(Node *node, int value)
    {
        if (!node)
            return new Node(value);

        if (value < node->value)
            node->left = insert(node->left, value);
        else if (value > node->value)
            node->right = insert(node->right, value);
        else
            return node;

        node->height = max(height(node->left), height(node->right)) + 1;

        int balance = getBalance(node);

        if (balance > 1 && value < node->left->value)
            return rightRotate(node);
        if (balance < -1 && value > node->right->value)
            return leftRotate(node);
        if (balance > 1 && value > node->left->value)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && value < node->right->value)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Fungsi untuk menghitung jumlah node kiri dan kanan
    void countNodes(Node *node, int &leftCount, int &rightCount)
    {
        if (!node)
            return;
        if (node->left)
            countNodes(node->left, leftCount, rightCount);
        if (node->right)
            countNodes(node->right, leftCount, rightCount);
        if (node == root)
            return;
        if (node->value < root->value)
            leftCount++;
        else
            rightCount++;
    }

public:
    AVLTree() { root = nullptr; }

    // Fungsi untuk memasukkan node ke dalam AVL Tree
    void insert(int value)
    {
        root = insert(root, value);
    }

    // Fungsi untuk melakukan pengecekan kebenaran
    void checkBalance()
    {
        if (!root)
        {
            cout << "Kebenaran" << endl;
            return;
        }
        int leftCount = 0, rightCount = 0;
        countNodes(root, leftCount, rightCount);
        if (leftCount > rightCount)
            cout << "Keraguan" << endl;
        else if (leftCount < rightCount)
            cout << "Kepercayaan" << endl;
        else
            cout << "Kebenaran" << endl;
    }
};

int main()
{
    int N;
    cin >> N;

    AVLTree avl;

    while (N--)
    {
        string command;
        cin >> command;
        if (command == "I")
        {
            int X;
            cin >> X;
            avl.insert(X);
        }
        else if (command == "S")
        {
            avl.checkBalance();
        }
    }

    return 0;
}
