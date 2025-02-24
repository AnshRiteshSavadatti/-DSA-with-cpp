// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        vector<bool> visited(V, false);
        
        q.push(0);
        visited[0] = true;
        
        vector<int> bfs;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            bfs.push_back(curr);
            
            for(auto it : adj[curr]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        
        return bfs;
    }