/**
* Problem Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
* Reference: https://www.youtube.com/watch?v=9XybHVqTHcQ&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=38
**/

// TC: O(E), SC: O(V + E)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(vector<int> flight: flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        queue<pair<int, int>> bfs;
        bfs.push({src, 0});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        int levels = 0;
        while(bfs.size() > 0 && levels <= k) {
            int size = bfs.size();
            while(size--) {
                int node = bfs.front().first;
                int cost = bfs.front().second;
                bfs.pop();
                for(pair<int, int> edge: adj[node]) {
                    int projectedCost = cost + edge.second;
                    int destinationNode = edge.first;
                    if(projectedCost < dist[destinationNode]) {
                        dist[destinationNode] = projectedCost;
                        bfs.push({destinationNode, projectedCost});
                    }
                }
            }
            levels++;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
