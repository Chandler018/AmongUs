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

    return (ch=='+' || ch=='-' ||
            ch=='*' || ch=='/');
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

// Iterative Inorder
void inorder(Node* root) {

    Node* curr = root;

    while(curr || top != -1) {

        while(curr) {

            push(curr);
            curr = curr->left;
        }

        curr = pop();

        cout << curr->data;

        curr = curr->right;
    }
}

// Iterative Preorder
void preorder(Node* root) {

    push(root);

    while(top != -1) {

        Node* temp = pop();

        cout << temp->data;

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

        cout << s2[top2--]->data;
    }
}

int main() {

    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    Node* root = constructTree(postfix);

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