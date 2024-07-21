// https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

// Handling one edge case where root->datt == node

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};


Node* solve(Node* root, int &k, int node){
    if(root == nullptr){
        return nullptr;
    }
    if(root->data == node) return root;
    
    Node* left = solve(root->left, k, node);
    Node* right = solve(root->right, k, node);
    
    if(!left && right){
        k--;
        if(k <=0){
            k = INT_MAX;
            return root;
        }
        return right;
    }else if(left && !right){
        k--;
        if(k <=0){
            k = INT_MAX;
            return root;
        }
        return left;
    }
    return nullptr;
    
}

int kthAncestor(Node *root, int k, int node)
{
    if(root == nullptr){
        return 0;
    }
    
    Node* ans = solve(root, k, node);
    if(!ans || ans->data == node) return -1;
    
    return ans->data;
}