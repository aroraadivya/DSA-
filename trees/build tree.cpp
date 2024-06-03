#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

// Function to build the tree by taking input during runtime
Node *buildTree() {
    int value;
    cout << "Enter root node value: ";
    cin >> value;
    
    if (value == -1){
        return nullptr;
    }

    Node *root = new Node(value);
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *current = q.front();
        q.pop();

        // Input left child
        cout << "Enter left child of " << current->data << " (enter -1 for null): ";
        cin >> value;
        if (value != -1) {
            current->left = new Node(value);
            q.push(current->left);
        }

        // Input right child
        cout << "Enter right child of " << current->data << " (enter -1 for null): ";
        cin >> value;
        if (value != -1) {
            current->right = new Node(value);
            q.push(current->right);
        }
    }
    return root;
}

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; ++i) {
                Node* currentNode = q.front();
                q.pop();
                currentLevel.push_back(currentNode->data);

                if (currentNode->left) {
                    q.push(currentNode->left);
                }
                if (currentNode->right) {
                    q.push(currentNode->right);
                }
            }
            result.push_back(currentLevel);
        }

        return result;
    }
};

int main() {
    cout << "Create the binary tree:" << endl;
    Node* root = buildTree();

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    cout << "Level order traversal of the binary tree:" << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
