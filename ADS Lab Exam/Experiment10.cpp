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

// Stack using array
Node* stack[100];
int top = -1;

void push(Node* x) {
    stack[++top] = x;
}

Node* pop() {
    return stack[top--];
}

bool isEmpty() {
    return top == -1;
}

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

// Iterative Inorder
void inorder(Node* root) {

    Node* curr = root;

    while(curr || !isEmpty()) {

        while(curr) {

            push(curr);
            curr = curr->left;
        }

        curr = pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}

// Iterative Preorder
void preorder(Node* root) {

    push(root);

    while(!isEmpty()) {

        Node* temp = pop();

        cout << temp->data << " ";

        if(temp->right)
            push(temp->right);

        if(temp->left)
            push(temp->left);
    }
}

// Iterative Postorder
void postorder(Node* root) {

    Node* s1[100];
    Node* s2[100];

    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    while(top1 != -1) {

        Node* temp = s1[top1--];

        s2[++top2] = temp;

        if(temp->left)
            s1[++top1] = temp->left;

        if(temp->right)
            s1[++top1] = temp->right;
    }

    while(top2 != -1) {

        cout << s2[top2--]->data << " ";
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

    top = -1;
    cout << "\nIterative Inorder: ";
    inorder(root);

    top = -1;
    cout << "\nIterative Preorder: ";
    preorder(root);

    cout << "\nIterative Postorder: ";
    postorder(root);

    return 0;
}