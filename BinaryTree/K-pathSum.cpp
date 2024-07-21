// https://www.geeksforgeeks.org/problems/k-sum-paths/1

#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
  public:
    void solve(Node* root, int k, int &count, vector<int>path){
        if(root == nullptr) return;
        
        path.push_back(root->data);
        
        solve(root->left, k, count, path);
        solve(root->right, k, count, path);
        
        int sum = 0;
        for(int i = path.size() -1; i >= 0; i--){
            sum += path[i];
            if(sum == k) count++;
        }
        return;
    }
    
    int sumK(Node *root,int k)
    {
        if(root == nullptr) return 0;
        int count = 0;
        vector<int>path;
        
        solve(root, k, count, path);
        return count;
    }
};