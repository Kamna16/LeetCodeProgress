#include<bits/stdc++.h>
using namespace std;
// since there are overlapping sub problems we will use dp

// recursion + memoization
class Solution {
public:
    bool solve(vector<int>& nums,int i,vector<int> &dp)
    {
        if(i==nums.size()-1) return true;
        if(dp[i] != -1) return dp[i];
        for(int j=1;j<=nums[i];j++)
        {
            if(solve(nums,i+j,dp))
                return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> dp(n,-1);
        return solve(nums,0,dp);
    }
};

//bottom up
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j] == 1 && j+nums[j] >= i)
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};