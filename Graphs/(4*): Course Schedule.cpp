/**
* Problem link: https://leetcode.com/problems/course-schedule/description/
**/

// Approach 1: DFS => TC: O(V + E), SC: O(V + E)
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








// Approach 2: BFS. TC: O(V + E), SC: O(V + E)
// Notes: Processing vertices with zero indegree nodes makes the visualization easier.
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(int row = 0; row < prerequisites.size(); row++) {
            indegree[prerequisites[row][1]]++;
            adj[prerequisites[row][0]].push_back(prerequisites[row][1]);
        }

        queue<int> qq;
        for(int vertex = 0; vertex < numCourses; vertex++) {
            if(indegree[vertex] == 0) qq.push(vertex);
        }

        int verticesProcessed = 0;
        while(qq.size() > 0) {
            int vertex = qq.front();
            qq.pop();
            verticesProcessed++;
            for(int idx = 0; idx < adj[vertex].size(); idx++) {
                int adjacentVertex = adj[vertex][idx];
                indegree[adjacentVertex]--;
                if(indegree[adjacentVertex] == 0) {
                    qq.push(adjacentVertex);
                }
            }
        }
        
        return verticesProcessed == numCourses ? true : false;
    }
};
