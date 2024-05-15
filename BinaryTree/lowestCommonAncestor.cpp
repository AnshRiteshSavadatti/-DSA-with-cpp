//https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root == nullptr){
           return nullptr;
       }
       if(root->data == n1 || root->data == n2){
           return root;
       }
       
       Node* leftAns = lca(root->left, n1, n2);
       Node* rightAns = lca(root->right, n1, n2);
       
       if(leftAns != nullptr && rightAns != nullptr){
           return root;
       }
       else if(leftAns == nullptr && rightAns != nullptr){
           return rightAns;
       }
       else if(leftAns != nullptr && rightAns == nullptr){
           return leftAns;
       }
       else 
           return NULL;
    }
};