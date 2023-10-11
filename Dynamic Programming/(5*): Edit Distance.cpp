/**
* Problem Link: https://www.codingninjas.com/studio/problems/edit-distance_630420
* Reference: https://youtu.be/fJaKO8FbDdo?si=hbK2AdlC7p8a4oeV
**/

// Approach 1: Brute Force. TC: O(2^M * 2^N), SC: O(N + M).
int editDistance(string str1, string str2)
{
    return helper(str1, 0, str2, 0);
}

int helper(string& str1, int i, string& str2, int j) {
    if(i >= str1.size()) return str2.size() - j;
    if(j >= str2.size()) return str1.size() - i;

    if(str1[i] == str2[j]) {
        return helper(str1, i + 1, str2, j + 1);
    }

    int add = helper(str1, i, str2, j + 1);
    int del = helper(str1, i + 1, str2, j);
    int replace = helper(str1, i + 1, str2, j + 1);

    return 1 + min(add, min(del, replace));
}





// Approach 2: Memoized. TC: O(N * M), SC: O(N + M)
int editDistance(string str1, string str2)
{
    vector<vector<int>> cache(str1.size(), vector<int> (str2.size(), -1));
    return helper(str1, 0, str2, 0, cache);
}

int helper(string& str1, int i, string& str2, int j, vector<vector<int>>& cache) {
    if(i >= str1.size()) return str2.size() - j;
    if(j >= str2.size()) return str1.size() - i;

    if(cache[i][j] != -1) return cache[i][j];

    if(str1[i] == str2[j]) {
        cache[i][j] = helper(str1, i + 1, str2, j + 1, cache);
        return cache[i][j];
    }

    int add = helper(str1, i, str2, j + 1, cache);
    int del = helper(str1, i + 1, str2, j, cache);
    int replace = helper(str1, i + 1, str2, j + 1, cache);

    cache[i][j] = 1 + min(add, min(del, replace));
    return cache[i][j];
}






// Approach 3: Tabulated. TC: O(N * M), SC: O(N + M)
int editDistance(string str1, string str2)
{
    vector<vector<int>> cache(str1.size() + 1, vector<int> (str2.size() + 1, 0));

    for(int j = 0; j <= str2.size(); j++) cache[str1.size()][j] = str2.size()  - j;
    for(int i = 0; i <= str1.size(); i++) cache[i][str2.size()] = str1.size()  - i;

    for(int i = str1.size() - 1; i >= 0; i--) {
        for(int j = str2.size() - 1; j >= 0; j--) {
            if(str1[i] == str2[j]) {
                cache[i][j] = cache[i + 1][j + 1];
            }
            else {
                int add = cache[i][j + 1];
                int del = cache[i + 1][j];
                int rep = cache[i + 1][j + 1];
                cache[i][j] = 1 + min(add, min(del, rep));
            }
        }
    }

    return cache[0][0];
}






// Approach 4: Tabulated with Space Optimized. TC: O(N * M), SC: O(M * 2)
int editDistance(string str1, string str2)
{
    vector<int> cache(str2.size() + 1, 0);

    for(int j = 0; j <= str2.size(); j++) cache[j] = str2.size()  - j;

    for(int i = str1.size() - 1; i >= 0; i--) {
        vector<int> temp = cache;
        temp[str2.size()] = str1.size() - i; // Visualize the matrix!
        for(int j = str2.size() - 1; j >= 0; j--) {
            if(str1[i] == str2[j]) {
                temp[j] = cache[j + 1];
            }
            else {
                int add = temp[j + 1];
                int del = cache[j];
                int rep = cache[j + 1];
                temp[j] = 1 + min(add, min(del, rep));
            }
        }
        cache = temp;
    }
    
    return cache[0];
}
