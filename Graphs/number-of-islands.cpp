// https://leetcode.com/problems/number-of-islands/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkLand(int i, int j, int m, int n, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        return i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == '1' && !visited[i][j];
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        queue<pair<int,int>> q;

        q.push(make_pair(i,j));
        visited[i][j] = true;

        int m = grid.size();
        int n = grid[0].size();

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            

            if(checkLand(p.first, p.second +1, m, n, grid, visited)){
                q.push(make_pair(p.first, p.second+1));
                visited[p.first][p.second+1] = true;
            }

            if(checkLand(p.first +1, p.second, m, n, grid, visited)){
                q.push(make_pair(p.first+1, p.second));
                visited[p.first+1][p.second] = true;
            }
            if(checkLand(p.first , p.second - 1, m, n, grid, visited)){
                q.push(make_pair(p.first, p.second-1));
                visited[p.first][p.second-1] = true;
            }
            if(checkLand(p.first -1 , p.second, m, n, grid, visited)){
                q.push(make_pair(p.first-1, p.second));
                visited[p.first-1][p.second] = true;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;
        for(int i =0; i < m; i ++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    bfs(grid, visited, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};