/**
* Problem Link: https://www.codingninjas.com/studio/problems/longest-common-substring_123520
* Reference: https://www.youtube.com/watch?v=_wP9mWNPL5w&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=28
**/

// Approach 1: Tabulated. TC: O(N * M), SC: O(N * M)
int lcs(string &str1, string &str2){
    vector<vector<int>> cache(str1.size() + 1, vector<int> (str2.size() + 1, 0));
    int maxVal = 0;
    for(int i = 1; i <= str1.size(); i++) {
        for(int j = 1; j <= str2.size(); j++) {
            if(str1[i - 1] == str2[j - 1]) {
                cache[i][j] = 1 + cache[i - 1][j - 1];
                maxVal = max(maxVal, cache[i][j]);
            }
        }
    }
    return maxVal;
}





// Approach 2: Tabulated with Space Optimized. TC: O(N * M), SC: O(M)
int lcs(string &str1, string &str2){
    vector<int> cache(str2.size() + 1, 0);
    int maxVal = 0;
    for(int i = 1; i <= str1.size(); i++) {
        vector<int> temp = cache;
        for(int j = 1; j <= str2.size(); j++) {
            if(str1[i - 1] == str2[j - 1]) {
                temp[j] = 1 + cache[j - 1];
                maxVal = max(maxVal, temp[j]);
            }
            else {
                temp[j] = 0;
            }
        }
        cache = temp;
    }
    return maxVal;
}
