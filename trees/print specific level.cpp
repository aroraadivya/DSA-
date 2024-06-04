#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d) : data(d), left(nullptr), right(nullptr){}
};

Node *buildtree(){
    int value;
    cout<<"Enter Value";
    cin>>value;

    if(value == -1){
        return nullptr;
    }

    Node *root = new Node(value);
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        Node *current = q.front();
        q.pop();

        cout<<"enter left child"<< current->data<<endl;
        cin>>value;
        if(value == -1){
            current->left = new Node(value);
            q.push(current->left);
        }

        cout<<"enter right child"<< current->data<<endl;
        cin>>value;
        if(value == -1){
            current->right = new Node(value);
            q.push(current->right);
        }

        return root;
    }
}

//print specific level

void printspecificlevel(Node *root, int level){
    if(root == nullptr){
        return;
    }
    if(level == 1){
        cout<< root->data<<" ";
    }
    else if(level>1){
        printspecificlevel(root->left, level-1);
        printspecificlevel(root->right, level-1);
    }
}

//inorder transversal
void inordertransveral(Node *root, vector<int> &values){
    if(root == nullptr){
        return;
    }
    inordertransveral(root->left, values);
    values.push_back(root->data);
    inordertransveral(root->right, values);
}
//convert to bst
Node *converttobst(vector<int> &values, int start, int end){
    if(start>end){
        return;
    }

    int mid = start+(end-start)/2;
    Node *root = new Node(values[mid]);

    root->left = converttobst(root->left, start, mid-1);
    root->right = converttobst(root->right, mid+1, end);
    return root;
}

//binary tree to bst
Node *binarytreetobst(Node *root){
    vector<int> values;
    inordertransveral(root, values);
    sort(values.begin(), values.end());
    return converttobst(values, 0, values.size() -1);
}


int main(){
    cout<<"create a binary tree";
    Node *root = buildtree();

    int specificlevel;
    cout<<"enter the level you want to print";
    cin>>specificlevel;
    cout<<"nodes at level"<< specificlevel<<"are: ";
    printspecificlevel(root, specificlevel);
    cout<<endl;
    return 0;
}