#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node *buildTree()
{
    int value;
    cout << "Enter root node value: ";
    cin >> value;

    if (value == -1)
    {
        return nullptr;
    }

    Node *root = new Node(value);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << "Enter left child of " << current->data << " (enter -1 for null): ";
        cin >> value;
        if (value != -1)
        {
            current->left = new Node(value);
            q.push(current->left);
        }

        cout << "Enter right child " << current->data << " (enter -1 for null): ";
        cin >> value;
        if (value != -1)
        {
            current->right = new Node(value);
            q.push(current->right);
        }

        return root;
    }
}

int height(Node *root){
    if(root == nullptr){
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

bool isbalanced(Node*root){
    if(root == nullptr){
        return true;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return abs(leftHeight - rightHeight) <=1 && isbalanced(root->left) && isbalanced(root->right);
}




    int main()
    {
        cout << "create a binary tree " << endl;
        Node *root = buildTree();

        cout << "Is the tree balanced? " << (isBalanced(bstRoot) ? "Yes" : "No") << endl;

        return 0;
    }