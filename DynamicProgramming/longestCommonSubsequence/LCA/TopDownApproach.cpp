// https://leetcode.com/problems/longest-common-subsequence/submissions/1348598439/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string x, string y) {
        int n = x.size();
        int m = y.size();

        vector<vector<int>> t(n+1, vector<int>(m+1 , 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (x[i - 1] == y[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);
                }
            }
        }
        return t[n][m];
    }
};
