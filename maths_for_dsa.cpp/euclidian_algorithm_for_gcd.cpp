// GCD of two numbers
//   O(log(min(a, b))
#include<iostream> 
using namespace std;

int ans(int a, int b){
    if(b == 0)
        return a;
    else{
        ans(b,a % b);
    }
}
int main(){
    int a, b;
    cout << "Enter the value of a " << endl;
    cin >> a;
    cout << "Enter the value of b " << endl;
    cin >> b;
    int answer = ans(a, b);
    cout << "The answer is " << answer << endl;
    return 0;
}