class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,int>> pq;
        int maxValue = INT_MIN;
        for(auto &pt : points){
            int x_j = pt[0];
            int y_j = pt[1];

            while(!pq.empty() && x_j - pq.top().second > k){
                pq.pop();
            }
            if (!pq.empty()) {
                maxValue = max(maxValue, y_j + x_j + pq.top().first);
            }
            pq.emplace(y_j - x_j, x_j);
        }
        return maxValue;
    }
};