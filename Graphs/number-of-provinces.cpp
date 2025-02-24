// https://leetcode.com/problems/number-of-provinces/

#include <bits/stdc++.h>
using namespace std;

class Solution {


public:
    void dfs(int node, vector<int> adjLs[], vector<bool>& visited){
        visited[node] = true;
        for(auto it : adjLs[node]){
            if(!visited[it]){
                dfs(it, adjLs, visited);
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int v = adj.size() + 1;
        vector<int> adjLs[v];

        for(int i =0; i < v -1; i++){
            for(int j =0; j < v -1; j++){
                if(adj[i][j] == 1 && i != j){
                    adjLs[i+1].push_back(j+1);
                    adjLs[j+1].push_back(i+1);
                }
            }
        }

        vector<bool> visited(v, false);

        int cnt = 0;
        for(int i = 1; i < v; i ++){
            if(!visited[i]){
                cnt++;
                dfs(i, adjLs, visited);
            }
        }
        return cnt;
    }
};