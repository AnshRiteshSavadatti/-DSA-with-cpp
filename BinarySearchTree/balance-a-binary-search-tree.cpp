// https://leetcode.com/problems/balance-a-binary-search-tree/description/

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
private:
    void inorderTraversal(TreeNode* root, vector<int>& a){
        if(root == nullptr) return;

        inorderTraversal(root->left, a);
        a.push_back(root->val);
        inorderTraversal(root->right, a);
        return;
    }

    TreeNode* createBST(vector<int>& a, int start, int end){
        if(start > end) return nullptr;

        int mid = start + ((end - start) / 2);
        TreeNode* root = new TreeNode(a[mid]);

        root->left = createBST(a, start, mid - 1);
        root->right = createBST(a, mid + 1, end);

        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);

        root = createBST(inorder, 0, inorder.size()-1);

        return root;
    }
};