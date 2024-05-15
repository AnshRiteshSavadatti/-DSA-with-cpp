#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        if(root == nullptr){
            return ans;
        }
        
        map<int,int>mpp;// store hd and data;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*, int> p = q.front();
            q.pop();
            
            int hd = p.second;
            Node* frontNode = p.first;
            
            mpp[hd] = frontNode->data;
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, hd -1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, hd+1));
            }
        }
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};