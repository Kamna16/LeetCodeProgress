class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int target,vector<int> & curr, int idx)
    {
        if(idx == nums.size()) return;
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }

        if(nums[idx] <= target)
        {
            curr.push_back(nums[idx]);
            solve(nums,target-nums[idx],curr,idx);
            curr.pop_back();
            solve(nums,target,curr,idx+1);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,curr,0);
        return ans;
    }
};