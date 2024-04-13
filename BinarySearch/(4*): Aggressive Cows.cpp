/**
* https://leetcode.com/problems/magnetic-force-between-two-balls/submissions/1231604599/
* Reference: https://www.youtube.com/watch?v=R_Mfw4ew-Vo&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=20
**/

//Appraoch 1: Brute Force. TC: O(nlogn) + O(maxDiff * n), SC: O(1).
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int maxDiff = position[position.size() - 1] - position[0];
        if(m == 2) return position[position.size() - 1] - position[0];
        
        
        for(int minDistance = 2; minDistance <= maxDiff; minDistance++) {
            if(!isValid(position, m, minDistance)) return minDistance - 1;
        }

        return maxDiff;
    }

private:
    bool isValid(vector<int>& position, int m,int minDistance) {
        m--;
        int lastIndex = 0;
        for(int i = 1; i < position.size(); i++) {
            if(position[i] - position[lastIndex] >= minDistance) {
                lastIndex = i;
                m--;
            }
            if(m == 0) return true;
        }
        return false;
    }
};




// Approach 2: Binary Search. TC: O(nlogn) + O(n * log(maxDiff)), SC: O(1).
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int maxDiff = position[position.size() - 1] - position[0];
        if(m == 2) return position[position.size() - 1] - position[0];
        
        int left = 1, right = maxDiff;
        int res = 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(isValid(position, m, mid)) {
                res = max(res, mid);
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    
        return res;
    }

private:
    bool isValid(vector<int>& position, int m, int minDistance) {
        m--;
        int lastIndex = 0;
        for(int i = 1; i < position.size(); i++) {
            if(position[i] - position[lastIndex] >= minDistance) {
                lastIndex = i;
                m--;
            }
            if(m == 0) return true;
        }
        return false;
    }
};
