#include <iostream>
using namespace std;

// Expression Tree Node
struct Node {
    char data;
    Node *left, *right;

    Node(char value) {
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

// Check operator
bool isOperator(char ch) {

    return (ch == '+' || ch == '-' ||
            ch == '*' || ch == '/');
}

// Construct Expression Tree
Node* constructTree(string postfix) {

    for(int i = 0; i < postfix.length(); i++) {

        char ch = postfix[i];

        // Operand
        if(!isOperator(ch)) {

            push(new Node(ch));
        }

        // Operator
        else {

            Node* temp = new Node(ch);

            temp->right = pop();
            temp->left = pop();

            push(temp);
        }
    }

    return pop();
}

// Inorder Traversal
void inorder(Node* root) {

    if(root != NULL) {

        if(isOperator(root->data))
            cout << "(";

        inorder(root->left);

        cout << root->data;

        inorder(root->right);

        if(isOperator(root->data))
            cout << ")";
    }
}

// Preorder Traversal
void preorder(Node* root) {

    if(root != NULL) {

        cout << root->data;

        preorder(root->left);

        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(Node* root) {

    if(root != NULL) {

        postorder(root->left);

        postorder(root->right);

        cout << root->data;
    }
}

int main() {

    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    Node* root = constructTree(postfix);

    cout << "\nInorder Expression: ";
    inorder(root);

    cout << "\nPreorder Expression: ";
    preorder(root);

    cout << "\nPostorder Expression: ";
    postorder(root);

    return 0;
}