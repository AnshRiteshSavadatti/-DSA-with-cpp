// https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(string& s, set<string>& ss, int i){
        if(i >= s.size()){
            ss.insert(s);
            return;
        }
        
        
        for(int j = i; j < s.size(); j++){
            swap(s[i], s[j]);
            solve(s, ss, i + 1);
            swap(s[i], s[j]);
        }
        
        return;
    }
    
public:
    vector<string> findPermutation(string &s) {
        
        set<string> ss;
        int i = 0, j = 1;
        
        solve(s, ss, i);
        
        vector<string> ans (ss.begin(), ss.end());
        return ans;
    }
};