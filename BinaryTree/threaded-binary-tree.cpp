// https://www.geeksforgeeks.org/threaded-binary-tree/

/*

#include <bits/stdc++.h>
using namespace std;


// Method 1: Using "struct" to make
// user-define data type
struct node {
    int data;
    struct node* left;
    struct node* right;
    bool rightThread;
};

// Method 2: Using "class" to make
// user-define data type
class Node {
public:
    int data;
    Node* left;
    Node* right;
    bool rightThread;
    // Val is the key or the value that has to be added to
    // the data part
    Node(int val){
        data = val;
        // Left and right child for node will be initialized
        // to null
        left = NULL;
        right = NULL;
        // rightThread will be initialized to false
        rightThread = false;
    }
};

// Utility function to find leftmost node in a tree rooted with n
Node* leftMost(Node* n){
    if (n == NULL)
        return NULL;

    while (n->left != NULL)
        n = n->left;

    return n;
}

// CPP code to do inorder traversal in a threaded binary tree
void inOrder(Node* root){
    Node* cur = leftMost(root);
    while (cur != NULL) {
        cout<<cur->data<<" ";

        // If this node is a thread node, then go to
        // inorder successor
        if (cur->rightThread)
            cur = cur->right;
        else // Else go to the leftmost child in right
             // subtree
            cur = leftmost(cur->right);
    }
}

*/