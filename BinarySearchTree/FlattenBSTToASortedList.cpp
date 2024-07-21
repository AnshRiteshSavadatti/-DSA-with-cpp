#include <bits/stdc++.h> 
using namespace std;
    
template <typename T> class TreeNode {
    public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

void inorderTraversal(TreeNode<int>* root, vector<int>& ans){
    if(root == nullptr) return;

    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
    return;
}

void vectorToll(TreeNode<int>* &root, vector<int>& ans){
    int i;
    int n = ans.size();
    TreeNode<int>* curr = root;
    for( i =1; i <n; i++){
        TreeNode<int>* temp = new TreeNode<int> (ans[i]);
        curr->right = temp;
        curr->left = nullptr;
        curr = temp;
    }
    curr->left = nullptr;
    curr->right = nullptr;
    return;
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> ans;
    inorderTraversal(root, ans);

    TreeNode<int>* newNode = new TreeNode<int> (ans[0]);

    vectorToll(newNode, ans);
    return newNode;

}
