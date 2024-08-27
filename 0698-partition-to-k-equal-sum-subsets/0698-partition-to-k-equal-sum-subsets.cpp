class Solution {
public:
    bool backtrack(vector<int>& nums,vector<int> &subsets, int idx, int target)
    {
        if(idx == nums.size())
        {
            for(int n : subsets)
            {
                if(n != target) return false;
            }
            return true;
        }
        int num = nums[idx];
        for(int i=0;i<subsets.size();i++)
        {
            if(subsets[i]+num > target) continue;
            subsets[i] += num;
            if(backtrack(nums,subsets,idx+1,target)) return true;
            subsets[i] -= num;
            if (subsets[i] == 0) break;

        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());
        int sum = accumulate(nums.begin(),nums.end(),0);
        if((sum%k) != 0) return false;
        int target = sum/k;
        sort(nums.rbegin(), nums.rend());
        vector<int> subsets(k,0);
        return backtrack(nums,subsets,0,target); 
    }
};