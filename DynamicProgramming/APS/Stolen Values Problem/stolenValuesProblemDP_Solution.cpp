// https://leetcode.com/problems/house-robber/description/

#include <bits/stdc++.h>
using namespace std;

int maxValueToSteal (vector<int> values){
    int n = values.size();

    vector<int> dp(n, 0);
    dp[1] = values[1];

    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + values[i]);
    }

    return dp[n-1];
}

int main(){
    vector<int> values = {0, 9, 3, 5, 8, 2, 4, 7};
    cout << "Hello" << endl;
    
    cout << maxValueToSteal(values) << endl;
    return 0;
}