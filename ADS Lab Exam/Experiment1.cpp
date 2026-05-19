#include <iostream>
using namespace std;

// Structure for tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Insert node manually
Node* createTree() {

    int value;

    cout << "Enter node value (-1 for no node): ";
    cin >> value;

    // No node
    if(value == -1)
        return NULL;

    Node* root = new Node(value);

    cout << "Enter left child of " << value << endl;
    root->left = createTree();

    cout << "Enter right child of " << value << endl;
    root->right = createTree();

    return root;
}

// Inorder Traversal
void inorder(Node* root) {

    if(root != NULL) {

        inorder(root->left);

        cout << root->data << " ";

        inorder(root->right);
    }
}

int main() {

    cout << "Create Binary Tree\n";

    Node* root = createTree();

    cout << "\nInorder Traversal: ";

    inorder(root);

    return 0;
}