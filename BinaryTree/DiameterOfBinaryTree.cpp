#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  
  int height(Node* root){
      if(root == nullptr){
          return 0;
      }
      int left = height(root->left);
      int right = height(root->right);
      
      int ans = max(left, right) + 1;
      
      return ans;
  }
  
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root == nullptr){
            return 0;
        }
        
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->right) + 1 + height(root->left);
        
        int ans = max({op1, op2, op3});
        
        return ans;
    }
};

//**************************************************************************************
//                  OPTIMIZED SOLUTION

class Solution {
  
  // first  diameter
  // second height
  pair<int,int> fastHeight(Node* root){
      if(root == nullptr){
          pair<int,int>p = make_pair(0,0);
            return p;
      }
      
      pair<int,int>left = fastHeight(root->left);
      pair<int,int>right = fastHeight(root->right);
      
      int op1 = left.first;
      int op2 = right.first;
      int op3 = left.second + right.second + 1;
      
      pair<int,int>ans;
      ans.first = max({op1,op2,op3});
      ans.second = max(left.second, right.second) + 1;
      return ans;
      
  }
  
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        pair<int,int> p = fastHeight(root);
        return p.first;
    }
};