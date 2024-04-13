#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:

    void traverseLeft(Node* root, vector<int>&ans){
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return;
        }
        
        ans.push_back(root->data);
        
        if(root->left){
            traverseLeft(root->left, ans);
        }else{
            traverseLeft(root->right, ans);
        }
        return;
    }
    
    void traverseLeaf(Node* root, vector<int> &ans){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
        return;
    }
    
    void traverseRight(Node* root, vector<int> &ans){
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return;
        }
        
        if(root->right){
            traverseRight(root->right, ans);
        }else{
            traverseRight(root->left, ans);
        }
        
        ans.push_back(root->data);
        return;
    }
    
    vector <int> boundary(Node *root)
    {
        
        vector<int>ans;
        if(root == nullptr){
            return ans;
        }
        
        ans.push_back(root->data);
        // print left part except leaf node
        traverseLeft(root->left, ans);
        
        // print leaf nodes from left to right LNR
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
        
        // print right part in revers order
        traverseRight(root->right, ans);
        
        return ans;
        
    }
};