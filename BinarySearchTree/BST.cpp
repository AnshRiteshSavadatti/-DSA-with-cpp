#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* right;
        Node* left;

        Node(int data){
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

Node* insertIntoBst(Node* root, int d){
    if(root == nullptr){
        Node * newNode = new Node(d);
        return newNode;
    }

    if(root->data <= d){
        root->left = insertIntoBst(root->left, d);
    }else if(root->data > d){
        root->right = insertIntoBst(root->right, d);
    }

    return root;

}

void takeInput(Node* &root){
    
    int d;
    while(d != -1){
        cout << "Enter the data" << endl;
        cin >> d;
        if(d == -1 ) break;

        root = insertIntoBst(root, d);
    }
}

Node * deleteFromBST(Node* root, int val){
    if(root == nullptr){
        return nullptr;
    }

    if(root->data == val){
        if(!root->left && !root->right){
            // 0 child
            delete root;
            return nullptr;
        }else if(root->left && !root->right){
            // 1 child
            Node* temp = root->left;
            delete root;
            return temp;
        }else if(!root->left && root->right){
            // 1 child
            Node* temp = root->right;
            delete root;
            return temp;
        }else{
            // 2 child
            Node * temp;
            // inorder predecessor 
            if(root->left){
                temp = root->left;
                Node * pre = root;
                while(temp->right){
                    pre = temp;
                    temp = temp->right;
                }
                temp->left = root->left;
                temp->right = root->right;
                pre->right = nullptr;
            }
            delete root;
            return temp;
        }
    }
    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
    }
    else{
        root->right = deleteFromBST(root->right, val);
    }
    return nullptr;
}

void inorder(Node* root){
    if(root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    return;
}

void levelOrderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    queue<Node*>q;
    q.push(root);
    cout << root->data << endl;

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        
        if(curr->left){
            cout << curr->data << " ";
            q.push(curr->left);
        }
        if(curr->right){
            cout << curr->data << " ";
            q.push(curr->right);
        }
    }
    return;
}

int main(){

    Node* root = nullptr;
    cout << "Creating BST" << endl;

    takeInput(root);
    // Input : 10 20 30 40 50 5 4 3 2 1 15 16 25 36 -1
    levelOrderTraversal(root);
    cout << endl;

    root = deleteFromBST(root, 20);
    root = deleteFromBST(root, 16);
    levelOrderTraversal(root);

    return 0;
}