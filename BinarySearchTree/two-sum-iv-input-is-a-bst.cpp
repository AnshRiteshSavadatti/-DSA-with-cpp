// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/

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
    void solve(TreeNode* root, vector<int> &a){
        if(root == nullptr) return;

        solve(root->left, a);
        a.push_back(root->val);
        solve(root->right, a);
    }

    bool pairExists(vector<int> &a, int k){
        int i = 0, j = a.size()-1;
        while(i < j){
            if(a[i] + a[j] > k){
                j--;
            }else if(a[i] + a[j] < k){
                i++;
            }else{
                return true;
            }
        }
        return false;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        solve(root, ans);

        return pairExists(ans, k);
    }
};