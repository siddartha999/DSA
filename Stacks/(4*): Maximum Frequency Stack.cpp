/**
  * Link: https://leetcode.com/problems/maximum-frequency-stack/description/
*/

class FreqStack {
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> levels;
    int maxFreq = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        levels[freq[val]].push(val);
        maxFreq = max(maxFreq, freq[val]);
    }
    
    int pop() {
        int val = levels[maxFreq].top();
        levels[maxFreq].pop();
        freq[val]--;
        if(levels[maxFreq].empty()) maxFreq--;
        return val;
    }
};
