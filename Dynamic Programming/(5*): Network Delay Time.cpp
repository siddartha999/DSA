/**
* Problem link: https://leetcode.com/problems/network-delay-time/description/
* Dijkstras Algorithm: https://www.youtube.com/watch?v=3dINsjyfooY&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=34
**/

//TC: O(E * logV) => E: V^2
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(vector<int> time: times) {
            int originVertex = time[0];
            int receiverVertex = time[1];
            int t = time[2];
            adj[originVertex].push_back({t, receiverVertex});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> bfs;
        vector<int> cache(n + 1, -1);
        bfs.push({0, k});
        int visitedCount = 0;
        while(bfs.size() > 0) {
            int vertex = bfs.top().second;
            int time = bfs.top().first;
            bfs.pop();
            if(cache[vertex] != -1) continue;
            cache[vertex] = time;
            visitedCount++;
            if(visitedCount == n) break;
            for(int idx = 0; idx < adj[vertex].size(); idx++) {
                int receiverVertex = adj[vertex][idx].second;
                int t = adj[vertex][idx].first;
                bfs.push({t + time, receiverVertex});
            }
        }

        if(visitedCount != n) return -1;

        int minTime = -1;
        for(int idx = 1; idx < cache.size(); idx++) {
            if(idx != k && minTime < cache[idx]) minTime = cache[idx];
        }

        return minTime;
    }
};
