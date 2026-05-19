#include <iostream>
using namespace std;

// Structure for Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Function to create Binary Tree
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

// Preorder Traversal
void preorder(Node* root) {

    if(root != NULL) {

        cout << root->data << " ";

        preorder(root->left);

        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(Node* root) {

    if(root != NULL) {

        postorder(root->left);

        postorder(root->right);

        cout << root->data << " ";
    }
}

int main() {

    cout << "Create Binary Tree\n";

    Node* root = createTree();

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}