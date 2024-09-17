class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int target,vector<int> & curr, int idx)
    {
        if(target == 0)
        {
            if(find(ans.begin(), ans.end(), curr) != ans.end()) return;
            ans.push_back(curr);
            return;
        }

        for(int i=idx;i<nums.size();i++)
        {
            if(i > idx && nums[i] == nums[i-1]) continue;
            if(nums[i]>target) break;
            curr.push_back(nums[i]);
            solve(nums,target-nums[i],curr,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,curr,0);
        return ans;
    }
};