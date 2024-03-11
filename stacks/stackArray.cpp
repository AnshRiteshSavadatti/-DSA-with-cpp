#include<iostream>
using namespace std;

class Stack{
    public :
        // properties
        int * arr;
        int size;
        int top;

        // behaviour
        Stack(int size){
            this->size = size;
            arr = new int[size];
            top = -1;
        }

        int isFull(){
            if(top == size -1){
                return 1;
            }
            return 0;
        }

        int isEmpty(){
            if(top == -1){
                return 1;
            }
            return 0;
        }

        void push(int n){
            if(isFull()){
                cout << "Stack overflow" << endl;
                return;
            }
            this->top++;
            arr[top] = n;
            return;
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return -1;
            }
            int t = arr[top];
            top--;
            return t;
        }

        int peek(){
            if(!isEmpty()){
                return arr[top];
            }
            return -1;
        }
};

int main(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(5);
    cout << s.peek() << endl;
    return 0;
}