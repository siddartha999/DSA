/**
* Problem link: https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
* Ref: https://www.youtube.com/watch?v=_BvEJ3VIDWw&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=42
**/

//TC: O(10^5), SC: O(10^5)
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(end >= 100000) return -1;
        if(start == end) return 0;
        int count = 1;
        queue<int> bfs;
        vector<bool> cache(100000, false);
        bfs.push(start);
        while(bfs.size() > 0) {
            int size = bfs.size();
            while(size--) {
                int val = bfs.front();
                bfs.pop();
                for(int a: arr) {
                    if(a == 1) continue;
                    int newVal = (val * a) % 100000;
                    if(newVal == end) return count;
                    if(cache[newVal] == true) continue;
                    cache[newVal] = true;
                    bfs.push(newVal);
                }
            }
            count++;
        }
        return -1;
    }
};
