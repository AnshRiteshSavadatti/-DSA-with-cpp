#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
 

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int>result;
    	if(root == nullptr){
    	    return result;
    	}
    	
    	
    	queue<Node*>q;
    	bool leftToRight = true;
    	
    	q.push(root);
    	
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int>ans(size);
    	    
        	for(int i =0; i<size ; i++){    
        	    Node* frontNode = q.front();
        	    q.pop();
        	    
        	    int index = leftToRight ? i : size - i - 1;
        	    ans[index] = frontNode->data;
        	    
        	    if(frontNode->left){
        	        q.push(frontNode->left);
        	    }
        	    
        	    if(frontNode->right){
        	        q.push(frontNode->right);
        	    }
        	}
        	
        	leftToRight = !leftToRight;
        	
        	for(auto it : ans)
        	    result.push_back(it);
    	}
    	return result;
    }
};