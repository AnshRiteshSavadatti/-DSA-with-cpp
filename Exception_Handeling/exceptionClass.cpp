
#include <iostream>
#include <stdexcept>
using namespace std;

int main(){
    try{
        throw(exception());
    }
    catch(exception & e){
            cout << "Exception caught " << e.what() << endl; 
        }
}