# include <iostream>
# include <stack>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
    Node(char val){
        data = val;
        left = right = nullptr;
    }
};

Node* buildTree(string postfix){
    stack<Node*> st;
    for (char ch : postfix){
        if (isalnum(ch)){  
            st.push(new Node(ch));
        }else{  
            Node* right = st.top(); 
            st.pop();
            Node* left = st.top(); 
            st.pop();
            Node* opNode = new Node(ch);
            opNode->left = left;
            opNode->right = right;
            st.push(opNode);
        }
    }
    return st.top();
}

void inorderRec(Node* root){
    if(!root) return;
    inorderRec(root->left);
    cout<<root->data<<" ";
    inorderRec(root->right);
}

void preorderRec(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorderRec(root->left);
    preorderRec(root->right);
}

void postorderRec(Node* root){
    if (!root) return;
    postorderRec(root->left);
    postorderRec(root->right);
    cout<<root->data<<" ";
}

void inordernr(Node* root){
    stack<Node*> st;
    Node* curr = root;
    while(curr || !st.empty()){
        while(curr){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); 
        st.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}

void preordernr(Node* root){
    if (!root) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* node = st.top(); 
        st.pop();
        cout<<node->data<<" ";
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
}

void postordernr(Node* root){
    if(!root) return;
    stack<Node*> st1, st2;
    st1.push(root);
    while (!st1.empty()){
        Node* node = st1.top(); 
        st1.pop();
        st2.push(node);
        if(node->left) st1.push(node->left);
        if(node->right) st1.push(node->right);
    }
    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}

int main(){
    string postfix = "AB*C+";  // Example: (A*B)+C
    cout<<"Postfix: "<<postfix<<endl;
    
    Node* root = buildTree(postfix);
    
    cout<<"\nRecursive Traversals:"<<endl;
    cout<<"Inorder: ";inorderRec(root); cout<<endl;
    cout<<"Preorder: ";preorderRec(root); cout<<endl;
    cout<<"Postorder: "; postorderRec(root); cout<<endl;
    
    cout<<"\nNon-Recursive Traversals:"<<endl;
    cout<<"Inorder: ";inordernr(root); cout<<endl;
    cout<<"Preorder: ";preordernr(root); cout<<endl;
    cout<<"Postorder: ";postordernr(root); cout<<endl;
    
    return 0;
}
