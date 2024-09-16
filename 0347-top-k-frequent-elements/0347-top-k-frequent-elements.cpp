class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> freq(n+1);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto p : mp)
        {
            freq[p.second].push_back(p.first);
        }
        vector<int> ans;
        for(int i=n;i>=0;i--)
        {
            while(freq[i].size() > 0 && k >0)
            {
                ans.push_back(freq[i].back());
                freq[i].pop_back();
                k--;
            }
            if(k <=0) break;
        }
        return ans;
    }
};