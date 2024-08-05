class Solution {
public:
    int dp[2501][2501];
    int LIS(vector<int>& nums, int i,int prev)
    {
        if(i >= nums.size()) return 0;
        if(prev != -1 && dp[i][prev] != -1) return dp[i][prev];
        int take=0, skip=0;
        if(prev == -1 || nums[i] > nums[prev])
        {
            take =  1 + LIS(nums,i+1,i);
        }
        skip = LIS(nums,i+1,prev);

        if(prev != -1)
        {
            dp[i][prev] = max(take,skip);
        }
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return LIS(nums,0,-1);
    }
};