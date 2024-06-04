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

void zigzagTransversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<Node *> currentlevel;
    stack<Node *> nextlevel;
    bool lefttoright = true;

    while (!currentlevel.empty())
    {
        Node *node = currentlevel.top();
        currentlevel.pop();

        if (node)
        {
            cout << node->data << " ";
            if (lefttoright)
            {
                if (node->left)
                {
                    nextlevel.push(node->left);
                }
                if (node->right)
                {
                    nextlevel.push(node->right);
                }
                else
                {
                    if (node->right)
                    {
                        nextlevel.push(node->right);
                    }
                    if (node->left)
                    {
                        nextlevel.push(node->left);
                    }
                }
            }
        }
        if(currentlevel.empty()){
            lefttoright =!lefttoright;
            swap(currentlevel, nextlevel);
            cout << endl;
        }
    };

    int main()
    {
        cout << "create a binary tree " << endl;
        Node *root = buildTree();

        cout << "Zigzag traversal of the binary tree:" << endl;
        zigzagTraversal(root);

        return 0;
    }