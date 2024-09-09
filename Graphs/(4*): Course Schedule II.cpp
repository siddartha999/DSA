/**
Problem link: https://leetcode.com/problems/course-schedule-ii/description/
**/

//DFS. TC: O(V + E), SC: O(V + E)
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




//BFS. TC: O(V + E), SC: O(V + E)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> inorder(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(int row = 0; row < prerequisites.size(); row++) {
            inorder[prerequisites[row][1]]++;
            adj[prerequisites[row][0]].push_back(prerequisites[row][1]);
        }

        queue<int> qq;
        for(int vertex = 0; vertex < numCourses; vertex++) {
            if(inorder[vertex] == 0) qq.push(vertex);
        }

        int verticesProcessed = numCourses;
        while(qq.size() > 0) {
            int vertex = qq.front();
            qq.pop();
            verticesProcessed--;
            for(int idx = 0; idx < adj[vertex].size(); idx++) {
                int adjacentVertex = adj[vertex][idx];
                inorder[adjacentVertex]--;
                if(inorder[adjacentVertex] == 0) {
                    qq.push(adjacentVertex);
                }
            }
            res.push_back(vertex);
        }

        if(verticesProcessed != 0) {
            return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
