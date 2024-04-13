#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution
{
    private:
    pair<bool, int> solve(Node* root){
        
        // base case if root is null
        if(root == nullptr){
            pair<bool, int>p = make_pair(true, 0);
            return p;
        }
        
        // base case for leaf nodes
        if(root->left == nullptr && root->right == nullptr){
            pair<bool, int>p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool, int>leftAns = solve(root->left);
        pair<bool, int>rightAns = solve(root->right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        
        bool condition = root->data == leftAns.second + rightAns.second;
        
        if(left && right && condition){
            pair<bool, int>ans = make_pair(true, root->data+leftAns.second+rightAns.second);
            return ans;
        }else{
            pair<bool, int>ans = make_pair(false, root->data+leftAns.second+rightAns.second);
            return ans;
        }
    }
    public:
    bool isSumTree(Node* root)
    {
        return solve(root).first;
         
    }
};