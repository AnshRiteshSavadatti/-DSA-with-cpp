#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node(){
        cout << "The data which is being deleted is " << this->data << endl;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

int len(Node* head){
    int cnt = 0;
    Node* t = head;
    while(t != NULL){
        t = t->next;
        cnt++;
    }
    return cnt;
}

void insert_at_beg(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);
    if(head == NULL){
        head = temp;
        tail = head;
        return;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    return;
}

void insert_at_end(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);
    if(head == NULL){
        head = temp;
        tail = head;
        return;
    }
    else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    return;
}

void insert_at_pos(Node* &head, Node* &tail, int pos, int data){
    if(pos == 1){
        insert_at_beg(head, tail, data);
        return;
    }
    else if(pos == len(head)){
        insert_at_end(head, tail, data);
        return;
    }
    else{
        int cnt = 1;
        Node* temp = head;
        while(cnt < pos-1){
            cnt++;
            temp = temp->next;
        }
        Node* t = temp->next;
        Node* newnode = new Node(data);
        newnode->next = t;
        t->prev = newnode;
        newnode->prev = temp;
        temp->next = newnode;
    }
    return;
}

void delete_from_beg(Node* &head){
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
    return;
}

void delete_from_end(Node* &tail){
    Node* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    temp->prev = NULL;
    delete temp;
    return;
}

void delete_at_pos(Node* &head, Node* &tail, int pos){
    if(pos == 1){
        delete_from_beg(head);
        return;
    }
    else if(pos == len(head)){
        delete_from_end(tail);
        return;
    }
    else{
        int cnt = 1;
        Node* temp = head;
        while(cnt < pos-1){
            cnt++;
            temp = temp->next;
        }
        Node* current;
        Node* nex;
        current = temp->next;
        nex = current->next;
        nex->prev = temp;
        temp->next = nex;
        current->next = NULL;
        current->prev = NULL;
    }
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

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    int ch;
    int data;
    int data2;
    while(1){
        cout << "Enter\n1 to insert at begnning\n2 to insert at end\n3 to insert at position\n4 to display\n5 to delete at position" << endl;
        cin >> ch;
        switch(ch){
            case 1:
                cout << "Enter the data which is to be inserted at begnning " << endl;
                cin >> data;
                insert_at_beg(head, tail, data);
                break;
            case 2:
                cout << "Enter the data which is to inserted at end" << endl;
                cin >> data;
                insert_at_end(head,tail,data);
                break;
            case 3:
                cout << "Enter the position in which data is to be inserted" << endl;
                cin >> data;
                cout << "Enter the data which is to be entered at positoin" << endl;
                cin >> data2;
                insert_at_pos(head,tail,data,data2);
                break;
            case 4:
                display(head);
                break;
            case 5:
                cout << "Enter the positoin at which data is to be inserted" << endl;
                cin >> data;
                delete_at_pos(head,tail,data);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
