/**
* Problem Link: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/
* Reference: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/solutions/1908888/java-c-python-binary-search-with-explanation/
**/

//Approach 1: Brute Force. TC: O(n * maxVal), SC: O(1)
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int res = 0;
        sort(candies.begin(), candies.end());
        for(int idx = 1; idx < candies[candies.size() - 1]; idx++) {
            if(!helper(candies, k, idx)) {
                return idx - 1;
            }
        }
        return candies[candies.size() - 1];
    }

private:
    bool helper(vector<int>& candies, long long k, int count) {
        for(int candy: candies) {
            k -= (candy / count);
            if(k <= 0) return true;
        }
        return false;
    }
};





// Approach 2: Binary Search + Sort. TC: O(nlogn) + O(n * log(maxVal)), SC: O(1)
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int res = 0;
        sort(candies.begin(), candies.end(), std::greater<>());
        int maxVal = candies[0];
        int left = 1, right = maxVal;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(helper(candies, k, mid)) {
                res = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }

private:
    bool helper(vector<int>& candies, long long k, int count) {
        for(int candy: candies) {
            k -= (candy / count);
            if(k <= 0) return true;
        }
        return false;
    }
};





// Approach 3: Binary Search. TC: O(n * log(maxVal)), SC: O(1)
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int res = 0;
        int maxVal = candies[0];
        for(int candy: candies) maxVal = max(maxVal, candy);
        int left = 1, right = maxVal;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(helper(candies, k, mid)) {
                res = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }

private:
    bool helper(vector<int>& candies, long long k, int count) {
        for(int candy: candies) {
            k -= (candy / count);
            if(k <= 0) return true;
        }
        return false;
    }
};
