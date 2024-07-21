#include <iostream>
#include <utility>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    if (root == nullptr) return {-1, -1};

    TreeNode* temp = root;
    TreeNode* pred = nullptr;
    TreeNode* succ = nullptr;

    // Find the node with the key and track the predecessor and successor
    while (temp != nullptr && temp->data != key) {
        if (key < temp->data) {
            succ = temp; // potential successor
            temp = temp->left;
        } else {
            pred = temp; // potential predecessor
            temp = temp->right;
        }
    }

    // If the node with key is not found
    if (temp == nullptr) return {-1, -1};

    // Find the predecessor (maximum value in left subtree)
    if (temp->left != nullptr) {
        pred = temp->left;
        while (pred->right != nullptr) {
            pred = pred->right;
        }
    }

    // Find the successor (minimum value in right subtree)
    if (temp->right != nullptr) {
        succ = temp->right;
        while (succ->left != nullptr) {
            succ = succ->left;
        }
    }

    int predValue = (pred != nullptr) ? pred->data : -1;
    int succValue = (succ != nullptr) ? succ->data : -1;

    return {predValue, succValue};
}

int main() {
    // Create a sample tree and test the function
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    pair<int, int> result = predecessorSuccessor(root, 20);
    cout << "Predecessor: " << result.first << ", Successor: " << result.second << endl;

    return 0;
}
