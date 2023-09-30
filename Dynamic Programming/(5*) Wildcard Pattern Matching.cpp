/**
* Problem Link: https://www.codingninjas.com/studio/problems/wildcard-pattern-matching_701650?
* Reference: https://www.youtube.com/watch?v=ZmlQ3vgAOMo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=36
**/


// Approach 1: Brute Force.
bool wildcardMatching(string pattern, string text)
{
   return helper(pattern, 0, text, 0);
}

bool helper(string& pattern, int i, string& text, int j) {
   if(i >= pattern.size() && j >= text.size()) return true;
   if(i >= pattern.size()) return false;

   if(j >= text.size()) {
      for(int index = i; index < pattern.size(); index++) {
         if(pattern[index] != '*') return false;
      }
      return true;
   }

   if(pattern[i] == text[j] || pattern[i] == '?') {
      return helper(pattern, i + 1, text, j + 1);
   }
   
   if(pattern[i] == '*') {
      return helper(pattern, i , text, j + 1) || helper(pattern, i + 1, text, j);
   }

   return false;
}





// Approach 2: Memoized. TC: O(N * M), SC: O(N * M) + O(N + M)
bool wildcardMatching(string pattern, string text)
{
   vector<vector<int>> cache(pattern.size(), vector<int> (text.size() + 1, - 1));
   return helper(pattern, 0, text, 0, cache);
}

bool helper(string& pattern, int i, string& text, int j, vector<vector<int>>& cache) {
   if(i >= pattern.size() && j >= text.size()) return true;
   if(i >= pattern.size()) return false;

   if(cache[i][j] != -1) {
      return cache[i][j];
   }

   if(j >= text.size()) {
      for(int idx = i; idx < pattern.size(); idx++) {
         if(pattern[idx] != '*') return false;
      }
      return true;
   }

   if(pattern[i] == text[j] || pattern[i] == '?') {
      bool res = helper(pattern, i + 1, text, j + 1, cache);
      cache[i][j] = (res == false ? 0 : 1);
      return res;
   }
   
   
   if(pattern[i] == '*') {
      cache[i][j] = helper(pattern, i , text, j + 1, cache) || helper(pattern, i + 1, text, j, cache);
      return cache[i][i];
   }

   cache[i][j] = 0;
   return cache[i][j];
}







// Approach 3: Tabulated. TC: O(N * M), SC: O(N + M)
bool wildcardMatching(string pattern, string text)
{
   vector<vector<bool>> cache(pattern.size() + 1, vector<bool> (text.size() + 1, false));
   cache[0][0] = true;

   for(int i = 1; i <= pattern.size(); i++) {
      bool flag = true;
      for(int j = 1; j <= i; j++) {
         if(pattern[j - 1] != '*') {
            flag = false; break;
         }
      }
      cache[i][0] = flag;
   }

   for(int i = 1; i <= pattern.size(); i++) {
      for(int j = 1; j <= text.size(); j++) {
         if(pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?') {
            cache[i][j] = cache[i - 1][j - 1];
         }

         else if(pattern[i - 1] == '*') {
            cache[i][j] = cache[i][j - 1] || cache[i - 1][j];
         }

      }
   }

   return cache[pattern.size()][text.size()];
}







// Tabulated with Space Optimized. TC: O(N * M), SC: O(M)
bool wildcardMatching(string pattern, string text)
{
   vector<bool> cache(text.size() + 1, false);
   cache[0] = true;

   for(int i = 1; i <= pattern.size(); i++) {
      vector<bool> temp = cache;
      
      bool flag = true;
      for(int idx = 1; idx <= i; idx++) {
         if(pattern[idx - 1] != '*') {flag = false; break;}
      }
      temp[0] = flag;

      for(int j = 1; j <= text.size(); j++) {
         if(pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?') {
            temp[j] = cache[j - 1];
         }
         else if(pattern[i - 1] == '*') {
            temp[j] = temp[j - 1] || cache[j];
         }
         else {
            temp[j] = false;
         }
      }
      cache = temp;
   }

   return cache[text.size()];
}
