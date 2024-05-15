#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        if(root == nullptr){
            return ans;
        }
        
        // node  hd
        map<int,int>mpp;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*,int>p = q.front();
            q.pop();
            
            Node* frontNode = p.first;
            int hd = p.second;
            
            // if one value is present of hd then do nothing
            if(mpp.find(hd) == mpp.end()){
                mpp[hd] = frontNode->data;
            }
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, hd -1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, hd+1));
            }
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }

};