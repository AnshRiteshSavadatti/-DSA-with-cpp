// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1


#include <bits/stdc++.h>
using namespace std;


void dfs(vector<int> adj[], vector<int>& ddfs, vector<bool>& visited){
    int temp = ddfs[ddfs.size()-1];
    
    for(auto it : adj[temp]){
        if(!visited[it]){
            visited[it] = true;
            ddfs.push_back(it);
            dfs(adj, ddfs, visited);
        }
    }
}
// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<int> ddfs;
    vector<bool> visited(V, false);
    
    ddfs.push_back(0);
    visited[0] = true;
    
    dfs(adj, ddfs, visited);
    
    return ddfs;
}