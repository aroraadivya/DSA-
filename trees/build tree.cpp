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

Node* newNode() {
    int value;
    cout << "Enter node value (enter -1 for null): ";
    cin >> value;
    if (value == -1) {
        return nullptr;
    }

    Node* node = new Node(value);
    cout << "Enter left child of " << value << endl;
    node->left = newNode();
    cout << "Enter right child of " << value << endl;
    node->right = newNode();
    return node;
}

void printLevelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
    cout << endl;
}

int main() {
    cout << "Create the binary tree:" << endl;
    Node* root = newNode();

    cout << "Level order traversal of the binary tree:" << endl;
    printLevelOrder(root);

    return 0;
}
