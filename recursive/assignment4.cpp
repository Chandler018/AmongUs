#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

struct User{
    string name;
    int day, month, year;
    int comments;
};

User users[20];
Node* adj[20];
int n;

void addFriends(int a, int b){
    Node* temp1 = new Node();
    temp1->data = b;
    temp1->next = adj[a];
    adj[a] = temp1;

    Node* temp2 = new Node();
    temp2->data = a;
    temp2->next = adj[b];
    adj[b] = temp2;
}

void maxFriends(){
    int maximum = -1;
    string person;

    for(int i=0;i<n;i++){
        int count = 0;
        Node* temp = adj[i];
        while(temp){
            count++;
            temp = temp->next;
        }

        if(count > maximum){
            maximum = count;
            person = users[i].name;
        }
    }

    cout<<"User with maximum friends: "<<person<<" ("<<maximum<<" friends)\n";
}

void maxMinComments(){
    int maxC = users[0].comments;
    int minC = users[0].comments;
    string maxUser = users[0].name;
    string minUser = users[0].name;

    for(int i=1;i<n;i++){
        if(users[i].comments > maxC){
            maxC = users[i].comments;
            maxUser = users[i].name;
        }

        if(users[i].comments < minC){
            minC = users[i].comments;
            minUser = users[i].name;
        }
    }

    cout<<"User with maximum comments: "<<maxUser<<" ("<<maxC<<")\n";
    cout<<"User with minimum comments: "<<minUser<<" ("<<minC<<")\n";
}

void birthdayMonth(){
    int m;
    cout<<"Enter month: ";
    cin>>m;

    cout<<"Users having birthday this month:\n";

    for(int i=0;i<n;i++){
        if(users[i].month == m)
            cout<<users[i].name<<endl;
    }
}

void DFS(int start){
    int stack[20];
    int visited[20]={0};
    int top=-1;

    stack[++top] = start;

    while(top!=-1){
        int v = stack[top--];

        if(!visited[v]){
            cout<<users[v].name<<" ";
            visited[v]=1;

            Node* temp = adj[v];
            while(temp){
                if(!visited[temp->data])
                    stack[++top] = temp->data;
                temp = temp->next;
            }
        }
    }
}

void BFS(int start){
    int queue[20];
    int visited[20]={0};
    int front=0,rear=0;

    queue[rear++] = start;
    visited[start]=1;

    while(front<rear){
        int v = queue[front++];

        cout<<users[v].name<<" ";

        Node* temp = adj[v];
        while(temp){
            if(!visited[temp->data]){
                visited[temp->data]=1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
}

int main(){

    cout<<"Enter number of users: ";
    cin>>n;

    for(int i=0;i<n;i++){
        adj[i]=NULL;
    }

    for(int i=0;i<n;i++){
        cout<<"Enter name: ";
        cin>>users[i].name;

        cout<<"Enter DOB (day month year): ";
        cin>>users[i].day>>users[i].month>>users[i].year;

        cout<<"Enter number of comments: ";
        cin>>users[i].comments;
    }

    int f;
    cout<<"Enter number of friendships: ";
    cin>>f;

    for(int i=0;i<f;i++){
        int a,b;
        cout<<"Enter friend pair index: ";
        cin>>a>>b;
        addFriends(a,b);
    }

    maxFriends();
    maxMinComments();
    birthdayMonth();

    cout<<"DFS Traversal: ";
    DFS(0);
    cout<<endl;

    cout<<"BFS Traversal: ";
    BFS(0);
    cout<<endl;

    return 0;
}
