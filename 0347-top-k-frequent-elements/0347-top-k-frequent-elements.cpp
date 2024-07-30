class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto x : mp)
        {
            pq.push({x.second,x.first});
            while(pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while(!pq.empty())
        {
            int num = pq.top().second;
            ans.push_back(num);
            pq.pop();
        }
        return ans;
    }
};