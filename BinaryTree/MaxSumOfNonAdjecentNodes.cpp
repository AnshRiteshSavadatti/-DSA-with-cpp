// https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution{
  public:
    pair<int, int> solve(Node* root){
        if(root == nullptr){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
         
        pair<int, int> l = solve(root->left);
        pair<int,int> r = solve(root->right);
        
        pair<int,int> res;
        res.first = root->data + l.second + r.second;
        res.second = max(l.second, l.first) + max(r.second, r.first);
        
        return res;
    }
    
    int getMaxSum(Node *root) 
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};