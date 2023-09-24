/**
* Problem Link: https://www.codingninjas.com/studio/problems/can-you-make_4244510
**/

// TC: O(N * M), SC: O(M)
int canYouMake(string &s1, string &s2){
    vector<int> cache(s2.size() + 1, 0);
    for(int i = 1; i <= s1.size(); i++) {
        vector<int> temp = cache;
        for(int j = 1; j <= s2.size(); j++) {
            if(s1[i - 1] == s2[j - 1]) {
                temp[j] = 1 + cache[j - 1];
            }
            else {
                temp[j] = max(temp[j - 1], cache[j]);
            }
        }
        cache = temp;
    }

    return s1.size() + s2.size() - (2 * cache[s2.size()]);
}
