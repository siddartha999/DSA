/**
* Problem Link: https://leetcode.com/problems/group-anagrams/description/
**/


// TC: O(N * K), SC: O(N * K)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> cache;
        for(string str: strs) {
            string ss = helper(str);
            cache[ss].push_back(str);
        }
        for(auto it = cache.begin(); it != cache.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
private:
    string helper(string& str) {
        string res = "";
        vector<int> chars(26, 0);
        for(char c: str) {
            chars[c - 'a']++;
        }
        for(int idx = 0; idx < 26; idx++) {
            if(chars[idx] > 0) {
                res += to_string('a' + idx) + to_string(chars[idx]); 
            }
        }
        return res;
    }
};
