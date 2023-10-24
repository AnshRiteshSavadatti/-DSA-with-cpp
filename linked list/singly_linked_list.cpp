#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    // constructer
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

int len(Node* &head){
    int cnt = 0;
    Node * temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insert_at_beg(Node* &head, Node* &tail, int data){
    Node* newnode =new Node(data);
    if(head == NULL){
        head = newnode;
        tail = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
    return;
}

void insert_at_end(Node* &head, Node* &tail, int d){
    Node * newnode = new Node(d);
    if(head == NULL){
        head = newnode;
        tail = newnode;
    }
    else{
        tail->next = newnode;
        tail = newnode;
    }
    return;
}

void insert_at_pos(Node* &head,Node* &tail, int d){
    int pos;
    Node * newnode = new Node(d);
    cout << "Enter the position" << endl;
    cin >> pos;
    int l = len(head);
    if(pos > l+1 || pos < 0) cout << "Invaid positon" << endl;
    else{
        if(pos == 1){
            insert_at_beg(head, tail, d);
            return;
        }
        else if(pos == l+1){
            insert_at_end(head, tail, d);
            return;
        }
        int cnt = 1;
        Node* temp = head;
        while(cnt < pos-1){
            temp = temp->next;
            cnt++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return;
}

void delete_from_beg(Node* &head){
    Node* temp = head;
    head = head->next;
    delete temp;
    return;
}

void delete_from_end(Node* &head, Node* &tail){
    Node* temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
    tail = temp;
    temp = temp->next;
    delete temp;
}

void delete_at_pos(Node* &head, Node* &tail, int pos){
    int c = 1;
    if(pos == 1){
        delete_from_beg(head);
        return;
    }
    else if(pos == len(head)){
        delete_from_end(head, tail);
        return;
    }
    Node* temp = head;
    while(c < pos -1){
        temp = temp->next;
        c++;
    }
    cout << "The data which is removed is " << temp->next->data << endl;;
    temp->next = temp->next->next;
    return;
}

void display(Node* & head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " " ;
        temp = temp->next;
    }
    cout << endl;
    return;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    int ch;
    int data;
    while(1){
        cout << "Enter \n1 to insert at begning \n2 to insert at end \n3 to insert at position \n4 to display " << endl;
        cout << "5 to delete ant any position" << endl;
        cout << "0 to exit" << endl;
        cin >> ch;
        switch(ch){
            case 1:
                cout << "Enter the data" << endl;
                cin >> data;
                insert_at_beg(head, tail, data);
                break;
            case 2:
                cout << "Enter the data" << endl;
                cin >> data;
                insert_at_end(head, tail, data);
                break;
            case 3:
                cout << "Enter the data" << endl;
                cin >> data;
                insert_at_pos(head, tail, data);
                break;
            case 4:
                cout << "HEAD " << head->data << " " << "TAIL " << tail->data << endl;
                display(head);
                break;
            case 5:
                cout << "Enter the positon which is to be deleted" << endl;
                cin >> data;
                delete_at_pos(head, tail, data);
                break;
            default :
                exit(0);
        }
    }
    return 0;
}