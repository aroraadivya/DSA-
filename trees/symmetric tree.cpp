#include<iostream>
using namespace std;

struct node{
    int value;
    node* left;
    node* right;
    node(int val=0) : value(val) ,left(nullptr), right(nullptr
    ) {}
};

class Solution {
public:
    bool isSymmetric(node* root){
        if (root == nullptr){
            return true;
        }
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(node* left, node* right){
        if(left == nullptr && right == nullptr){
            return true;
        }
        if(left == nullptr || right == nullptr){
            return false;
        }
        if(left->value != right->value){
            return false;
        }
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};

node* newnode(){
    int value;
    cout << "Enter node value (enter -1 for null): ";
    cin >> value;
    if (value == -1) {
        return nullptr;
    }

    node* newNode = new node(value);
    cout << "Enter left child of " << value << endl;
    newNode->left = newnode();
    cout << "Enter right child of " << value << endl;
    newNode->right = newnode();

    return newnode();
}


int main() {
    cout << "Create the binary tree:" << endl;
    node* root = newnode();

    Solution sol;
    bool result = sol.isSymmetric(root);
    cout << "The tree is " << (result ? "symmetric" : "not symmetric") << endl;

    return 0;
}