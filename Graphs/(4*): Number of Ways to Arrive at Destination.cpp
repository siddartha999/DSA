/**
* Problem link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
* Ref: https://www.youtube.com/watch?v=_-0mx0SmYxA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=40
**/

//TC: Similar to Dijkstara's. TC: O((V + E)logV), SC: O(V)
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long, long long>>> adj(n);
        for(vector<int> road: roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        int MOD = 1e9 + 7;
        long long INF = 1e15;
        vector<long long> dist (n, INF);
        vector<long long> ways (n, 0);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> bfs;
        dist[0] = 0;
        ways[0] = 1;
        bfs.push({0, 0});
        while(bfs.size() > 0) {
            long long cost = bfs.top().first;
            long long vertex = bfs.top().second;
            bfs.pop();
            if(cost > dist[vertex]) continue;
            for(pair<int, long long> edge: adj[vertex]) {
                long long receiverVertex = edge.first;
                long long projectedCost = cost + edge.second;
                if(projectedCost < dist[receiverVertex]) {
                    ways[receiverVertex] = ways[vertex];
                    dist[receiverVertex] = projectedCost;
                    bfs.push({projectedCost, receiverVertex});
                }
                else if(projectedCost == dist[receiverVertex]) {
                    ways[receiverVertex] = (ways[receiverVertex] + ways[vertex]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};
