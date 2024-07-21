// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    int find(vector<int>& preorder, int n){
        for(int i=0; i<preorder.size(); i++){
            if(n == preorder[i]) return i;
        }
        return INT_MIN;
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& index, int startInorder, int endInOrder, int size){
        if(index >= size || startInorder > endInOrder){
            return nullptr;
        }

        int element = preorder[index++];
        TreeNode * root = new TreeNode(element);
        int pos = find(inorder, element);

        /* In this case left sub tree must be created first */
        root->left = solve(preorder, inorder, index, startInorder, pos-1, size);
        root->right = solve(preorder, inorder, index, pos+1, endInOrder, size);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;

        TreeNode* root = solve(preorder, inorder, preOrderIndex, 0, preorder.size()-1, preorder.size());

        return root;
    }
};