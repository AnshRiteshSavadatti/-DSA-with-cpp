//  https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
    
private:
    void solve(Node* root, int len, int &maxlen, int sum, int &maxSum){
        if(root == nullptr){
            if(len == maxlen){
                maxSum = max(maxSum, sum);
            }else if(len > maxlen){
                maxSum = sum;
                maxlen = len;
            }
            return ;
        }
        
        solve(root->left, len+1, maxlen, sum+root->data, maxSum);
        solve(root->right, len+1, maxlen, sum+root->data, maxSum);
        return;
    }
    
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;
        int maxlen = 0;
        int sum = 0;
        int maxSum = 0;
        
        solve(root, len, maxlen, sum, maxSum);
        
        return maxSum;
    }
};