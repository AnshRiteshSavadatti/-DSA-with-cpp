//  Divide Linked List In Two
// https://www.naukri.com/code360/problems/let-last-be-the-first_920455?topList=jp-morgan-interview-questions&problemListRedirection=true&count=25&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM&customSource=studio_nav&page=2

#include <bits/stdc++.h> 
using namespace std;

    // Following is the list node structure:
    
    template <typename T>
    class Node {
        public:
            T data;
            Node* next;

            Node(T data) {
                next = NULL;
                this->data = data;
            }
            ~Node() {
                if (next != NULL) {
                    delete next;
                }
            }
    };


pair < Node < int > * , Node < int > * > divideList(Node < int > * head) {
    // Write your code here.
    Node<int>* first = new Node<int>(-1);
    Node<int>* second = new Node<int>(-1);

    Node<int>* temp1 = first;
    Node<int>* temp2 = second;

    bool flag = true;
    Node<int>* temp = head;

    while(temp != nullptr){
        if(flag){
            Node<int>* newnode = new Node<int>(temp->data);
            temp1->next = newnode;
            temp1 = temp1->next;
        }else{
            Node < int > * newnode = new Node<int>(temp->data);
            temp2->next = newnode;
            temp2 = temp2->next;
        }
        flag = !flag;
        temp = temp->next;
    }
    
    return make_pair(first->next, second->next);

}
