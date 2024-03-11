#include<bits/stdc++.h>
using namespace std;

int main(){
    int num = -130;
    int digitCount = static_cast<int>(log10(abs(num)))+1;
    const char* str = "123";
    int number = stoi(str);
    cout << number + 1 << endl;
    cout << int(log10(abs(num)) + 1) << endl;
    cout << digitCount << endl;
    return 0;
}