//same tree
#include<iostream>
using namespace std;

struct treenode{
    int value;
    treenode* left;
    treenode* right;
    treenode(int val = 0) : value(val), left(nullptr), right(nullptr) {}
};

class solution{
public:
    bool isSametree(treenode* p, treenode* q){
        if(p == nullptr && q == nullptr){
            return true;
        }
        if(p == nullptr || q == nullptr){
            return false;
        }
        if(p->value != q->value){
            return false;
        }

        return isSametree(p->left, q->left) && isSametree(p->right, q->right);
    }
};

treenode* insertNode() {
    int value;
    cout << "Enter node value (enter -1 for null): ";
    cin >> value;
    if (value == -1) {
        return nullptr;
    }

    treenode* newNode = new treenode(value);
    cout << "Enter left child of " << value << endl;
    newNode->left = insertNode();
    cout << "Enter right child of " << value << endl;
    newNode->right = insertNode();

    return newNode;
}

int main() {
    cout << "Create tree p:" << endl;
    treenode* p = insertNode();

    cout << "Create tree q:" << endl;
    treenode* q = insertNode();

    solution sol;
    bool result = sol.isSametree(p, q);
    cout << "The trees are " << (result ? "same" : "not same") << endl;

    return 0;
}
