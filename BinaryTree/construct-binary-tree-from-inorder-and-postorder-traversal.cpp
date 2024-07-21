// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    int position(int element, vector<int>& inorder){
        for(int i=0; i<inorder.size(); i++){
            if(inorder[i] == element) return i;
        }
        return -1;
    }

    TreeNode * solve(vector<int>& inorder, vector<int>& postorder, int &PostOrderIndex, int inorderStart, int inorderEnd, int size){
        if(inorderStart > inorderEnd || PostOrderIndex < 0){
            return nullptr;
        }

        int element = postorder[PostOrderIndex--];
        TreeNode * root = new TreeNode (element);
        int pos = position(element, inorder);

        if (pos == -1) {
            return nullptr; 
        }

        root->right = solve(inorder, postorder, PostOrderIndex, pos + 1, inorderEnd, size);
        root->left = solve(inorder, postorder, PostOrderIndex, inorderStart, pos-1, size);
        

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode * root ;
        
        int size = inorder.size();
        int index = size -1;
        root = solve(inorder, postorder, index, 0, size - 1, size);

        return root;
    }
};