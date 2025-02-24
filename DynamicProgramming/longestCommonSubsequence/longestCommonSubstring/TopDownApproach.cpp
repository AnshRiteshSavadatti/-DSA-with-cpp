// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstr(string x, string y) {
        int n = x.size();
        int m = y.size();

        vector<vector<int>> t(n + 1, vector<int>(m + 1, 0));

        int result = 0; 

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (x[i - 1] == y[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                    result = max(result, t[i][j]);
                } else {
                    t[i][j] = 0;
                }
            }
        }
    return result;
    }