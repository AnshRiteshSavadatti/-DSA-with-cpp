#include<iostream>
using namespace std;

string reverse(string s, int i, int j){
    if(i > j)
        return s;
    swap(s[i],s[j]);
    i++; j--;
    s = reverse(s,i,j);
    return s;
}

int main(){
    string s;
    cout << "Enter the string which is to be reversed" << endl;
    cin >> s;
    s = reverse(s,0,s.size()-1);
    cout << s << endl;
    return 0;
}