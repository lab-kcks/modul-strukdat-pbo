#include <iostream>
using namespace std;

// Class Node
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Class Binary Tree
class BST
{
public:
    Node *root;
    BST() : root(nullptr) {}

    // Build binary tree dari level order
    void buildFromLevelOrder(int arr[], int n)
    {
        if (n == 0)
            return;
        root = new Node(arr[0]);

        Node *queue[100];
        int front = 0, rear = 0;
        queue[rear++] = root;

        int i = 1;
        while (i < n)
        {
            Node *current = queue[front++];
            if (i < n)
            {
                current->left = new Node(arr[i++]);
                queue[rear++] = current->left;
            }
            if (i < n)
            {
                current->right = new Node(arr[i++]);
                queue[rear++] = current->right;
            }
        }
    }

    // Inorder traversal untuk cari elemen ke-k
    void inorder(Node *node, int &count, int k, int &kthValue)
    {
        if (!node || count >= k)
            return;
        inorder(node->left, count, k, kthValue);
        count++;
        if (count == k)
        {
            kthValue = node->data;
            return;
        }
        inorder(node->right, count, k, kthValue);
    }

    // Cari elemen ke-k dari inorder traversal
    int findKthInorder(int k)
    {
        int count = 0, kthValue = -1;
        inorder(root, count, k, kthValue);
        return kthValue;
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> k[i];
    }

    BST tree;
    tree.buildFromLevelOrder(arr, n);

    cout << tree.findKthInorder(k[0]) << " "
         << tree.findKthInorder(k[1]) << " "
         << tree.findKthInorder(k[2]) << endl;

    return 0;
}