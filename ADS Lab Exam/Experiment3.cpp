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

// Function to calculate height
int height(Node* root) {

    if(root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight > rightHeight)
        return leftHeight + 1;

    else
        return rightHeight + 1;
}

int main() {

    cout << "Create Binary Tree\n";

    Node* root = createTree();

    cout << "\nHeight of Binary Tree = "
         << height(root);

    return 0;
}