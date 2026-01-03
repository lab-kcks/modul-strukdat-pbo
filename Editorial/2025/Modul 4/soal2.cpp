#include <iostream>
using namespace std;

class AVLTree
{
private:
    // helper max
    static inline int max(int a, int b) { return a > b ? a : b; }

    // Node AVL Tree (private)
    struct Node
    {
        int index;
        char color;
        int height;
        Node *left;
        Node *right;
        Node(int idx, char col)
            : index(idx), color(col), height(1), left(nullptr), right(nullptr) {}
    };

    Node *root = nullptr;

    int getHeight(Node *n)
    {
        return n ? n->height : 0;
    }

    int getBalance(Node *n)
    {
        return getHeight(n->left) - getHeight(n->right);
    }

    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T = x->right;
        x->right = y;
        y->left = T;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }

    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T = y->left;
        y->left = x;
        x->right = T;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
    }

    Node *insert(Node *node, int idx, char col)
    {
        if (!node)
            return new Node(idx, col);
        if (idx < node->index)
            node->left = insert(node->left, idx, col);
        else if (idx > node->index)
            node->right = insert(node->right, idx, col);
        else
        {
            node->color = col;
            return node;
        }

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        int bal = getBalance(node);
        if (bal > 1 && idx < node->left->index)
            return rotateRight(node);
        if (bal < -1 && idx > node->right->index)
            return rotateLeft(node);
        if (bal > 1 && idx > node->left->index)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (bal < -1 && idx < node->right->index)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    char search(Node *node, int idx) const
    {
        if (!node)
            return 'W';
        if (idx == node->index)
            return node->color;
        return idx < node->index
                   ? search(node->left, idx)
                   : search(node->right, idx);
    }

    void printPixels(Node *node, int &cur, int N) const
    {
        if (!node)
            return;
        printPixels(node->left, cur, N);
        while (cur < node->index && cur <= N)
        {
            cout << 'W';
            ++cur;
        }
        if (cur == node->index)
        {
            cout << node->color;
            ++cur;
        }
        printPixels(node->right, cur, N);
    }

public:
    void update(int idx, char col)
    {
        root = insert(root, idx, col);
    }

    char query(int idx) const
    {
        return search(root, idx);
    }

    void printFinal(int N) const
    {
        int cur = 1;
        printPixels(root, cur, N);
        while (cur <= N)
        {
            cout << 'W';
            ++cur;
        }
        cout << '\n';
    }
};

int main()
{
    int N, T;
    cin >> N >> T;

    AVLTree tree;
    char *queryResults = new char[T];
    int qc = 0;

    for (int t = 0; t < T; ++t)
    {
        int type, i;
        cin >> type;
        if (type == 1)
        {
            char c;
            cin >> i >> c;
            tree.update(i, c);
        }
        else
        {
            cin >> i;
            queryResults[qc++] = tree.query(i);
        }
    }

    // output queries
    for (int j = 0; j < qc; ++j)
        cout << queryResults[j] << '\n';
    delete[] queryResults;

    // output final pixels
    tree.printFinal(N);
    return 0;
}