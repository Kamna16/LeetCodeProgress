class Solution {
public:
    vector<vector<int>> dp;
    bool solve(vector<int>& nums, int idx, int target)
    {
        if (target == 0) return true;
        if (idx == nums.size() || target < 0) return false;
        
        if (dp[idx][target] != -1) return dp[idx][target];
        int take = solve(nums,idx+1,target-nums[idx]);
        int not_take = solve(nums,idx+1,target);

        return dp[idx][target] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 == 1) return false;
        int t = sum/2;
        dp.resize(nums.size(), vector<int>(t + 1, -1));
        return solve(nums,0,t);
    }
};