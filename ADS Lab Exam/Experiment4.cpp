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

// Function to display leaf nodes
void displayLeafNodes(Node* root) {

    if(root == NULL)
        return;

    // Leaf node
    if(root->left == NULL &&
       root->right == NULL) {

        cout << root->data << " ";
    }

    displayLeafNodes(root->left);

    displayLeafNodes(root->right);
}

int main() {

    cout << "Create Binary Tree\n";

    Node* root = createTree();

    cout << "\nLeaf Nodes: ";

    displayLeafNodes(root);

    return 0;
}