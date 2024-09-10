/**
* Problem link: https://leetcode.com/problems/find-eventual-safe-states/description/
**/

// Approach 1: DFS with current traversal path. TC: O(V+ E), SC: O(V + E)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safeNodes;
        vector<int> vertexResultCache(graph.size(), -1); 
        for(int vertex = 0; vertex < graph.size(); vertex++) {
            if(graph[vertex].size() == 0) {
                safeNodes.push_back(vertex);
            }
            else if(vertexResultCache[vertex] == -1) {
                unordered_set<int> path;
                dfs(graph, vertex, safeNodes, path, vertexResultCache);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }

private:
    bool dfs(vector<vector<int>>& graph, int vertex, vector<int>& safeNodes, unordered_set<int>& path, vector<int>&     vertexResultCache) {
        if(path.find(vertex) != path.end()) return false;
        if(graph[vertex].size() == 0) return true;
        if(vertexResultCache[vertex] != -1) {
            return vertexResultCache[vertex];
        }

        path.insert(vertex);
        for(int idx = 0; idx < graph[vertex].size(); idx++) {
            int receiverVertex = graph[vertex][idx];
            if(dfs(graph, receiverVertex, safeNodes, path, vertexResultCache) == false) {
                vertexResultCache[vertex] = 0;
                return false;
            }
        }
        path.erase(vertex);
        safeNodes.push_back(vertex);
        vertexResultCache[vertex] = 1;
        return true;
    }
};














// Approach 2: DFS without current traversal path. TC: O(V+ E), SC: O(V + E)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safeNodes;
        vector<int> vertexResultCache(graph.size(), -1); 
        for(int vertex = 0; vertex < graph.size(); vertex++) {
            if(graph[vertex].size() == 0) {
                safeNodes.push_back(vertex);
            }
            else if(vertexResultCache[vertex] == -1) {
                dfs(graph, vertex, safeNodes, vertexResultCache);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }

private:
    bool dfs(vector<vector<int>>& graph, int vertex, vector<int>& safeNodes, vector<int>& vertexResultCache) {
        if(graph[vertex].size() == 0) return true;
        if(vertexResultCache[vertex] != -1) {
            if(vertexResultCache[vertex] == 2 || vertexResultCache[vertex] == 0) return false;
            return true;
        }

        vertexResultCache[vertex] = 2;
        for(int idx = 0; idx < graph[vertex].size(); idx++) {
            int receiverVertex = graph[vertex][idx];
            if(dfs(graph, receiverVertex, safeNodes, vertexResultCache) == false) {
                vertexResultCache[vertex] = 0;
                return false;
            }
        }
        safeNodes.push_back(vertex);
        vertexResultCache[vertex] = 1;
        return true;
    }
};











// Approach 3: BFS. TC: O(V + E), SC: O(V + E). A similiarish BFS approach to CourseSchedule problems
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safeNodes;
        vector<vector<int>> incomingVertices(graph.size());
        queue<int> bfs;
        vector<int> outdegree(graph.size(), 0);
        for(int vertex = 0; vertex < graph.size(); vertex++) {
            if(graph[vertex].size() == 0) {
                bfs.push(vertex);
                continue;
            }
            outdegree[vertex] = graph[vertex].size();
            for(int outgoingEdge = 0; outgoingEdge < graph[vertex].size(); outgoingEdge++) {
                int receiverVertex = graph[vertex][outgoingEdge];
                incomingVertices[receiverVertex].push_back(vertex);
            }
        }

        vector<int> res;
        while(bfs.size() > 0) {
            int vertex = bfs.front();
            bfs.pop();
            res.push_back(vertex);
            for(int incomingEdge = 0; incomingEdge < incomingVertices[vertex].size(); incomingEdge++) {
                int incomingVertex = incomingVertices[vertex][incomingEdge];
                outdegree[incomingVertex]--;
                if(outdegree[incomingVertex] == 0) bfs.push(incomingVertex);
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};
