#include<iostream>
using namespace std;

bool palindrome(string s, int i, int j){
    if(i > j) // base case
        return true;
    if(s[i] != s[j])
        return false;
    return palindrome(s, ++i, --j);  // recursive relation
}

int main(){string s;
    cout << "Enter the string " << endl;
    cin >> s;
    bool flag = palindrome(s,0,s.size()-1);
    if(flag)
        cout << "Palindrome" << endl;
    else        
        cout << "Not a palindrome" << endl;
    return 0;

}