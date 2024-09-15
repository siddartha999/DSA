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







//Approach 2: Topological Sort. TC: O(V + E), SC: O(V + E)
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int, int>>> adj(N);
        for(int idx = 0; idx < edges.size(); idx++) {
            int originVertex = edges[idx][0];
            int receiverVertex = edges[idx][1];
            adj[originVertex].push_back({receiverVertex, edges[idx][2]});
        }
        stack<int> stack;
        vector<bool> visited(N, false);
        
        dfs(adj, stack, visited, 0);   
        vector<int> res(N, -1);
        res[0] = 0;
        while(!stack.empty()) {
            int vertex = stack.top();
            stack.pop();
            for(int idx = 0; idx < adj[vertex].size(); idx++) {
                int receiverVertex = adj[vertex][idx].first;
                int weight = adj[vertex][idx].second;
                if(res[receiverVertex] == -1) {
                    res[receiverVertex] = res[vertex] + weight;
                }
                else if(res[receiverVertex] > res[vertex] + weight) {
                    res[receiverVertex] = res[vertex] + weight;
                }
            }
        }
        return res;
    }
    
private: 
    void dfs(vector<vector<pair<int, int>>>& adj, stack<int>& stack, vector<bool>& visited, int vertex) {
        if(visited[vertex] == true) {
            return;
        }
        visited[vertex] = true;
        for(int idx = 0; idx < adj[vertex].size(); idx++) {
            int receiverVertex = adj[vertex][idx].first;
            dfs(adj, stack, visited, receiverVertex);
        }
        stack.push(vertex);
    }
};
