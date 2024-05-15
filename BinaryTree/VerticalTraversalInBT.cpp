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
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int>ans;
        if(root == nullptr){
            return ans;
        }
        // hd   level  nodes->Data
        map<int,map<int,vector<int>>> mpp;
        
        //       Node->data   hd,   lvl
        queue<pair<Node*, pair<int,int>>> q;
        
        q.push(make_pair(root, make_pair(0,0)));
         
        while(!q.empty()){
            pair<Node*,pair<int,int>>p = q.front();
            q.pop();
            
            Node* frontNode = p.first;
            int hd = p.second.first;
            int lvl = p.second.second;
            
            mpp[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
            }
            
        }
        for(auto it: mpp){
            for(auto jt: it.second){
                for(auto kt: jt.second){
                    ans.push_back(kt);
                }
            }
        }
        return ans;
    }
};