#include<iostream>
using namespace std;

void change(int** ptr2){
    // ptr2 = ptr2 + 1;
    // kuch change hoge ?? --> NAHI

    **ptr2 = **ptr2 + 1;
    // kuch change hoga ?? --> 10 ka value 11 hoga

     *ptr2 = *ptr2 + 1;
    // kuch change hoga ?? --> ptr ka address change hoga
}

int main(){
    int i = 10;
    int* ptr = &i;  
    // THIS GIVES ERROR
    // int* ptr1 = &ptr;
    // cout << "The value is -->" << *ptr1 << endl;
    int **ptr2 = & ptr;
    cout << "Before " << endl;
    cout << i << endl;
    cout << ptr << endl;
    cout << ptr2 << endl;
    change(ptr2);
    cout << "After" << endl;
    cout << i << endl;
    cout << *ptr << endl;
    cout << ptr2 << endl;
    return 0;

}