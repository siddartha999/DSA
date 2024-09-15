/**
* Problem Statement: https://www.geeksforgeeks.org/problems/alien-dictionary/1
**/
// User function Template for C++

class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        vector<vector<char>> adj(26);
        for(int col = 1; col < n; col++) {
            string prevWord = dict[col - 1];
            string word = dict[col];
            int idx = 0;
            while(idx < prevWord.length() && idx < word.length()) {
                if(prevWord[idx] == word[idx]) {
                    idx++;
                    continue;
                }
                adj[prevWord[idx] - 'a'].push_back(word[idx]);
                break;
            }
        }
        
        vector<bool>visited (26, false);
        stack<char> stack;
        for(int idx= 0; idx < k; idx++) {
            dfs(adj, idx + 'a', visited, stack);
        }
        
        string res = "";
        while(!stack.empty()) {
            res += stack.top();
            stack.pop();
        }
        
        return res;
    }
    
private:
    void dfs(vector<vector<char>>& adj, char ch, vector<bool>& visited, stack<char>& stack) {
        if(visited[ch - 'a'] == true) return;
        visited[ch - 'a'] = true;
        for(int col = 0; col < adj[ch - 'a'].size(); col++) {
            dfs(adj, adj[ch - 'a'][col], visited, stack);
        }
        stack.push(ch);
    }
};
