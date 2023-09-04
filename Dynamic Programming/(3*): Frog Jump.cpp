/**
* Problem: https://www.codingninjas.com/studio/problems/frog-jump_3621012
* Referene: https://www.youtube.com/watch?v=EgG3jsGoPvQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=5
**/

//Approach 1: Memoization. TC: O(N), SC: O(N)
int helper(vector<int> &nums, vector<int>& cache, int idx) {
    if(idx >= nums.size()) return INT_MAX;

    if(idx == nums.size() - 1) return 0;

    if (cache[idx] != -1) return cache[idx];

    int jumpOne = abs(nums[idx] - nums[idx + 1]) + helper(nums, cache, idx + 1);

    int jumpTwo = (idx + 2 < nums.size()) ? (abs(nums[idx] - nums[idx + 2]) + 
        helper(nums, cache, idx + 2)) : INT_MAX;

    cache[idx] = min(jumpOne, jumpTwo);

    return cache[idx];

}

int frogJump(int n, vector<int> &heights)
{
    if(heights.size() == 1) return heights[0];
    vector<int> cache(n, -1);
    return helper(heights,cache, 0);
}








// Approach 2: Tabulation. TC: O(N), SC: O(N)
int frogJump(int n, vector<int> &heights)
{
    if(heights.size() == 1) return heights[0];
    vector<int> cache(n, -1);
    cache[0] = 0;
    for (int i = 1; i < n; i++) {
        int jumpOne = abs(heights[i] - heights[i - 1]) + cache[i - 1];
        int jumpTwo = INT_MAX;
        if (i > 1) {
            jumpTwo = abs(heights[i] - heights[i - 2]) + cache[i - 2];
        }
        cache[i] = min(jumpOne, jumpTwo);
    }
    return cache[n - 1];
}









//Approach 3: Tabulation with space optimized. TC: O(N), SC: O(1)
int frogJump(int n, vector<int> &heights)
{
    int cacheOne = 0, cacheTwo = 0;
    for (int i = 1; i < n; i++) {
        int jumpOne = abs(heights[i] - heights[i - 1]) + cacheOne;
        int jumpTwo = INT_MAX;
        if (i > 1) {
            jumpTwo = abs(heights[i] - heights[i - 2]) + cacheTwo;
        }
        cacheTwo = cacheOne;
        cacheOne = min(jumpOne, jumpTwo);
    }
    return cacheOne;
}


