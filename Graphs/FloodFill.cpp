// https://leetcode.com/problems/flood-fill/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& image, int i, int j, int m, int n, int curr, vector<vector<bool>>& visited){
        return i < m && j < n && i >=0 && j >=0 && curr == image[i][j] && !visited[i][j];
    }

    void bfs(vector<vector<int>>& image, int i, int j, int color, vector<vector<bool>>& visited){
        visited [i][j] = true;

        vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        int m = image.size();
        int n = image[0].size();

        queue<pair<int,int>> q;
        q.push({i, j});

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();

            for(auto it : directions){
                int x = p.first + it.first;
                int y = p.second + it.second;
                if(checkValid(image, x, y, m, n, image[p.first][p.second], visited)){
                    q.push({x, y});
                    visited[x][y] = true;
                }
            }
            image[p.first][p.second] = color;
        }
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        bfs(image, sr, sc, color, visited);

        return image;
    }
};





// Same code using DFS

class Solution {
public:
    bool checkValid(vector<vector<int>>& image, int i, int j, int m, int n, int curr, vector<vector<bool>>& visited){
        return i < m && j < n && i >=0 && j >=0 && curr == image[i][j] && !visited[i][j];
    }

    void dfs(vector<vector<int>>& image, int i, int j, int color, vector<vector<bool>>& visited, int m, int n, vector<pair<int,int>>& directions){
        
        visited [i][j] = true;
        for(auto it : directions){
            int x = i + it.first;
            int y = j + it.second;
            if(checkValid(image, x, y, m, n, image[i][j], visited)){
                dfs(image, x, y, color, visited, m, n, directions);
            }
        }
        image[i][j] = color;

        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        dfs(image, sr, sc, color, visited, m, n, directions);

        return image;
    }
};