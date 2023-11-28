#include<bits\stdc++.h>
using namespace std;

int anagrams(string s, string str){
    int ways = 0;
    int cnt = 0;
    int arr[26] = {0};
    //storing the total count of individual charecters 
    for(int i=0; i<str.length(); i++){
        int temp = str[i] -'a';
        arr[temp]++;
    }
    // counting the total number of distinct charecters
    for(int i = 0; i < 26; i++){
        if(arr[i] > 0)
            cnt++;
    }

    int j =0; 
    int i = 0;
    while(j<s.length()){
        if(j - i + 1 < str.length()){
            int temp = s[j] - 'a';
            if(arr[temp] != 0){
                arr[temp]--;
                if(arr[temp] == 0)
                    cnt--;
            }
            j++;
        }
        else{
            if(cnt == 0){
                ways++;
                arr[s[i] - 'a']++;
                cnt++;
            }
            i++;
            j++;
            if(arr[s[j] - 'a'] > 0){
                arr[s[j] - 'a']--;
                if(arr[s[j] - 'a'] == 0)
                        cnt--;
            }
        }
    }
    return ways;

}
int main(){
    string s;
    cout << "Enter the string which is to be compared " << endl;
    cin>>s;
    string str;
    cout << "Enter string which is to be found" << endl;
    cin >> str;
    int ans = anagrams(s, str);
    cout << "The total number of anagrams is " << ans << endl;
    return 0;
}

