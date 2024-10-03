class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(),nums.end(),0LL);
        int rem = sum%p;
        if(rem == 0) return 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        int ans = n;
        long long prefix_sum = 0;
        long long curr_mod;
        int target_mod;
        for(int i=0;i<n;i++)
        {
            prefix_sum += nums[i];
            curr_mod = prefix_sum % p;
            target_mod = (curr_mod - rem + p)%p;
            if(mp.find(target_mod) != mp.end())
            {
                ans = min(ans,i-mp[target_mod]);
            }
            mp[curr_mod] = i;
            
        }
        if(ans == n) return -1;
        return ans;
    }
};