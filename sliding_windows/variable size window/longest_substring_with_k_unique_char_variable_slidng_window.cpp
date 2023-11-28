// longest stubstring with k unique charectors 
#include<bits/stdc++.h>
using namespace std;

int longest_substring(string str, int k){
    int j = 0, i = 0, cnt = 0, ans = 0;
    int n = str.size();
    map < char, int > mpp;
    while(j < str.size()){
        if(mpp.size() < k){
            mpp[str[j++]]++;
        }
        else if(mpp.size() == k){
            cnt++;
            ans = max(cnt, ans);
            if(j < n){
                mpp[str[j++]]++;

            }
        }
        else{
            while(mpp.size() > k)
                mpp[str[i++]]--;
        }
    }
    return ans;
}

int main(){
    string str;
    cout << "Enter the string " << endl;
    cin >> str;
    int k;
    cout << "Enter the value of unique number of occurance ie k " << endl;
    cin >> k;
    int ans = longest_substring(str, k);
    cout << "The total number of longest string with k unique vairable is " << ans << endl;
    return 0;
}