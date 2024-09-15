/**
* Problem link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
**/

// Aproach 1: TC: O(V + E), SC: O(V + E)
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(N);
        for(int idx = 0; idx < M; idx++) {
            vector<int> edge = edges[idx];
            int originVertex = edge[0];
            int receiverVertex = edge[1];
            int weight = edge[2];
            adj[originVertex].push_back({weight, receiverVertex});
        }
        
        vector<int> res(N, -1);
        vector<bool> visited(N, false);
        dfs(adj, res, visited, 0, 0);
        return res;
    }
    
private:
    void dfs(vector<vector<pair<int, int>>>& adj, 
        vector<int>& res, vector<bool>& visited, int vertex, int pathWeight) {
        if(res[vertex] != -1) {
            if(res[vertex] < pathWeight) {
                return;
            }
            else {
                res[vertex] = min(res[vertex], pathWeight);
            }
        }
        else {
            res[vertex] = pathWeight;
        }
        
        if(res[vertex] == -1) {
        }
        
        for(int idx = 0; idx < adj[vertex].size(); idx++) {
            pair<int, int> pp = adj[vertex][idx];
            int weight = pp.first;
            int receiverVertex = pp.second;
            dfs(adj, res, visited, receiverVertex, pathWeight + weight);
        }
    }
};
