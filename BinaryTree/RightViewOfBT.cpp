#include<bits/stdc++.h>
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

// Should return  right view of tree
class Solution
{
    private:
    void solve(Node* root, map<int,int>& mpp, int level){
        if(root == nullptr){
            return;
        }
        
        mpp[level] = root->data;
        solve(root->left, mpp, level+1);
        solve(root->right, mpp, level+1);
        return;
    }
    
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int>ans;
        map<int,int>mpp;
        solve(root, mpp, 0);
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};




// ********************************************************************************************************
//                          MORE OPTIMIZED CODE
// *********************************************************************************************************

// Should return  right view of tree
class Solution
{
    private:
    void solve(Node* root, vector<int>& ans, int level){
        if(root == nullptr){
            return;
        }
        
        if(ans.size() == level){
            ans.push_back(root->data);
        }
        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
        
        return;
    }
    
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int>ans;
        solve(root, ans, 0);
        return ans;
    }
};
