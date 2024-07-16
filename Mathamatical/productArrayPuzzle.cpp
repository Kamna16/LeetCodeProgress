#include<bits/stdc++.h>
using namespace std;

// Approach2 - gfg
class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        long long int product = 1;
        int zeroCount = 0;

        for(int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                product *= nums[i];
            } else {
                zeroCount++;
            }
        }

        vector<long long int> ans(n, 0); 

        if (zeroCount > 1) {
            return ans; 
        }

        for(int i = 0; i < n; i++) {
            if (zeroCount == 0) {
                ans[i] = product / nums[i];
            } else if (zeroCount == 1 && nums[i] == 0) {
                ans[i] = product;
            }
        }

        return ans;
    }
};

// Approach2 - leetcode
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int totalProduct = 1;
        int suffix[n];        
        int prefix[n];        
        prefix[0] =1;
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1]* nums[i-1];
        }
        suffix[n-1] =1;
        for(int i=n-2;i>=0;i--)
        {
            suffix[i] = suffix[i+1]* nums[i+1];
        }
        for(int i=0;i<n;i++)
        {
            ans[i] = prefix[i]*suffix[i];
        }

        return ans;

    }
};
