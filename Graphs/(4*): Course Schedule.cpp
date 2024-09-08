/**
* Problem link: https://leetcode.com/problems/course-schedule/description/
**/

// DFS: TC: O(V + E), SC: O(V + E)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int row = 0; row < prerequisites.size(); row++) {
            adj[prerequisites[row][0]].push_back(prerequisites[row][1]);
        }

        vector<bool> visited(numCourses, false);
        for(int vertex = 0; vertex < numCourses; vertex++) {
            if(visited[vertex] == true) continue;
            unordered_set<int> path;
            if(!dfs(adj, visited, vertex, path)) return false;
        }

        return true;
    }
private:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int vertex, unordered_set<int>& path) {
        if(path.find(vertex) != path.end()) return false;
        if(visited[vertex] == true) return true;
        path.insert(vertex);
        visited[vertex] = true;
        for(int idx = 0; idx < adj[vertex].size(); idx++) {
            int adjacentVertex = adj[vertex][idx];
            if(!dfs(adj, visited, adjacentVertex, path)) return false;
        }
        path.erase(vertex);
        return true;
    }
};
