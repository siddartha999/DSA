/**
* Problem link: https://leetcode.com/problems/word-ladder-ii/
**/

// Approach 1: BFS with saved paths
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        vector<vector<string>> res;
        bool isEndWordInList = false;
        for(string word: wordList) {
            if(word == endWord) isEndWordInList = true;
            words.insert(word);
        }
        if(isEndWordInList == false) return res;
        queue<pair<string, vector<string>>> bfs;
        bfs.push({beginWord, {beginWord}});
        words.erase(beginWord);
        
        while(bfs.size() > 0) {
            int size = bfs.size();
            unordered_set<string> wordsToRemove;
            while(size--) {
                string word = bfs.front().first;
                vector<string> path = bfs.front().second;
                bfs.pop();
                for(int idx = 0; idx < word.length(); idx++) {
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        string newWord = word;
                        newWord[idx] = ch;
                        if(newWord == word) continue;
                        if(newWord == endWord) {
                            vector<string> newPath = path;
                            newPath.push_back(newWord);
                            res.push_back(newPath);
                            continue;
                        }
                        if(words.find(newWord) != words.end()) {
                            vector<string> newPath = path;
                            newPath.push_back(newWord);
                            wordsToRemove.insert(newWord);
                            bfs.push({newWord, newPath});
                        }
                    }
                }
            }
            if(res.size() > 0) { //Break-out as soon as the current level produces a path to the endWord
                break;
            }
            for(auto it = wordsToRemove.begin(); it != wordsToRemove.end(); it++) {
                words.erase(*it);
            }
        }



        return res;
    }
};









// Approach 2: BFS + DFS with path construction.
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        vector<vector<string>> res;
        bool isEndWordInList = false;
        for(string word: wordList) {
            if(word == endWord) isEndWordInList = true;
            words.insert(word);
        }
        if(isEndWordInList == false) return res;
        queue<string> bfs;
        bfs.push(beginWord);
        words.erase(beginWord);
        unordered_map<string, int> distanceMap;
        distanceMap[beginWord] = 0;
        int distance = 1;
        bool isEndWordReached = false;
        while(bfs.size() > 0) {
            int size = bfs.size();
            while(size--) {
                string word = bfs.front();
                bfs.pop();
                for(int idx = 0; idx < word.length(); idx++) {
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        string newWord = word;
                        newWord[idx] = ch;
                        if(newWord == endWord) {
                            isEndWordReached = true;
                            break;
                        }
                        if(newWord == word) continue;
                        if(words.find(newWord) != words.end()) {
                            words.erase(newWord);
                            distanceMap[newWord] = distance;
                            bfs.push(newWord);
                        }
                    }
                }
            }
            if(isEndWordReached == true) break;
            distance++;
        }

        if(isEndWordReached == false) {
            return res;
        }

        vector<string> path;
        path.push_back(endWord);
        constructSequences(beginWord, res, distanceMap, path, endWord, distance - 1);
        return res;

    }
private:
    void constructSequences(string& beginWord, vector<vector<string>>& res, unordered_map<string, int>& distanceMap, vector<string>& path, string currentWord, int minimalLevel) {
        if(currentWord == beginWord) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }
        for(int idx = 0; idx < currentWord.length(); idx++) {
            for(char ch = 'a'; ch <= 'z'; ch++) {
                string newWord = currentWord;
                newWord[idx] = ch;
                if(newWord == currentWord) continue;
                if(distanceMap[newWord] == minimalLevel) {
                    path.push_back(newWord);
                    constructSequences(beginWord, res, distanceMap, path, newWord, minimalLevel - 1);
                    path.pop_back();
                }
            }
        }
    }
};
