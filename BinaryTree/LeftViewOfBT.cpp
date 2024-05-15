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

void solve(Node* root, vector<int>& ans, int level){
    if(root == nullptr){
        return;
    }
    if(ans.size() == level){
        ans.push_back(root->data);
    }
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
    return;
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int>ans; 
    solve(root, ans, 0);
    return ans;
}