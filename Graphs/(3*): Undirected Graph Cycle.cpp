/**
* Problem link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
**/

//DFS. TC: O(V + 2E), SC: O(V)
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for(int idx = 0; idx < V; idx++) {
            if(visited[idx] == true) {
                continue;
            }
            if(detectCycle(idx, adj, visited, idx)) {
                 return true;
            }
        }
        return false;
    }
private:
    bool detectCycle(int vertex, vector<int> adj[], vector<bool>& visited, int prevVertex) {
        if(visited[vertex] == true) return true;
        visited[vertex] = true;
        for(int idx = 0; idx < adj[vertex].size(); idx++) {
            int nextVertex = adj[vertex][idx];
            if(prevVertex != nextVertex) {
                bool isCycle = detectCycle(nextVertex, adj, visited, vertex);
                if(isCycle == true) return true;
            }
        }
        return false;
    }
};
