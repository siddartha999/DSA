/**
* Problem link: https://leetcode.com/problems/is-graph-bipartite/description/
**/

// Approach 1: BFS. TC: O(V + E), SC: O(V + E)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<char> color(graph.size(), 'd');
        for(int idx = 0; idx < graph.size(); idx++) {
            if(color[idx] != 'd') continue;
            queue<int> qq;
            qq.push(idx);
            while(qq.size() > 0) {
                int vertex = qq.front();
                qq.pop();
                if(color[vertex] == 'd') color[vertex] = 'a';
                char expectedNextVertexColor = (color[vertex] == 'a') ? 'b' : 'a';
                for(int idx = 0; idx < graph[vertex].size(); idx++) {
                    int nextVertex = graph[vertex][idx];
                    if(color[nextVertex] != 'd') {
                        if(color[nextVertex] == expectedNextVertexColor) continue;
                        if(color[nextVertex] != expectedNextVertexColor) return false;
                    }
                    color[nextVertex] = expectedNextVertexColor;
                    qq.push(nextVertex);
                }
            }
        }
   
        return true;
    }
};
