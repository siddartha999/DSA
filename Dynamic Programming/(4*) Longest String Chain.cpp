/**
* Problem Link: https://leetcode.com/problems/longest-string-chain/description/
**/

// TC: O(N * N * maxLenOfString), SC: O(N)
class Solution {
private:
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
public:
    int longestStrChain(vector<string>& words) {
       sort(words.begin(), words.end(), compare);
        vector<int> lsc(words.size(), 1);
        int maxVal = 1;

        for(int idx = 1; idx < words.size(); idx++) {
            for(int prev = 0; prev < idx; prev++) {
                if(helper(words[idx], words[prev])) {
                    lsc[idx] = max(lsc[idx], 1 + lsc[prev]);
                }
            }
            maxVal = max(maxVal, lsc[idx]);
        }

        return maxVal;
    }
private:
    bool helper(string& word1, string& word2) {
        if(word1.size() != word2.size() + 1) return false;
        int i = 0, j = 0;
        bool oneChance = false;
        while(i < word1.size() && j < word2.size()) {
            if(word1[i] == word2[j]) {
                i++;
                j++;
                continue;
            }
            if(oneChance == true) return false;
            oneChance = true;
            i++;
        }
        return true;
    }
};
