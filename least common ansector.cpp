#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node* buildTree() {
    int value;
    cout << "Enter root node value: ";
    cin >> value;

    if (value == -1){
        return nullptr;
    }

    Node* root = new Node(value);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << "Enter left child of " << current->data << " (enter -1 for null): ";
        cin >> value;
        if (value != -1) {
            current->left = new Node(value);
            q.push(current->left);
        }

        cout<<"Enter right child "<< current->data << " (enter -1 for null): ";
        cin>>value;
        if(value != -1){
            current->right = new Node(value);
            q.push(current->right);
        }

        return root;
    }
}

Node* findLCA(Node*root, int n1, int n2){
    if (root == nullptr){
        return nullptr;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* left_lca = findLCA(root->left, n1, n2);
    Node* right_lca = findLCA(root->right, n1, n2);

    if(left_lca != nullptr && right_lca != nullptr){
        return root;
    }

    return (left_lca !=nullptr) ? left_lca : right_lca;
}

int main(){
    cout<<"create a binary tree "<<endl;
    Node* root = buildTree();

    int n1, n2;
    cout<<"enter first node value";
    cin>>n1;
    cout<<"enter secong node value";
    cin>>n2;

    Node* lca = findLCA(root, n1, n2);

    if(lca != nullptr){
        cout<<"LCA of "<<n1<<" and "<<n2<<" is "<<lca->data<<endl;
    }
    else{
        cout<<"LCA of "<<n1<<" and "<<n2<<" does not exist"<<endl;
    }

    return 0;
}