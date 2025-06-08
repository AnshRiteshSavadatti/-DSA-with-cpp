// https://leetcode.com/problems/house-robber/description/

#include <bits/stdc++.h>
using namespace std;

int maxValueToSteal (vector<int> values, int n, int index){
    if(index >= n) return 0;

    return max(values[index] + maxValueToSteal(values, n, index + 2), maxValueToSteal(values, n, index + 1));
}

int main(){
    vector<int> values = {0, 9, 3, 5, 8, 2, 4, 7};
    cout << "Hello" << endl;
    
    cout << maxValueToSteal(values, values.size(), 0) << endl;
    return 0;
}