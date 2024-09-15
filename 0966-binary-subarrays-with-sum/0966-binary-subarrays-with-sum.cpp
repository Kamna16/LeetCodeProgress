class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        int cnt =0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            int Find = sum-goal;
            if(mp.find(Find) != mp.end())
            {
                cnt += mp[Find];
            }
            mp[sum]++;
        }
        return cnt;
    }
};