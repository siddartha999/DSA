/**
Problem link: https://leetcode.com/problems/course-schedule-ii/description/
**/

//Approach 1: DFS. TC: O(V + E), SC: O(V + E)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> adj(numCourses);
        for(int row = 0; row < prerequisites.size(); row++) {
            adj[prerequisites[row][0]].push_back(prerequisites[row][1]);
        }

        vector<bool> visited(numCourses, false);
        unordered_set<int> path;
        for(int vertex = 0; vertex < numCourses; vertex++) {
            if(!dfs(adj, vertex, visited, res, path)) return {};
        }
        return res;
    }

private:
    bool dfs(vector<vector<int>>& adj, int vertex, vector<bool>& visited, vector<int>& res, unordered_set<int>& path) {
        if(visited[vertex] == true) return true;
        path.insert(vertex);
        visited[vertex] = true;
        for(int idx = 0; idx < adj[vertex].size(); idx++) {
            int adjacentVertex = adj[vertex][idx];
            if(path.find(adjacentVertex) != path.end()) return false;
            if(!dfs(adj, adjacentVertex, visited, res, path)) return false;
        }
        res.push_back(vertex); //Log vertex only after all the dependencies have been resolved.
        path.erase(vertex);
        return true;
    }
};




//Approach 2: BFS. TC: O(V + E), SC: O(V + E)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(int row = 0; row < prerequisites.size(); row++) {
            adj[prerequisites[row][0]].push_back(prerequisites[row][1]);
            indegree[prerequisites[row][1]]++;
        }

        queue<int> bfs;
        for(int vertex = 0; vertex < numCourses; vertex++) {
            if(indegree[vertex] == 0) bfs.push(vertex);
        }

        vector<int> order;
        int verticesProcessed = 0;
        while(bfs.size() > 0) {
            int vertex = bfs.front();
            bfs.pop();
            order.push_back(vertex);
            verticesProcessed++;
            for(int idx = 0; idx < adj[vertex].size(); idx++) {
                int adjacentVertex = adj[vertex][idx];
                indegree[adjacentVertex]--;
                if(indegree[adjacentVertex] == 0) bfs.push(adjacentVertex);
            }
        }

        if(verticesProcessed != numCourses) return {};

        reverse(order.begin(), order.end());
        return order;
    }
};
