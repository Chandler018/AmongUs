#include <iostream>
using namespace std;

// BST Node
struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Insert node
Node* insert(Node* root, int value) {

    if(root == NULL)
        return new Node(value);

    if(value < root->data)
        root->left = insert(root->left, value);

    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// BFS Traversal
void BFS(Node* root) {

    Node* queue[100];

    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear) {

        Node* temp = queue[front++];

        cout << temp->data << " ";

        if(temp->left != NULL)
            queue[rear++] = temp->left;

        if(temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

int main() {

    Node* root = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {

        cout << "Enter value: ";
        cin >> value;

        root = insert(root, value);
    }

    cout << "\nBFS Traversal: ";

    BFS(root);

    return 0;
}