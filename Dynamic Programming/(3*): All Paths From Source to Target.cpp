/**
* Problem link: https://leetcode.com/problems/all-paths-from-source-to-target/description/
**/

//DFS. TC: O(N * 2^N)
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        dfs(graph, 0, path, res);
        return res;
    }
private:
    void dfs(vector<vector<int>>& graph, int vertex, vector<int>& path, vector<vector<int>>& res) {
        if(vertex == graph.size() - 1) {
            res.push_back(path);
            return;
        }
        for(int idx = 0; idx < graph[vertex].size(); idx++) {
            int receiverVertex = graph[vertex][idx];
            path.push_back(receiverVertex);
            dfs(graph, receiverVertex, path, res);
            path.pop_back();
        }
    }
};
