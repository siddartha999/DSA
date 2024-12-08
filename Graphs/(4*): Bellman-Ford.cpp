/**
* Problem link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
* Ref: https://www.youtube.com/watch?v=0vVofAhAYjc&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=43
**/

//TC: O(V * E)
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    int maxVal = pow(10, 8);
    vector<int> res(V, maxVal);
    res[src] = 0;
    for(int idx = 0; idx < V; idx++) {
        for(vector<int> edge: edges) {
            if(res[edge[0]] == maxVal) continue;
            if(res[edge[0]] + edge[2] < res[edge[1]]) {
                res[edge[1]] = res[edge[0]] + edge[2];
            }
        }
    }
   
   //Nth-iteration: final relaxation
   for(vector<int> edge: edges) {
        if(res[edge[0]] == maxVal) continue;
        if(res[edge[0]] + edge[2] < res[edge[1]]) {
            return {-1};
        }
    }
    return res;
}
