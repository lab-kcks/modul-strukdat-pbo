#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int key;
    string name;
    Node *left;
    Node *right;

    Node(int k, const string &n) : key(k), name(n), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree() : root(nullptr) {}

    Node *insert(Node *node, int key, const string &name)
    {
        if (!node)
            return new Node(key, name);
        if (key < node->key)
            node->left = insert(node->left, key, name);
        else
            node->right = insert(node->right, key, name);
        return node;
    }

    void insert(int key, const string &name)
    {
        root = insert(root, key, name);
    }

    void rotate_clockwise()
    {
        if (!root || !root->left)
            return;
        Node *new_root = root->left;
        root->left = new_root->right;
        new_root->right = root;
        root = new_root;
    }

    int find_depth(Node *node, const string &name, int depth)
    {
        if (!node)
            return -1;
        if (node->name == name)
            return depth;
        int d = find_depth(node->left, name, depth + 1);
        if (d != -1)
            return d;
        return find_depth(node->right, name, depth + 1);
    }

    int find_depth(const string &name)
    {
        return find_depth(root, name, 1);
    }

    bool exists(Node *node, const string &name)
    {
        if (!node)
            return false;
        if (node->name == name)
            return true;
        return exists(node->left, name) || exists(node->right, name);
    }

    bool exists(const string &name)
    {
        return exists(root, name);
    }
};

int main()
{
    BinaryTree tree;
    int N;
    cin >> N;
    string op;
    for (int i = 0; i < N; ++i)
    {
        cin >> op;
        if (op == "A")
        {
            int val;
            string name;
            cin >> val >> name;
            tree.insert(val, name);
        }
        else if (op == "C")
        {
            tree.rotate_clockwise();
        }
        else if (op == "B")
        {
            string s1, s2;
            cin >> s1 >> s2;
            if (!tree.exists(s1) || !tree.exists(s2))
                continue;
            int d1 = tree.find_depth(s1);
            int d2 = tree.find_depth(s2);
            if (d1 == d2)
            {
                cout << s1 << " dan " << s2 << " bersalaman" << endl;
            }
            else if (d1 > d2)
            {
                cout << s1 << " membungkuk " << (d1 - d2) << " kali ke " << s2 << endl;
            }
            else
            {
                cout << s2 << " membungkuk " << (d2 - d1) << " kali ke " << s1 << endl;
            }
        }
    }
    return 0;
}