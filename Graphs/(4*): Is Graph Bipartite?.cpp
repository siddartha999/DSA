/**
* Problem link 1: https://leetcode.com/problems/is-graph-bipartite/description/
* Problem link 2: https://www.geeksforgeeks.org/problems/bipartite-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
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



// Approach: DFS. TC: O(V + E), SC: O(V + E)
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<char> color(V, 'd');
	    for(int vertex = 0; vertex < V; vertex++) {
	        if(color[vertex] != 'd') continue;
	        if(!isValid(adj, color, V, vertex)) {
	            return false;
	        }
	    }
	    return true;
	}

private:
    bool isValid(vector<int> adj[], vector<char>& color, int V, int vertex) {
        if(vertex >= V || adj[vertex].size() == 0) {
            return true;
        }
        
        if(color[vertex] == 'd') color[vertex] = 'a';
        int adjacentVertexColor = (color[vertex] == 'a') ? 'b' : 'a';
        for(int idx = 0; idx < adj[vertex].size(); idx++) {
            int adjacentVertex = adj[vertex][idx];
            if(color[adjacentVertex] != 'd') {
                if(color[adjacentVertex] != adjacentVertexColor) return false;
                continue;
            }
            color[adjacentVertex] = adjacentVertexColor;
            if(!isValid(adj, color, V, adjacentVertex)) return false;
        }
        return true;
    }

};
