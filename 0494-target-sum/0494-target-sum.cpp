class Solution {
public:
    
    int solve(int idx, vector<int>& nums,int sum, int target)
    {
        if(idx >= nums.size())
        {
            if(sum == target) return 1;
            return 0;
        }

        int opt1 = solve(idx+1,nums,sum+nums[idx],target);
        int opt2 = solve(idx+1,nums,sum-nums[idx],target);

        return opt1+opt2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
    
        return solve(0,nums,0,target);;
    }
};