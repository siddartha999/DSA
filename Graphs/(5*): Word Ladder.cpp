/**
* Problem link: https://leetcode.com/problems/word-ladder/description/
**/


//Approach 1: BFS. TLE on leetcode (length of a word is much smaller than the size of wordList). TC: O(N^2 * M). N: wordList length, M: length of a word
//BFS is preferred to DFS as a level-by-level traversal determines the shorter path faster.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord || beginWord.size() != endWord.size()) return 0;
        unordered_map<string, vector<string>> adj;
        bool isEndWordInList = false;
        adj[beginWord] = {};
        for(string word: wordList) {
            adj[word] = {};
        }
        for(string word: wordList) {
            if(word == endWord) isEndWordInList = true;
            for(auto it = adj.begin(); it != adj.end(); it++) {
                string key = it->first;
                vector<string> nodes = it->second;
                if(key != word) {
                    int idx = 0;
                    int diff = 0;
                    while(idx < key.length()) {
                        if(key[idx] != word[idx]) diff++;
                        if(diff > 1) break;
                        idx++;
                    }
                    if(diff == 1) nodes.push_back(word);
                    adj[key] = nodes;
                }
            }
        }
        if(isEndWordInList == false) return 0;

        unordered_set<string> visited;
        queue<string> bfs;
        bfs.push(beginWord);
        int transformations = 1;
        while(bfs.size() > 0) {
            int size = bfs.size();
            while(size--) {
                string word = bfs.front();
                bfs.pop();
                for(int idx = 0; idx < adj[word].size(); idx++) {
                    string adjacentWord = adj[word][idx];
                    if(adjacentWord == endWord) return transformations;
                    if(visited.find(adjacentWord) != visited.end()) {
                        bfs.push(adjacentWord);
                        visited.insert(adjacentWord);
                    }
                }
            }
            transformations++;
        }

        return 0;
    }
};









// Approach 2: BFS. TC: O(N * (M * 26)), SC: O(N * M). N: wordList length, M: length of a word
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord || beginWord.size() != endWord.size()) return 0;
        bool isEndWordInList = false;
        unordered_set<string> words;
        for(string word: wordList) {
            words.insert(word);
            if(word == endWord) isEndWordInList = true;
        }
        if(isEndWordInList == false) return 0;
        queue<string> bfs;
        bfs.push(beginWord);
        words.erase(beginWord);
        int transformations = 1;
        while(bfs.size() > 0) {
            int size = bfs.size();
            while(size--) {
                string word = bfs.front();
                bfs.pop();
                for(int idx = 0; idx < word.size(); idx++) {
                    for(char c = 'a'; c <= 'z'; c++) {
                        string newWord = word;
                        newWord[idx] = c;
                        if(words.find(newWord) != words.end()) {
                            if(newWord == endWord) return transformations + 1;
                            bfs.push(newWord);
                            words.erase(newWord);
                        }
                    }
                }
            }
            transformations++;
        }

        return 0;
    }
};
