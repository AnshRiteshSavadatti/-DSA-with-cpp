#include <bits/stdc++.h>
using namespace std;

int countSetBits (int n){
    int cnt = 0;
    while(n){
        cnt += (n & 1);
        n = n >> 1;
    }
    return cnt;
}

int minCost (vector<vector<int>>& c){
    int n = c.size();
    int dp[1 << n];

    for(int i =1 ; i < n; i++) dp[i] = INT_MAX;
    dp[0] = 0;

    for(int mask = 0; mask < (1 << n); mask++){
        int x = countSetBits(mask);
        for(int j = 0; j < n; j++){
            if(!(mask & (1 << j))) dp[1 << j | mask] = min(dp[1 << j | mask], c[x][j] + dp[mask]);
        }
    }

    return dp[(1 << n)-1];
}

int main(){
    vector<vector<int>> c = {{3, 2, 7}, {5, 1, 3}, {2, 7, 2}};
    cout << minCost(c) << endl;
}