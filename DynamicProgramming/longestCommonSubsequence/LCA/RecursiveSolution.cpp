// https://leetcode.com/problems/longest-common-subsequence/submissions/1348563768/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string x, string y) {
        if(x.size() == 0 || y.size() == 0){
            return 0;
        }

        if(x[0] == y[0]){
            x.erase(x.begin()+0);
            y.erase(y.begin()+0);
            return 1 + longestCommonSubsequence(x,y);
        }
        string a = x;
        string b = y;
        a.erase(a.begin()+0);
        y.erase(y.begin() +0);

        return max(longestCommonSubsequence(a,b), longestCommonSubsequence(x,y));
    }
};