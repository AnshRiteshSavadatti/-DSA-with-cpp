#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insert_at_end(Node* &head, int data){
    Node* newnode = new Node(data);
    if(head == NULL){
        head = newnode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    return;
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

void reverse(Node* &head, Node* curr, Node* prv){
    // base case
    if(curr == NULL){
        head = prv;
        return;
    }
    Node* nex = curr->next;
    reverse(head, nex, curr);
    curr->next = prv;
    return;
}

// Node* reverse(Node* head, Node* curr, Node* pr){
//     if(head == NULL || head->next == NULL){
//         return head ;
//     }
//     Node* prv = NULL;
//     Node* cur = head;
//     Node* nex = head->next;

//     while(cur != NULL){
//         cur->next = prv;
//         prv = cur;
//         cur = nex;
//         if(nex != NULL)
//             nex = nex->next;
//         cout << "HI" << endl;
//     }
//     cout << "yo" << endl;
//     return prv;
// }

int main(){
    Node* head = NULL;
    int ch;
    int data;
    while(1){
        cout << "Enter" << endl;
        cout << "1 to insert at end" << endl;
        cout << "2 to display" << endl;
        cout << "3 to reverse the list " << endl;
        cin >> ch;
        switch(ch){
            case 1:
                cout << "Enter the data which has to be inserted " << endl;
                cin >> data;
                insert_at_end(head, data);
                break;
            case 2:
                cout << "The linked list is " << endl;
                display(head);
                break;
            case 3:
                head = reverse(head,head,NULL);
                cout << "hello" << endl;
                break;
            default:
                cout << "Thank you" << endl;
                exit(0);
        }
    }
    return 0;
}