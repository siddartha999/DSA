/**
* Problem link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
**/

// TC: O(V), SC: O(V). NOTE: Topological Sort does not fit in an undirected graph setting
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src){
        vector<vector<int>> adj(N);
        for(int idx = 0; idx < M; idx++) {
            int originVertex = edges[idx][0];
            int receiverVertex = edges[idx][1];
            adj[originVertex].push_back(receiverVertex);
            adj[receiverVertex].push_back(originVertex);
        }
        
        queue<int> bfs;
        vector<int> res(N, -1);
        res[src] = 0;
        bfs.push(src);
        
        while(!bfs.empty()) {
            int vertex = bfs.front();
            bfs.pop();
            for(int idx = 0; idx < adj[vertex].size(); idx++) {
                int adjacentVertex = adj[vertex][idx];
                if(res[adjacentVertex] == -1) { //adjacentVertex is visited for the first-time
                    res[adjacentVertex] = res[vertex] + 1;
                    bfs.push(adjacentVertex);
                }
            }
        }
        
        return res;
    }
};
