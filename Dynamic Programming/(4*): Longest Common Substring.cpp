/**
* Problem Link: https://www.codingninjas.com/studio/problems/longest-common-substring_1235207
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






// Approach 3: Tabulated with Space Optimized with 1 Array. TC: O(N * M), SC: O(N)
int lcs(string &str1, string &str2){
    vector<int> cache(str2.size() + 1, 0);
    int maxVal = 0;
    for(int i = str1.size() - 1; i >= 0; i--) {
        for(int j = 0; j <= str2.size() - 1; j++) {
            if(str1[i] == str2[j]) {
                cache[j] = 1 + cache[j + 1];
                maxVal = max(maxVal, cache[j]);
            }
            else {
                cache[j] = 0;
            }
        }
    }
    return maxVal;
}







// Brute Force Approach. TC: O(2^N * 2^M), SC: O(N + M)
int helper(string&, int, string&, int, int&);

int lcs(string &str1, string &str2){
    int maxVal = 0;
    helper(str1, 0, str2, 0, maxVal);
    return maxVal;
}

int helper(string& a, int i, string& b, int j, int& maxVal) {
    if(i >= a.size() || j >= b.size()) return 0;
    
    int val = 0;
    
    if(a[i] == b[j]) {
        val = 1 + helper(a, i + 1, b, j + 1, maxVal);
        maxVal = max(maxVal, val);
    }
    
    helper(a, i, b, j + 1, maxVal); 
    helper(a, i + 1, b, j, maxVal);
    
    return val;
}






// Memoized Approach. TC: O(N * M), SC: O(N * M) + O(N + M)
int helper(string&, int, string&, int, int&, vector<vector<int>>&);

int lcs(string &str1, string &str2){
    vector<vector<int>> cache(str1.size(), vector<int> (str2.size(), -1));
    int maxVal = 0;
    helper(str1, 0, str2, 0, maxVal, cache);
    return maxVal;
}

int helper(string& a, int i, string& b, int j, int& maxVal, vector<vector<int>>& cache) {
    if(i >= a.size() || j >= b.size()) return 0;
    
    if(cache[i][j] != -1) return cache[i][j];
    
    int val = 0;
    
    
    if(a[i] == b[j]) {
        val = 1 + helper(a, i + 1, b, j + 1, maxVal, cache);
        maxVal = max(maxVal, val);
    }
    
    helper(a, i, b, j + 1, maxVal, cache); 
    helper(a, i + 1, b, j, maxVal, cache);
    
    cache[i][j] = val;
    return val;
}
