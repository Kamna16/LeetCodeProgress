class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>, greater<int>> pq;
        for(auto p : intervals)
        {
            int start = p[0];
            int end = p[1];
            if(!pq.empty() && start > pq.top()){
                pq.pop();
                pq.push(end);
            }else{
                pq.push(end);
            }
        }
        return pq.size();
    }
};