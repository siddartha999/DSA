/**
* Problem Link: https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1
**/



// Approach 1: Brute Force. TC: O(N * K), SC: O(N)
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int K){
        vector<int> count(stations.size() - 1, 0);
        double res = 0;
        
        while(K--) {
            int maxIdx = 0;
            double maxDistance = 0;
            for(int idx = 1; idx < stations.size(); idx++) {
                int localStations = count[idx - 1] + 2;
                double localDistance = ((double)(stations[idx] - stations[idx - 1]) / localStations);
                if(localDistance > maxDistance) {
                    maxDistance = localDistance;
                    res = maxDistance;
                    maxIdx = idx - 1;
                }
            }
            count[maxIdx]++;
        }
        
        return res;
    }
};






// Approach 2: Priority Queue. TC: (NlogN) + O(K * logN), SC: O(N)
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int K){
        vector<int> count(stations.size() - 1, 0);
        priority_queue<pair<double, int>> pq;
        for(int idx = 1; idx < stations.size(); idx++) {
            pq.push({(double)stations[idx] - stations[idx - 1], idx - 1});
        }
        
        while(K--) {
            pair<double, int> top = pq.top();
            pq.pop();
            int idx = top.second;
            count[idx] += 1;
            int localStations = count[idx] + 1;
            double actualDistance = stations[idx + 1] - stations[idx];
            double maxSectorDistance = ((double)actualDistance / localStations);
            pq.push({maxSectorDistance, idx});
        }
        
        return pq.top().first;
    }
};
