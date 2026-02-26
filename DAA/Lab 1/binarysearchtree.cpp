#include <iostream>
using namespace std;

int iter = 0;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    iter++;  // comparison count
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Search in BST
bool search(Node* root, int key) {
    if (root == NULL)
        return false;

    iter++;  // comparison count
    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int n, x, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "\nInorder Traversal (Sorted Order): ";
    inorder(root);

    cout << "\n\nEnter value to search: ";
    cin >> key;

    if (search(root, key))
        cout << "Element found";
    else
        cout << "Element not found";

    cout << "\nTotal iterations: " << iter;

    return 0;
}

