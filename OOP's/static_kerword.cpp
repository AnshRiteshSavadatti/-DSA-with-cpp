#include<iostream>
using namespace std;


class Hero{
    public:
    int health;
    char level;
    static int timetoComplete;

    static int fun(){
        return timetoComplete;
    }
};

// data_type class_name :: variable name = value;
// :: --> is scope resolution operator

int Hero :: timetoComplete = 5;


int main(){
    cout << Hero :: fun() << endl;
    return 0;
}