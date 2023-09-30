/**
* Problem Link: https://www.codingninjas.com/studio/problems/stocks-are-profitable_893405?
**/

// Approach 1: With a stack. TC: O(N), SC: O(N)
int maximumProfit(vector<int> &prices){
    int maxVal = 0;
    stack<int> stack;
    for(int price: prices) {
        if(stack.size() == 0 || price < stack.top()) {
            stack.push(price);
        }
        else {
            maxVal = max(maxVal, price - stack.top());
        }
    }
    return maxVal;
}





// Approach 2: Optimized. TC: O(N), SC: O(1)
int maximumProfit(vector<int> &prices){
    int maxVal = 0;
    int minVal = prices[0];
    for(int idx = 1; idx < prices.size(); idx++) {
        int price = prices[idx];
        if(price < minVal) {
            minVal = price;
        }
        else {
            maxVal = max(maxVal, price - minVal);
        }
    }
    return maxVal;
}
