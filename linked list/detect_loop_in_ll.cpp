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

Node* floyds_loop_detection_algo(Node* head){
    Node* slow,*fast;
    fast = head; slow = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
        slow = slow->next;
        if(slow == fast)
            return fast;
    }
    return NULL;
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

/*
    cycle can also be detected by using map
*/
Node* start_of_loop(Node* head){
    if(head == NULL)
        return NULL;
    Node* intersection = floyds_loop_detection_algo(head);
    if(intersection == NULL)
        return NULL;
    Node* slow = head;
    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return intersection;
}

void remove_loop(Node* &head){
    Node* temp = start_of_loop(head);
    Node* t = temp;
    while(t->next != temp)
        t = t->next;
    t->next = NULL;
    return;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insert_at_end(head,tail,10);
    insert_at_end(head,tail,20);
    insert_at_end(head,tail,30);
    insert_at_end(head,tail,40);
    tail->next = head->next;
    Node* temp;
    int ch;
    int data;
    while(1){
        cout << "Enter" << endl;
        cout << "1 to insert at end" << endl;
        cout << "2 to display" << endl;
        cout << "3 detect loop " << endl;
        cout << "4 to get starting node of loop" << endl;
        cout << "5 to remove loop " << endl;
        cin >> ch;
        switch(ch){
            case 1: 
                cout << "Enter the data" << endl;
                cin >>data;
                insert_at_end(head, tail, data);
                break;
            case 2:
                display(head);
                break;
            case 3:
                temp = floyds_loop_detection_algo(head);
                if(temp == NULL)
                    cout << "loop is not present" << endl;
                else
                    cout << "Loop is present" << endl;
                break;
            case 4:
                temp = start_of_loop(head);
                if(temp == NULL)
                    cout <<"No loop present" << endl;
                else    
                    cout << "Loop present at " << temp->data << endl;
                break;
            case 5:
                remove_loop(head);
                cout << "Loop removed" << endl;
                break;
            default:
                exit(0);
                break;
        }
    }
    return 0;
}