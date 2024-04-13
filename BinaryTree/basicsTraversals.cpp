#include <iostream>
#include <queue>
using namespace std;

// do reverse level order traversal
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

Node* create(Node* root, int arr[], int& i) {
    if (arr[i] == -1) {
        i++;
        return nullptr;
    }

    root = new Node(arr[i++]);
    root->left = create(root->left, arr, i);
    root->right = create(root->right, arr, i);
    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == nullptr){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL); // adding seperator to print level wise

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        

        if(current == nullptr){
            // purana level complete ho gaya
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        }else{
            cout << current->data << " ";
            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
    }
    return;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    return;
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
    return;
}

void buildFromLevelOrderTraversal(Node* &root, int arr[]){
    queue<Node*>q;
    root = new Node(arr[0]);
    q.push(root);
    int i = 0;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        i++;
        if(arr[i] != -1){
            temp->left = new Node(arr[i]);
            q.push(temp->left);
        }
        i++;
        if(arr[i] != -1){
            temp->right = new Node(arr[i]);
            q.push(temp->right);
        }
    }
    return;
}

int main() {
    Node* root = nullptr;

    // Inserting values in tree
    int arr[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    int index = 0;
    root = create(root, arr, index);

    cout << "The level order traversal is " << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "The inorder traversal is" << endl;
    inorder(root);
    cout << endl;

    cout << "The preorder traversal is" << endl;
    preOrder(root);
    cout << endl;

    cout << "The postorder traversal is" << endl;
    postOrder(root);
    cout << endl;

    Node * head = nullptr;

    int arr2[] = {1, 3, 5, 7, 11, 17, -1, -1, -1, -1, -1, -1, -1};
    /*
        The number of -1 is no of elements in the binary tree + 1
    */
    buildFromLevelOrderTraversal(head, arr2);
    cout << "The levelOrder traversal of the tree made from level order traversel is" << endl;
    levelOrderTraversal(head);


    return 0;
}
