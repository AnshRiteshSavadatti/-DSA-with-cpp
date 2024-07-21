// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* mapping(TreeNode* root, int start, map<TreeNode*, TreeNode*> &mpp){
        // create mapping and find target
        if(root == nullptr) return nullptr;

        if(root->left){
            mpp[root->left] = root;
        }
        if(root->right){
            mpp[root->right] = root;
        }
        if(root->val == start){
            return root;
        }
        
        TreeNode* left = mapping(root->left, start, mpp);
        TreeNode* right = mapping(root->right, start, mpp);

        if(right) return right;
        return left;
    }

    int burnTree(TreeNode* root, map<TreeNode*, TreeNode*> &mpp){
        map <TreeNode*, bool> visited;
        queue <TreeNode*> q;

        // doing something like level order traversal
        q.push(root);
        visited[root] = true;

        int ans = 0;

        while(!q.empty()){
            bool flag = false;
            int size = q.size();// to track if elements is added or not to increment ans;

            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                    flag = true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                    flag = true;
                }
                if(mpp[curr] && !visited[mpp[curr]]){
                    q.push(mpp[curr]);
                    visited[mpp[curr]] = true;
                    flag = true;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {
        // 1. create a mappig child->parent
        // 2. find the target node in O(n)
        // 3. use visited datastructure and a queue to keep map of the nodes which are visited and the nodes which are being added newly

        int ans = 0;
        map<TreeNode*, TreeNode*> mpp;
        mpp[root] = nullptr;

        TreeNode* target = mapping(root, start, mpp);

        ans = burnTree(target, mpp);

        return ans;

    }
};