/**
* Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
*/

// Approach 1: Brute Force; TC: O(NM), SC: O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()) return -1;

        for(int i = 0; i <= haystack.size() - needle.size(); i++) {
            bool isMatched = true;
            for(int j = 0; j < needle.size(); j++) {
                if(needle[j] != haystack[i + j]) {
                    isMatched = false;
                    break;
                }
            }
            if(isMatched == true) return i;
        }

        return -1;
    }
};



// Approach 2: KMP: Visualize it!;  TC: O(M), Pre-processing: O(N), SC: O(N).  
// N: size(needle), M: size(haystack);
// Visualize with haystack: "mememes" & needle: "memes". The goal of KMP is to avoid the redundant work

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()) return -1;

        vector<int> lps(needle.size(), 0);

        //Populate the longest boundary array
        int prev = 0, idx = 1;
        while(idx < needle.size()) {
            if(needle[idx] == needle[prev]) {
                prev += 1;
                lps[idx] = prev;
                idx++;
            }
            else {
                if(prev == 0) idx++;
                else prev = lps[prev - 1];
            }
        }

        //Searching for needle in a haystack
        int np = 0;
        for(int i = 0; i < haystack.size(); i++) {
            if(haystack[i] == needle[np]) {
                np++;
            }
            else {
                while(np > 0) {
                    np = lps[np - 1];
                    if(haystack[i] == needle[np]) {
                        np++;
                        break;
                    }
                } 
            }

            if(np == needle.size()) return i - np + 1;
        }

        return -1;
    }
};
