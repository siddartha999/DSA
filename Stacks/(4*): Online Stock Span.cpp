/**
* Link: https://leetcode.com/problems/online-stock-span/description/
*/

class StockSpanner {
public:
    stack<pair<int, int>> stack;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int total = 1;
        while(!stack.empty() && stack.top().first <= price) {
            total += stack.top().second;
            stack.pop();
        }
        stack.push({price, total});
        return total;
    }
};

// TC: O(N), SC: O(N) in the worst case, O(1) on an average
