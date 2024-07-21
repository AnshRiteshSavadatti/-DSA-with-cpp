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

    bool solution(TreeNode* root, long mini, long maxi){
        if(root == nullptr) return true;

        if(root->val > mini && root->val < maxi){
            bool left = solution(root->left, mini, root->val);
            bool right = solution(root->right, root->val, maxi);
            return left && right;
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
       
        long mini = std::numeric_limits<long>::min();
        long maxi = std::numeric_limits<long>::max();
    
        bool ans = solution(root, mini, maxi);

        return ans;
    }
};